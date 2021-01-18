#include "inc/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    qRegisterMetaType<QVector<qint16>>();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
