#ifndef CALIFICACIONES_H
#define CALIFICACIONES_H

#include <QMainWindow>
#include <estudianteform.h>

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

private slots:
    void on_actionNuevo_triggered();

    void on_actionSalir_triggered();

    void procesarDatosEstudiante(const QString &nombre);


private:
    Ui::Calificaciones *ui;
    QList<Estudiante*> m_estudiantes;

};
#endif //CALIFICACIONES_H
