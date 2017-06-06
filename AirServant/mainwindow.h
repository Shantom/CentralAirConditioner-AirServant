#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <login.h>
#include "headers.h"
#include "servant.h"
#include "requestcontroller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool login();

private:
    Ui::MainWindow *ui;
    Servant servant;
    int upperBound=30;
    int lowerBound=17;
public slots:
    void refreshInfo();
private slots:
    void on_pushButton_up_clicked();
    void on_pushButton_down_clicked();

    void on_pushButton_high_clicked();

    void on_pushButton_medium_clicked();

    void on_pushButton_low_clicked();

    void on_pushButton_stop_clicked();

signals:
};

#endif // MAINWINDOW_H
