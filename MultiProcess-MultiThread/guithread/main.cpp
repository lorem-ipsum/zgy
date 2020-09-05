//main.cpp
#include <QtGui>
#include "tqt.h"

int main(int argc,char **argv)
{
    QApplication app(argc, argv);
    Widget *widget = new Widget;
    widget->show();
    return app.exec();
}
