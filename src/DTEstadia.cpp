#include <string>
#include "../include/DTEstadia.h" 
using namespace std;
#include <iostream>

DTEstadia::DTEstadia()
{
    this->huesped = "";
    this->reserva = 0;
    this->hostal = "";
    this->habitacion = 0;
}

DTEstadia::DTEstadia(string hues, int res, date entrada, date salida, string hostal, int hab){
    this->huesped = hues;
    this->reserva = res;
    this->entrada = entrada;
    this->salida = salida;
    this->hostal = hostal;
    this->habitacion = hab;
}


    string DTEstadia::getHuesped(){
        return this->huesped;
    }

    int DTEstadia::getReserva(){
        return this->reserva;
    }

    date DTEstadia::getEntrada(){
        return this->entrada;
    }

    date DTEstadia::getSalida(){
        return this->salida;
    }

    string DTEstadia::getHostal(){
        return this->hostal;
    }

    int DTEstadia::getHabitacion(){
        return this->habitacion;
    }


    void DTEstadia::setHuesped(string hues){
        this->huesped = hues;
    }

    void DTEstadia::setReserva(int res){
        this->reserva = res;
    }

    void DTEstadia::setEntrada(date entrada){
        this->entrada = entrada;
    }

    void DTEstadia::setSalida(date salida){
        this->salida = salida;
    }
    
    void DTEstadia::setHostal(string hostal){
        this->hostal = hostal;
    }
    
    void DTEstadia::setHabitacion(int hab){
        this->habitacion = hab;
    }
    
    ostream &operator<<(ostream &o,  DTEstadia &e){
        o << "Huesped: " << e.getHuesped() <<endl;
        o << "Código Reserva: " << e.getReserva() <<endl;
        date entrada = e.getEntrada();
        o << "Fecha de entrada: " << entrada << endl;
        date salida = e.getSalida();
        o << "Fecha de salida: ";
        if (salida.esVacia())
        {
            o << "Sin Finalizar."<< endl;
        } else {
            o << salida << endl;
        }
        o << "Hostal: " << e.getHostal() << endl;
        o << "Habitación: " << e.getHabitacion() << endl;
        return o;
    }