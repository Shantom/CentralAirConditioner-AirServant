#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    std::string addr="10.201.11.213";
    int port=6666;
    std::ifstream file("../serverAddr.dat");
    if(file)
        file>>addr>>port;
    else
    {
        qDebug()<<"file failed";
    }
    Communication::connectToMaster(QHostAddress(QString::fromStdString(addr)),port);
    servant.sendBeat();
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
