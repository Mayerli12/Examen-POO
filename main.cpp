#include "calificaciones.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator T;
    QStringList langs;
    langs << "Español" << "Portuges";
    const QString lang = QInputDialog ::getItem(NULL,
                                                "Language",
                                                "Select Language",
                                                langs);
    if (lang=="Portugues"){
        T.load(":/portugues.qm");
    }
    if (lang != "Español"){
        a.installTranslator(&T);
    }
    a.setStyleSheet("fusion");
    Calificaciones w;
    w.show();
    return a.exec();
}
