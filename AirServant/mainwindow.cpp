#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    servant.setWin(this);
    RefreshUIController::theCtrler=new RefreshUIController();
    RefreshUIController::connect(RefreshUIController::theCtrler,
                                &RefreshUIController::refresh,
                                this,
                                &MainWindow::refreshInfo);

    std::string addr="10.201.11.213";
    int port=6666;
    std::ifstream file("../serverAddr.dat");
    if(file)
        file>>addr>>port;
    else
    {
        qDebug()<<"cannot open file.";
    }
    bool result=
            Communication::connectToMaster(QHostAddress(QString::fromStdString(addr)),port);
    if(!result)
    {
        QMessageBox::critical(this,"error","can't connect to the master!");
        exit(404);
    }
    servant.startBeat();
}
MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::login()
{
    Login lg;
    if(lg.exec()==QDialog::Accepted)
    {
        show();
        return true;
    }
    else
        return false;
}

void MainWindow::refreshInfo()
{
    ui->label_bill->setText(QString("%1").arg(servant.getBill()));
    ui->label_consumption->setText(QString("%1").arg(servant.getKwh()));
    ui->label_mode->setText(QString::fromStdString(servant.getMode()));
}
