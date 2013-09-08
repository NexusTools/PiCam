#include <QApplication>
#include "picam.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PiCam w;
    w.show();
    
    return a.exec();
}
