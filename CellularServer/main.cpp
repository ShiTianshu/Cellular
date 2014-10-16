#include <QApplication>

#include "cellularserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CellularServer s;
    s.initialize();
    s.start();
    return a.exec();
}
