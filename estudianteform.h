#ifndef ESTUDIANTEFORM_H
#define ESTUDIANTEFORM_H

#include <QWidget>
#include <QList>
#include <QMessageBox>


#include <estudiante.h>

namespace Ui {
class EstudianteForm;
}

class EstudianteForm : public QWidget
{
    Q_OBJECT

public:
    explicit EstudianteForm(QWidget *parent = nullptr);
    ~EstudianteForm();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

signals:
    void datosEstudianteIngresados(const QString &nombre, float nota1, float nota2);

private:
    Ui::EstudianteForm *ui;
    QList<Estudiante*> m_estudiante;

};
#endif // ESTUDIANTEFORM_H
