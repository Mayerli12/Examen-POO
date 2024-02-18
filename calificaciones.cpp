#include "calificaciones.h"
#include "ui_calificaciones.h"

Calificaciones::Calificaciones(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calificaciones)
{
    ui->setupUi(this);
    ui->tblCalificaciones->setColumnCount(6);
    ui->tblCalificaciones->setHorizontalHeaderLabels({"Nombre" , "Nota 1" , "Nota 2" , "Nota Final" , "Estado" , "Nmin Remedial"});
    // Inicializar la lista de estudiantes
    m_estudiantes = QList<Estudiante*>();
}

Calificaciones::~Calificaciones()
{
    delete ui;
}



void Calificaciones::on_actionNuevo_triggered()
{
    EstudianteForm *w = new EstudianteForm(this);
    connect(w, &EstudianteForm::datosEstudianteIngresados, this, &Calificaciones::procesarDatosEstudiante);
    w->show();
}


void Calificaciones::on_actionSalir_triggered()
{
    this->close();
}

void Calificaciones::procesarDatosEstudiante(const QString &nombre)
{
    Estudiante *nuevoEstudiante = new Estudiante(nombre, 0, 0); // Aquí deberías pasar las notas adecuadas

    // Agregar el nuevo estudiante a la lista de estudiantes
    m_estudiantes.append(nuevoEstudiante);
}

