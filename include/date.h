#ifndef _DATE_H
#define _DATE_H

#include <iostream>
using namespace std;

class date
{
private:
    int dia;
    int mes;
    int anio;
    int hora;

public:
    //creates
    date();
    date(int, int, int, int);
    
    //setters
    void setDia(int);
    void setMes(int);
    void setAnio(int);
    void setHora(int);
    
    //getters
    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    
    //sobrecargas
    int operator-(const date &);
    bool operator==(const date &);
    date &operator=(const date &);
    bool operator<(const date &);

    bool esVacia();
};

ostream &operator<<(ostream &o, date &d);

#endif
