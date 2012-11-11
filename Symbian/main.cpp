#include <QtGui/QApplication>
#include <QObject>
#include <QDeclarativeItem>
#include "qmlapplicationviewer.h"
#include "mainwindow.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    MainWindow	window;

    QmlApplicationViewer viewer;
    viewer.setMainQmlFile(QLatin1String("qml/netsoul/main.qml"));

    QObject *rootObject = dynamic_cast<QObject*>(viewer.rootObject());
    // met l'objet qml bouton dans window
    window.button = viewer.rootObject()->findChild<QObject *>("buttonConnect");

    // signal du bouton
    QObject::connect(window.button, SIGNAL(qmlSignal(QString, QString)), &window, SLOT(connection(QString, QString)));
    // signal d'affichage du dialogue
    QObject::connect(&window, SIGNAL(dialog(QVariant)), window.button, SLOT(showDialog(QVariant)));

    viewer.showExpanded();
    return app->exec();
}
