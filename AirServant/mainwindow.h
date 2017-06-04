#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <login.h>
#include "headers.h"
#include "servant.h"

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
public slots:
    void refreshInfo();
};

#endif // MAINWINDOW_H
