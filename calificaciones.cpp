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

    //connect(ui->actionGuardar_Datos, &QAction::triggered, this, &Calificaciones::guardarDatos);
    cargarDatos();

}

Calificaciones::~Calificaciones()
{
    delete ui;
}

void Calificaciones::guardarDatos()
{
    // Abrir un cuadro de diálogo para que el usuario seleccione la ubicación y el nombre del archivo
    QString rutaArchivo = QFileDialog::getSaveFileName(this, tr("Guardar como"), "", tr("Archivos CSV (*.csv)"));

    if (!rutaArchivo.isEmpty()) {
        QFile archivo(rutaArchivo);
        if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream salida(&archivo);
            // Escribir los encabezados
            salida << tr("Nombre,Nota 1,Nota 2,Nota Final,Estado,Nmin Remedial\n");
            // Escribir los datos

            for (Estudiante *estudiante : m_estudiantes) {
                salida << estudiante->nombre() << "," << estudiante->getNota1() << "," << estudiante->getNota2() << ","
                    << estudiante->notaF() << "," << estudiante->estado() << "," << estudiante->notaR() << "\n";
            }
            archivo.close();
            QMessageBox::information(this, tr("Guardado"), tr("Los datos se han guardado correctamente."));
        } else {
            QMessageBox::critical(this, tr("Error"), tr("No se pudo abrir el archivo para escribir."));
        }
    }
}

void Calificaciones::cargarDatos()
{
    QString rutaArchivo = QFileDialog::getOpenFileName(this, tr("Cargar Datos"), QDir::homePath(), tr("Notas(*.csv)"));

    if (!rutaArchivo.isEmpty()) {
        QFile archivo(rutaArchivo);

        if (archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream entrada(&archivo);
            entrada.readLine(); // Leer y descartar la primera línea (encabezados)

            while (!entrada.atEnd()) {
                QString linea = entrada.readLine();
                QStringList datos = linea.split(",");
                if (datos.size() == 6) {
                    QString nombre = datos[0];
                    float nota1 = datos[1].toFloat();
                    float nota2 = datos[2].toFloat();
                    float notaFinal = datos[3].toFloat();
                    QString estado = datos[4];
                    float notaRemedial = datos[5].toFloat();
                    procesarDatosEstudiante(nombre, nota1, nota2);
                }
            }
            archivo.close();
        }
    }
    else
    {
        QMessageBox::warning(this, tr("Cargar Datos"), tr("No se pudo abrir el archivo"));
    }
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
    // Verificar si el estudiante esta reprobado
    if (nuevoEstudiante->notaF() < 70) {
        ui->tblCalificaciones->setItem(fila, 5, new QTableWidgetItem(QString::number(nuevoEstudiante->notaR())));
    } else {
        ui->tblCalificaciones->setItem(fila, 5, new QTableWidgetItem("0"));
    }

}


void Calificaciones::on_actionGuardar_Datos_triggered()
{
    guardarDatos();
}





void Calificaciones::on_actionCargar_Datos_triggered()
{
    cargarDatos();
}


void Calificaciones::on_actionCreditos_triggered()
{
    CreditosForm *w = new CreditosForm();
     w->show();
}

