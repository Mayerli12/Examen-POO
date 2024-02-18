#include "estudiante.h"

Estudiante::Estudiante() {}

Estudiante::Estudiante(const QString &nombre, float nota1, float nota2)
    : m_nombre(nombre), m_nota1(nota1), m_nota2(nota2)
{}

QString Estudiante::nombre() const
{
    return m_nombre;
}

QString Estudiante::estado() const
{
    float notaFinal = (m_nota1 + m_nota2) / 2;
    if (notaFinal >= 70)
        return "Aprobado";
    else if (notaFinal >= 25)
        return "Remedial";
    else
        return "Reprobado";
}

QString Estudiante::toString() const
{
    return m_nombre + " " + estado() + " " + QString::number(m_nota1) + " " + QString::number(m_nota2);
}
