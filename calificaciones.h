#ifndef CALIFICACIONES_H
#define CALIFICACIONES_H

#include <QMainWindow>
#include <QFile>
#include <QDir>
#include <QFileDialog>

#include <estudianteform.h>
#include "estudiante.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class Calificaciones;
}
QT_END_NAMESPACE

class Calificaciones : public QMainWindow
{
    Q_OBJECT

public:
    Calificaciones(QWidget *parent = nullptr);
    ~Calificaciones();

    void guardarDatos();
    void cargarDatos();

private slots:
    void on_actionNuevo_triggered();

    void on_actionSalir_triggered();

    void procesarDatosEstudiante(const QString &nombre, float nota1, float nota2);


    void on_actionGuardar_Datos_triggered();



    void on_actionCargar_Datos_triggered();

private:
    Ui::Calificaciones *ui;
    QList<Estudiante*> m_estudiantes;

};
#endif //CALIFICACIONES_H
