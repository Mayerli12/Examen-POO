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

void Calificaciones::procesarDatosEstudiante(const QString &nombre, float nota1, float nota2)
{
    Estudiante *nuevoEstudiante = new Estudiante(nombre, nota1, nota2);

    // Agregar el estudiante a la lista de estudiantes
    m_estudiantes.append(nuevoEstudiante);

    // Añadir una nueva fila a la tabla
    int fila = ui->tblCalificaciones->rowCount();
    ui->tblCalificaciones->insertRow(fila);

    // Insertar los datos del estudiante en las columnas correspondientes
    ui->tblCalificaciones->setItem(fila, 0, new QTableWidgetItem(nuevoEstudiante->nombre()));
    ui->tblCalificaciones->setItem(fila, 1, new QTableWidgetItem(QString::number(nuevoEstudiante->getNota1())));
    ui->tblCalificaciones->setItem(fila, 2, new QTableWidgetItem(QString::number(nuevoEstudiante->getNota2())));
    ui->tblCalificaciones->setItem(fila, 3, new QTableWidgetItem(QString::number(nuevoEstudiante->notaF())));
    ui->tblCalificaciones->setItem(fila, 4, new QTableWidgetItem(nuevoEstudiante->estado()));
    ui->tblCalificaciones->setItem(fila, 5, new QTableWidgetItem(QString::number(nuevoEstudiante->notaR())));

}

