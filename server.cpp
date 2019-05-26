#include "server.h"

server::server()
{

}

server::~server()
{

}

void server::startServer()
{

    if (this->listen(QHostAddress::Any,1234))
    {
        qDebug() << "Listenning";
    }
    else
    {
        qDebug()<<"Not listening";
    }
}

void server::incomingConnection(int socketDescriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

        connect(socket,SIGNAL(readyRead()),this,SLOT(sockReady()));
        connect(socket,SIGNAL(disconnected()),this,SLOT(sockDisc()));

    qDebug()<<socketDescriptor<<" Client connected";


    socket->write("{\"type\":\"connect\",\"status\":\"yes\"}");
    qDebug()<<"Send client connect status - YES";
}

void server::sockReady()
{
    Data = socket->readAll();
    qDebug()<<"Data: " << Data;

    doc = QJsonDocument::fromJson(Data,&docError);

    //{"type":"select","params":"workers"}
    if(docError.errorString()=="no error occurred"){
        if((doc.object().value("type").toString()=="select") &&
                (doc.object().value("params").toString() == "workers")){


//            QFile file;
//            file.setFileName("C:\\Users\\Mic-PC\\Documents\\QT projects\\files\\workers.json");
//            if(file.open(QIODevice::ReadOnly|QFile::Text)){
//                QByteArray fromFile = file.readAll();
//                //{"type":"resultSelect","result":..}
//                QByteArray itog = "{\"type\":\"resultSelect\",\"result\":" +fromFile+"}";
//                socket->write(itog);
//                socket->waitForBytesWritten(500);
//            }
//            file.close();

                //{"type":"resultSelect","result":..}




        }
    }
}

void server::sockDisc()
{
    qDebug()<<"Disconnect";
    socket->deleteLater();
}
