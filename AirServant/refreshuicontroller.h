#ifndef REFRESHUICONTROLLER_H
#define REFRESHUICONTROLLER_H

#include <QObject>

class RefreshUIController : public QObject
{
    Q_OBJECT
public:
    explicit RefreshUIController(QObject *parent = 0);
    static RefreshUIController *theCtrler;
signals:
    void refresh();

public slots:
};

#endif // REFRESHUICONTROLLER_H
