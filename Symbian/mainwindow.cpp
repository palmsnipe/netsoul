#include "mainwindow.h"

MainWindow::MainWindow() : QObject()
{
  netsoul = new Netsoul();
}

MainWindow::~MainWindow()
{
  if (netsoul->isRunning() == true)
    netsoul->disconnect();

    delete netsoul;
}

void		MainWindow::connection(const QString &login, const QString &password)
{
  if (netsoul->isRunning() == false)
    {
      int msg = netsoul->connect(login, password);
      if (netsoul->isRunning() == true)
      {
          qDebug() << "Deconnexion";
          this->button->setProperty("text", "D\351connexion");
          emit dialog(QVariant(msg));
      }
      else
      {
          emit dialog(QVariant(msg));
      }
    }
  else
    {
      qDebug() << "Disconnect";
      netsoul->disconnect();
      this->button->setProperty("text", "Connexion");
    }
}
