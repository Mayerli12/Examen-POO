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

    if (notaF() >= 70)
        return "Aprobado";
    else if (notaF() >= 25)
        return "Remedial";
    else
        return "Reprobado";
}

QString Estudiante::toString() const
{
    return m_nombre + " " + estado() + " " + QString::number(m_nota1) + " " + QString::number(m_nota2);
}

float Estudiante::notaF() const
{
    return m_nota1 + m_nota2;
}

float Estudiante::notaR() const
{
    return (70.0 - 0.4 * notaF()) / 0.6;
}

float Estudiante::getNota1() const
{
    return m_nota1;
}

float Estudiante::getNota2() const
{
    return m_nota2;
}
