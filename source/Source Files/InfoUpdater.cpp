#include "InfoUpdater.h"

InfoUpdater::InfoUpdater(QString threadName, MainWindow* window) : name(threadName)
{
    w = window;
}

void InfoUpdater :: run() {
    while(1) {
        w -> updateSystemInformation();
    }
}
