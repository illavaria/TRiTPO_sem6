#include "mainwindow.h"
#include "InfoUpdater.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    InfoUpdater* infoUpdater = new InfoUpdater("InfoUpdater", &w);
    infoUpdater -> start();
    return a.exec();
}
