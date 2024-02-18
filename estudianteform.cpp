#include "estudianteform.h"
#include "ui_estudianteform.h"

EstudianteForm::EstudianteForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EstudianteForm)
{
    ui->setupUi(this);
}

EstudianteForm::~EstudianteForm()
{
    delete ui;
}

void EstudianteForm::on_buttonBox_accepted()
{
    QString nombre = ui->txtNombre->text();
    float nota1 = ui->spnNota1->value();
    float nota2 = ui->spnNota2->value();

    m_estudiante.append(new Estudiante(nombre, nota1, nota2));

    emit datosEstudianteIngresados(nombre, nota1, nota2);

    if (nombre.isEmpty()){
        QMessageBox::warning(this, "Nombre", "El nombre no pueden estar vacío");
        ui->txtNombre->setFocus();
        return;
    }
    close();

}



void EstudianteForm::on_buttonBox_rejected()
{
    this->close();
}

