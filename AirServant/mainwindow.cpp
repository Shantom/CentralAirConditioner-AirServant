#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Servant");
    servant.setWin(this);
    RequestController::initial(&servant);
    RefreshUIController::theCtrler=new RefreshUIController();
    RefreshUIController::connect(RefreshUIController::theCtrler,
                                &RefreshUIController::refresh,
                                this,
                                &MainWindow::refreshInfo);
    ui->pushButton_stop->setEnabled(false);
    ui->pushButton_up->setEnabled(false);
    ui->pushButton_down->setEnabled(false);
    ui->label_warning->setStyleSheet("color:red");

    std::string addr="127.0.0.1";
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
    connect(&Communication::socket,&QAbstractSocket::disconnected,
            this,&MainWindow::on_close);
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
    ui->label_temp->setText(QString("%1").arg(servant.getTemp()));
    ui->label_matemp->setText(QString("%1").arg(servant.getMaTemp()));

    std::string preMode=ui->label_mode->text().toStdString();
    std::string curMode=servant.getMode();
    if(curMode!=preMode)//change mode
    {
        ui->label_mode->setText(QString::fromStdString(servant.getMode()));
        on_pushButton_stop_clicked();
        if(curMode=="COLD")
        {
            ui->lcdNumber->display(26);
            upperBound=30;
            lowerBound=17;
        }
        else
        {
            ui->lcdNumber->display(20);
            upperBound=26;
            lowerBound=13;
        }
    }

}

void MainWindow::on_pushButton_up_clicked()
{
    int goal=ui->lcdNumber->value();
    goal++;
    ui->lcdNumber->display(goal);
    if(goal==upperBound)
        ui->pushButton_up->setEnabled(false);
    else
        ui->pushButton_up->setEnabled(true);

    bool result=RequestController::request(goal);
    if(!result)
    {
        ui->lcdNumber->display(--goal);
        ui->label_warning->setText("WARNING:conflict with master.");
    }
    else
    {
        servant.setGoal(goal);
        servant.setActive(true);
    }

}

void MainWindow::on_pushButton_down_clicked()
{
    int goal=ui->lcdNumber->value();
    goal--;
    ui->lcdNumber->display(goal);

    if(goal==lowerBound)
        ui->pushButton_down->setEnabled(false);
    else
        ui->pushButton_down->setEnabled(true);

    bool result=RequestController::request(goal);
    if(!result)
    {
        ui->lcdNumber->display(++goal);
        ui->label_warning->setText("WARNING:conflict with master.");
    }
    else
    {
        servant.setGoal(goal);
        servant.setActive(true);
    }

}

void MainWindow::on_pushButton_high_clicked()
{
    ui->pushButton_up->setEnabled(true);
    ui->pushButton_down->setEnabled(true);
    ui->pushButton_high->setEnabled(false);
    ui->pushButton_medium->setEnabled(true);
    ui->pushButton_low->setEnabled(true);
    ui->pushButton_stop->setEnabled(true);
    int goal=ui->lcdNumber->value();
    std::string velocity="HIGH";
    RequestController::request(goal,velocity);
    servant.setActive(true);
}

void MainWindow::on_pushButton_medium_clicked()
{
    ui->pushButton_up->setEnabled(true);
    ui->pushButton_down->setEnabled(true);
    ui->pushButton_high->setEnabled(true);
    ui->pushButton_medium->setEnabled(false);
    ui->pushButton_low->setEnabled(true);
    ui->pushButton_stop->setEnabled(true);
    int goal=ui->lcdNumber->value();
    std::string velocity="MEDIUM";
    RequestController::request(goal,velocity);
    servant.setActive(true);
}

void MainWindow::on_pushButton_low_clicked()
{
    ui->pushButton_up->setEnabled(true);
    ui->pushButton_down->setEnabled(true);
    ui->pushButton_high->setEnabled(true);
    ui->pushButton_medium->setEnabled(true);
    ui->pushButton_low->setEnabled(false);
    ui->pushButton_stop->setEnabled(true);
    int goal=ui->lcdNumber->value();
    std::string velocity="LOW";
    RequestController::request(goal,velocity);
    servant.setActive(true);
}

void MainWindow::on_pushButton_stop_clicked()
{
    ui->pushButton_up->setEnabled(false);
    ui->pushButton_down->setEnabled(false);
    ui->pushButton_high->setEnabled(true);
    ui->pushButton_medium->setEnabled(true);
    ui->pushButton_low->setEnabled(true);
    ui->pushButton_stop->setEnabled(false);
    std::string velocity="NONE";
    RequestController::request(0,velocity);
    servant.setActive(false);

}

void MainWindow::on_close()
{
    QMessageBox::critical(this,"Disconnected","Disconnected with master.");
    exit(405);
}
