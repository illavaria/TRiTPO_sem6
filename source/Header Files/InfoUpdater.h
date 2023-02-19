#ifndef INFOUPDATER_H
#define INFOUPDATER_H
#include <QThread>
#include "mainwindow.h"


class InfoUpdater : public QThread
{
public:
    explicit InfoUpdater(QString threadName, MainWindow* window);
    MainWindow* w;
private:
    QString name;
    void run();
};

#endif // INFOUPDATER_H
