#include <QtGui/QApplication>
#include "mainwindow.h"

//#include <dlfcn.h>
#include <QtCore/QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("FTNANRB");
    app.setApplicationName("SwiftNPU");
    MainWindow w;
    w.show();
    return app.exec();
}
