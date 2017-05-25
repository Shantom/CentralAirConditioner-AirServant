#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::string addr="127.0.0.1";
    int port=40000;
    std::ifstream file("serverAddr.txt");
    if(file)
        file>>addr>>port;
    Communication::connectToMaster(QHostAddress(addr),port);
    servant.sendbeat();
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
