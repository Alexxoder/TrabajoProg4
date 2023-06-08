#include "../include/date.h"

//creates
date::date()
{
    dia = 0;
    mes = 0;
    anio = 0;
    hora = 0;
}

date::date(int dd, int mm,int aaaa, int hh)
{
    dia = dd;
    mes = mm;
    anio = aaaa;
    hora = hh;
}

//setters
void date::setDia(int dia)
{
    this->dia = dia;
}

void date::setMes(int mes)
{
    this->mes = mes;
}

void date::setAnio(int anio)
{
    this->anio = anio;
}

void date::setHora(int hora)
{
    this->hora = hora;
}

//getters
int date::getDia()
{
    return dia;
}

int date::getMes()
{
    return mes;
}

int date::getAnio()
{
    return anio;
}

int date::getHora()
{
    return hora;
}

// sobrecargar 
int date::operator-(const date &f)
{
    int innumero = f.dia + (f.mes - 1) * 31 + (f.anio) * 12 * 31;
    int outnumero = this->dia + (this->mes - 1) * 31 + (this->anio) * 12 * 31;

    return (outnumero - innumero);
}

bool date::operator==(const date &f)
{
    return (anio == f.anio) && (mes == f.mes) && (dia == f.dia) && (hora = f.hora);
}

date &date::operator=(const date &f)
{
    this->dia = f.dia;
    this->mes = f.mes;
    this->anio = f.anio;
    this->hora = f.hora;
    return *this;
}

bool date::operator<(const date &f)
{
    if (this->anio != f.anio)
        return this->anio < f.anio;
    else if (this->mes != f.mes)
        return this->mes < f.mes;
    else if (this->dia != f.dia)
        return this->dia < f.dia;
    else if (this->hora != f.hora)
        return this->hora < f.hora;
    else return false;
}

ostream &operator<<(ostream &o, date &d)
{   

    o << "Fecha: " << d.getDia() << "/" << d.getMes() << "/" << d.getAnio() << "-";
    int hora = d.getHora();
    if (hora > 12 )
        {
            hora = hora - 12;
            o << hora << "PM" << endl;
        }
    else o << hora << "AM" << endl;
    return o;
}

bool date::esVacia()
{
    return (this->anio == 0);
}