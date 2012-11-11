#ifndef NETSOUL_H
#define NETSOUL_H

#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <QHostInfo>
#include <QHostAddress>

class		Netsoul: public QObject
{
Q_OBJECT
public:
  Netsoul(QObject* parent = 0);
  ~Netsoul();
  int		connect(const QString &login, const QString &password);
  void		disconnect();
  bool      isRunning() const;
private:
  void		parseConnect(const QString & str);

  QTcpSocket	*socket;

  QString	num_socket;
  QString	md5;
  QString	host_client;
  QString	port_client;
  QString      	timestamp;

  bool      run;
};

#endif // NETSOUL_H
