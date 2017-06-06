#ifndef REQUESTCONTROLLER_H
#define REQUESTCONTROLLER_H

#include <QObject>
#include "headers.h"
#include "QTimer"

class RequestController : public QObject
{
    Q_OBJECT
public:
    explicit RequestController(QObject *parent = 0);
    static void initial(Servant *serv);
    static bool request(int goal, std::string velocity="");

private:

    static QTimer oneSecond;
    static Servant *servant;
    static int goal;
    static std::string velocity;

signals:

public slots:
    static void sendRequest();

};

#endif // REQUESTCONTROLLER_H
