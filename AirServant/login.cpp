#include "login.h"
#include "ui_login.h"



Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowTitle("Login");
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_login_clicked()
{
    QString roomid=ui->lineEdit_room->text();
    QString userid=ui->lineEdit_user->text();
    LoginController lc;
    if(lc.login(roomid.toStdString(),userid.toStdString()))
        accept();
    else
        QMessageBox::critical(this,"Failed","Lost connection with master.");
}
