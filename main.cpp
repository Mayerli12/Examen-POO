#include "calificaciones.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calificaciones w;
    w.show();
    return a.exec();
}
