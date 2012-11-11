#include <QObject>
#include <QTcpSocket>
#include <QStringList>
#include <QCryptographicHash>
#include <QByteArray>
#include <QDebug>
#include "netsoul.h"

Netsoul::Netsoul(QObject *parent) : QObject(parent)
{
  socket = new QTcpSocket(this);
  this->run = false;
}

Netsoul::~Netsoul()
{
  delete this->socket;
}

void    Netsoul::disconnect()
{
  qDebug() << "NETSOUL: Disconnect client.";
  this->socket->close();

  this->run = false;
}

int     Netsoul::connect(const QString &login, const QString &password)
{
  this->socket->connectToHost("ns-server.epita.fr", 4242);
  if (this->socket->waitForConnected(1000))
  {
    qDebug() << "NETSOUL: Liaison established";
      // connect
    this->socket->waitForReadyRead(1000);
    parseConnect(this->socket->readAll());
      // envoi demande d'authentification
    if (this->socket->write("auth_ag ext_user none none\n") == -1)
      qDebug() << "NETSOUL: Erreur write";
    this->socket->waitForBytesWritten(1000);
      // receive request
    this->socket->waitForReadyRead(1000);
    qDebug() << "Rep1 :" << this->socket->readAll();
      // make authentification
    QString test = QString(QCryptographicHash::hash(QByteArray(QString(this->md5 + "-" + this->host_client + "/" + this->port_client + password).toStdString().c_str()), QCryptographicHash::Md5).toHex());
      // send authentification
    if (this->socket->write(QString("ext_user_log " + login + " " + test + " palmsnipeNS nokiaQt\n").toStdString().c_str()) == -1)
      qDebug() << "Erreur write";
    this->socket->waitForBytesWritten(1000);
      // receive request
    this->socket->waitForReadyRead(1000);
    QString tmp = this->socket->readAll();

    if (tmp != "rep 002 -- cmd end\n")
    {
     if (tmp == "rep 033 -- ext user identification fail\n")
     {
       qDebug() << "NETSOUL: incorrect login or password";
     }
     else
     {
       qDebug() << "NETSOUL: unknown error";
     }
     disconnect();
     return (2);
   }
   else
   {
      // envoi utilisateur actif
    if (this->socket->write(QString("state actif:" + this->timestamp + "\n").toStdString().c_str()) == -1)
      qDebug() << "Erreur write";
    this->socket->waitForBytesWritten(1000);

    qDebug() << "NETSOUL: Logged !!";
    this->run = true;
    return (0);
  }
}
else
{
  qDebug() << "NETSOUL: unable to establish connection";
  return (1);
}
return (0);
}

void		Netsoul::parseConnect(const QString & str)
{
  int		i = 0;
  QStringList	list = str.split(" ");

  for (QStringList::iterator it = list.begin(); it != list.end(); ++it)
  {
    if (i == 1)
      this->num_socket = *it;
    else if (i == 2)
      this->md5 = *it;
    else if (i == 3)
      this->host_client = *it;
    else if (i == 4)
      this->port_client = *it;
    else if (i == 5)
      this->timestamp = QString(*it).remove('\n');
    ++i;
  }
}

bool      Netsoul::isRunning() const
{
  return this->run;
}
