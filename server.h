#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QFile>

class server : public QTcpServer
{

    Q_OBJECT
    QByteArray Data;
    QJsonDocument doc;
    QJsonParseError docError;
public:
    server();
    ~server();

    QTcpSocket* socket;
public slots:
    void startServer();
    void incomingConnection(int socketDescriptor);
    void sockReady();
    void sockDisc();
};



#endif // SERVER_H
