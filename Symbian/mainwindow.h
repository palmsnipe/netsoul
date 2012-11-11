#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include "netsoul.h"

class		MainWindow : public QObject
{
Q_OBJECT
public:
  MainWindow();
  ~MainWindow();
  QObject *button;
public slots:
  void		connection(const QString &login, const QString &password);
signals:
  void dialog(QVariant id);
private:
  Netsoul	*netsoul;

};

#endif // MAINWINDOW_H
