#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <QString>

class Estudiante
{
public:
    Estudiante();
    Estudiante(const QString &nombre, float nota1, float nota2);
    QString nombre() const;
    QString estado() const;
    QString toString() const;

private:
    QString m_nombre;
    float m_nota1;
    float m_nota2;
};

#endif // ESTUDIANTE_H
