#include "../include/Fabrica.h"

#include <iostream>
#include <limits>
using namespace std;

int main()
{
    Fabrica *fabrica = Fabrica::getInstancia();
    int opcion = 7;

    do
    {
        cout << "Elija una opción:" << endl;
        cout << "0: Salir." << endl;
        cout << "1: Carga de Datos de Prueba." << endl;
        cout << "2: Alta de Usuario." << endl;
        cout << "3: Alta de Hostal." << endl;
        cout << "4: Alta de Habitación." << endl;
        cout << "5: Asignar Empleado a Hostal." << endl;
        cout << "6: Realizar Reserva." << endl;
        cout << "7: Consultar top 3 de hostales." << endl;
        cout << "8: Registrar Estadía." << endl;
        cout << "9: Finalizar Estadía." << endl;
        cout << "10: Calificar Estadía." << endl;
        cout << "11: Comentar Calificación." << endl;
        cout << "12: Consulta de Usuario." << endl;
        cout << "13: Consulta de Hostal." << endl;
        cout << "14: Consulta de Reserva. " << endl;
        cout << "15: Consulta de Estadía. " << endl;
        cout << "16: Baja de Reserva. " << endl;
        cout << "17: Suscribirse a Notificaciones." << endl;
        cout << "18: Consulta de Notificaciones." << endl;
        cout << "19: Eliminar Suscripción." << endl;
        cout << "20: Modificar Fecha del Sistema." << endl;

        cin >> opcion;
        switch (opcion)
        {
        case 0:
        {
            delete fabrica;
            break;
        }
        case 1: // Carga de Datos de Prueba
        {
            // Empleados
            InterfazUsuario *iUsuario = fabrica->getInterfazUsuario();
            DTUsuario *E = new DTEmpleado("Emilia", "emilia@mail.com", "123", TipoCargo::Recepcion);
            bool registrado = iUsuario->ingresarPersona(E);
            if (!registrado)
                iUsuario->confirmarAlta();
            else
                iUsuario->cancelarAlta();
            delete E;

            E = new DTEmpleado("Leonardo", "leo@mail.com", "123", TipoCargo::Recepcion);
            registrado = iUsuario->ingresarPersona(E);
            if (!registrado)
                iUsuario->confirmarAlta();
            else
                iUsuario->cancelarAlta();
            delete E;

            E = new DTEmpleado("Alina", "alina@mail.com", "123", TipoCargo::Administracion);
            registrado = iUsuario->ingresarPersona(E);
            if (!registrado)
                iUsuario->confirmarAlta();
            else
                iUsuario->cancelarAlta();
            delete E;

            E = new DTEmpleado("Barliman", "barli@mail.com", "123", TipoCargo::Recepcion);
            registrado = iUsuario->ingresarPersona(E);
            if (!registrado)
                iUsuario->confirmarAlta();
            else
                iUsuario->cancelarAlta();
            delete E;

            // Huespedes
            DTUsuario *H = new DTHuesped("Sofia", "sofia@mail.com", "123", true);
            registrado = iUsuario->ingresarPersona(H);
            if (!registrado)
                iUsuario->confirmarAlta();
            else
                iUsuario->cancelarAlta();
            delete H;

            H = new DTHuesped("Frodo", "frodo@mail.com", "123", true);
            registrado = iUsuario->ingresarPersona(H);
            if (!registrado)
                iUsuario->confirmarAlta();
            else
                iUsuario->cancelarAlta();
            delete H;

            H = new DTHuesped("Sam", "sam@mail.com", "123", false);
            registrado = iUsuario->ingresarPersona(H);
            if (!registrado)
                iUsuario->confirmarAlta();
            else
                iUsuario->cancelarAlta();
            delete H;

            H = new DTHuesped("Merry", "merry@mail.com", "123", false);
            registrado = iUsuario->ingresarPersona(H);
            if (!registrado)
                iUsuario->confirmarAlta();
            else
                iUsuario->cancelarAlta();
            delete H;

            H = new DTHuesped("Pippin", "pippin@mail.com", "123", false);
            registrado = iUsuario->ingresarPersona(H);
            if (!registrado)
                iUsuario->confirmarAlta();
            else
                iUsuario->cancelarAlta();
            delete H;

            H = new DTHuesped("Seba", "seba@mail.com", "123", true);
            registrado = iUsuario->ingresarPersona(H);
            if (!registrado)
                iUsuario->confirmarAlta();
            else
                iUsuario->cancelarAlta();
            delete H;

            // Hostales
            InterfazHostal *iHostal = fabrica->getInterfazHostal();
            iHostal->registrarHostal("La posada del finger", "Av de la playa 123, Maldonado", "099111111");
            iHostal->registrarHostal("Mochileros", "Rambla Costera 333, Rocha", "42579512");
            iHostal->registrarHostal("El Pony Pisador", "Bree (preguntar por Gandalf) ", "000");
            iHostal->registrarHostal("Altos de Fing", "Av del Toro 1424", "099892992");
            iHostal->registrarHostal("Caverna Lujosa", "Amaya 2515", "233233235");

            // Habitaciones
            DTHabitacion *HA = new DTHabitacion(1, 40, 2);
            iHostal->ingresarHabitacion(HA, "La posada del finger");
            iHostal->confirmarAltaHabitacion();
            delete HA;

            HA = new DTHabitacion(2, 10, 7);
            iHostal->ingresarHabitacion(HA, "La posada del finger");
            iHostal->confirmarAltaHabitacion();
            delete HA;

            HA = new DTHabitacion(3, 30, 3);
            iHostal->ingresarHabitacion(HA, "La posada del finger");
            iHostal->confirmarAltaHabitacion();
            delete HA;

            HA = new DTHabitacion(4, 5, 12);
            iHostal->ingresarHabitacion(HA, "La posada del finger");
            iHostal->confirmarAltaHabitacion();
            delete HA;

            HA = new DTHabitacion(1, 3, 2);
            iHostal->ingresarHabitacion(HA, "Caverna Lujosa");
            iHostal->confirmarAltaHabitacion();
            delete HA;

            HA = new DTHabitacion(1, 9, 5);
            iHostal->ingresarHabitacion(HA, "El Pony Pisador");
            iHostal->confirmarAltaHabitacion();
            delete HA;

            // Asignación de empleados a hostales
            iUsuario->ingresarEmpleado("La posada del finger", "emilia@mail.com");
            iUsuario->confirmarAsignacion();

            iUsuario->ingresarEmpleado("Mochileros", "leo@mail.com");
            iUsuario->confirmarAsignacion();

            iUsuario->ingresarEmpleado("Mochileros", "alina@mail.com");
            iUsuario->confirmarAsignacion();

            iUsuario->ingresarEmpleado("El Pony Pisador", "barli@mail.com");
            iUsuario->confirmarAsignacion();

            // Reservas
            InterfazReserva *iReserva = fabrica->getInterfazReserva();

            date in;
            in.setDia(1);
            in.setMes(5);
            in.setAnio(2022);
            in.setHora(14);
            date out;
            out.setDia(10);
            out.setMes(5);
            out.setAnio(2022);
            out.setHora(10);
            iReserva->ingresarReserva(in, out, false);
            iReserva->almacenarNombreHostal("La posada del finger");
            iReserva->ingresarResponsable("sofia@mail.com");
            iReserva->confirmarReserva(1);

            in = date(4, 1, 2001, 20);
            out = date(5, 1, 2001, 2);
            iReserva->ingresarReserva(in, out, true);
            iReserva->almacenarNombreHostal("El Pony Pisador");
            iReserva->ingresarResponsable("frodo@mail.com");
            iReserva->ingresarHuesped("sam@mail.com");
            iReserva->ingresarHuesped("merry@mail.com");
            iReserva->ingresarHuesped("pippin@mail.com");
            iReserva->confirmarReserva(1);

            in = date(7, 6, 2022, 14);
            out = date(30, 6, 2022, 11);
            iReserva->ingresarReserva(in, out, false);
            iReserva->almacenarNombreHostal("La posada del finger");
            iReserva->ingresarResponsable("sofia@mail.com");
            iReserva->confirmarReserva(3);

            in = date(10, 6, 2022, 14);
            out = date(30, 6, 2022, 11);
            iReserva->ingresarReserva(in, out, false);
            iReserva->almacenarNombreHostal("Caverna Lujosa");
            iReserva->ingresarResponsable("seba@mail.com");
            iReserva->confirmarReserva(1);

            // Estadias
            InterfazFecha *iFechaSistema = fabrica->getInterfazFecha();

            in = date(1, 5, 2022, 18);
            iFechaSistema->actualizarFecha(in);
            iReserva->registrarEstadia(1, "sofia@mail.com");

            in = date(4, 1, 2001, 21);
            iFechaSistema->actualizarFecha(in);
            iReserva->registrarEstadia(2, "frodo@mail.com");

            in = date(4, 1, 2001, 21);
            iFechaSistema->actualizarFecha(in);
            iReserva->registrarEstadia(2, "sam@mail.com");

            in = date(4, 1, 2001, 21);
            iFechaSistema->actualizarFecha(in);
            iReserva->registrarEstadia(2, "merry@mail.com");

            in = date(4, 1, 2001, 21);
            iFechaSistema->actualizarFecha(in);
            iReserva->registrarEstadia(2, "pippin@mail.com");

            in = date(11, 6, 2022, 18);
            iFechaSistema->actualizarFecha(in);
            iReserva->registrarEstadia(4, "seba@mail.com");

            // Finalizacion de estadias
            out = date(10, 5, 2022, 9);
            iFechaSistema->actualizarFecha(out);
            iHostal->finalizarEstadia("sofia@mail.com", "La posada del finger");

            out = date(5, 1, 2001, 2);
            iFechaSistema->actualizarFecha(out);
            iHostal->finalizarEstadia("frodo@mail.com", "El Pony Pisador");

            out = date(15, 6, 2022, 22);
            iFechaSistema->actualizarFecha(out);
            iHostal->finalizarEstadia("seba@mail.com", "Caverna Lujosa");

            // Calificar estadias
            in = date(11, 5, 2022, 18);
            iFechaSistema->actualizarFecha(out);
            iReserva->calificar("Un poco caro para lo que ofrecen. El famoso gimnasio era una caminadora (que hacía tremendo ruido) y 2 pesas, la piscina parecía el lago del Parque Rodó y el desayuno eran 2 tostadas con mermelada. Internet se pasaba cayendo. No vuelvo.", 3, "sofia@mail.com", 1, "La posada del finger");

            in = date(5, 1, 2001, 3);
            iFechaSistema->actualizarFecha(out);
            iReserva->calificar("Se pone peligroso de noche, no recomiendo. Además no hay caja fuerte para guardar anillos.", 2, "frodo@mail.com", 2, "El Pony Pisador");

            in = date(15, 6, 2022, 23);
            iFechaSistema->actualizarFecha(in);
            iReserva->calificar("Había pulgas en la habitación. Que lugar más mamarracho!!", 1, "seba@mail.com", 4, "La posada del finger");

            // Comentar calificacion
            iReserva->responder("barli@mail.com", "Desapareció y se fue sin pagar.", "frodo@mail.com", 2);

            //Reiniciamos la fecha
            in = date(22, 6, 2022, 2);
            iFechaSistema->actualizarFecha(in);
            break;
        }
        case 2: // Alta de Usuario
                //*la memoria pedida se debe eliminar del controlador, caso 0
        {
            bool registrado;
            string nombre = "\0";
            string contrasenia = "\0";
            string email = "\0";
            DTUsuario *dtusuario;
            int tipo = 0;
            int confirmar = 0;
            do
            {
                // primero pregunto que tipo de usuario es
                // segundo ingreso los datos comunes de usuario
                cout << "Selecione el tipo de usuario:" << endl;
                cout << "1- Ingresar huesped." << endl;
                cout << "2- Ingresar empleado." << endl;
                cin >> tipo;
                cout << "Ingresar el nombre: ";
                cin >> nombre;
                cout << "Ingrese mail del usuario: ";
                cin >> email;
                cout << "Ingrese contraseña del usuario: ";
                cin >> contrasenia;
                // si es Huesped creo un DTHuesped y lo guardo en un DTUsuario y si es empleado creo un DTEmpleado
                if (tipo == 1)
                {
                    int esFinger = 0;
                    cout << "¿Es finger? \n 1- Si. \n 2- No." << endl;
                    cin >> esFinger;
                    if (esFinger == 1)
                        dtusuario = new DTHuesped(nombre, email, contrasenia, true);
                    else
                        dtusuario = new DTHuesped(nombre, email, contrasenia, false);
                }
                else
                {
                    int tipoCargo = 0;
                    cout << "¿Qué cargo tiene? \n 1-Administracion \n 2-Limpieza \n 3-Recepcion \n 4-Infraestructura \n";
                    cin >> tipoCargo;
                    switch (tipoCargo)
                    {
                    case 1:
                    {
                        dtusuario = new DTEmpleado(nombre, email, contrasenia, TipoCargo::Administracion);
                        break;
                    }
                    case 2:
                    {
                        dtusuario = new DTEmpleado(nombre, email, contrasenia, TipoCargo::Limpieza);
                        break;
                    }
                    case 3:
                    {
                        dtusuario = new DTEmpleado(nombre, email, contrasenia, TipoCargo::Recepcion);
                        break;
                    }
                    case 4:
                    {
                        dtusuario = new DTEmpleado(nombre, email, contrasenia, TipoCargo::Infraestructura);
                        break;
                    }
                    }
                }
                InterfazUsuario *Iusuario = fabrica->getInterfazUsuario();
                registrado = Iusuario->ingresarPersona(dtusuario);
            } while (registrado);
            cout << "Ingrese 1 para confirmar, o 2 para cancelar: ";
            cin >> confirmar;
            if (confirmar == 1)
            {
                fabrica->getInterfazUsuario()->confirmarAlta();
                cout << "Se añadió el usuario al sistema." << endl;
            }
            else
            {
                fabrica->getInterfazUsuario()->cancelarAlta();
                cout << "Se canceló el alta." << endl;
            }

            //*ahora tengo que hacer el delete del DTUsuario que cree para pasar como parametro
            //*en caso de que hubiera confirmado el alta, se creo nueva memoria para el sistema asi que ya no necesito la info del DT
            delete dtusuario;
            break;
        }
        case 3: // Alta de Hostal
        {
            string nombreHostal = "\0";
            string direccion = "\0";
            string telefono = "\0";

            cout << "Ingrese el nombre del hostal a registrar: \n";
            cin.ignore();
            getline(cin, nombreHostal);
            cout << "Ingrese la dirección del hostal a registrar: \n";
            getline(cin, direccion);
            cout << "Ingrese el teléfono del hostal a registrar: \n";
            cin >> telefono;

            InterfazHostal *iHostal = fabrica->getInterfazHostal();
            iHostal->registrarHostal(nombreHostal, direccion, telefono);
            cout << "El Hostal se registro con exito." << endl;
            break;
        }
        case 4: // Alta de Habitacion
        {
            bool bandera = true;
            cin.ignore();
            InterfazHostal *hos = fabrica->getInterfazHostal();
            string nombreHostal;
            map<string, DTHostal *> hostales = hos->obtenerHostales(); //! hay que eliminar estos dthostales 1
            while (bandera)
            {
                for (map<string, DTHostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it)
                {
                    cout << *it->second << endl;
                }
                cout << "Ingrese el nombre del hostal elegido: ";
                getline(cin, nombreHostal);
                try
                {

                    if (hostales.find(nombreHostal) == hostales.end())
                    {
                        throw nombreHostal;
                    }
                    else
                    {
                        bandera = false;
                        int numeroHabitacion;
                        int capacidad;
                        int precio;
                        cout << "Ingrese el numero de habitación: ";
                        cin >> numeroHabitacion;
                        cout << "Ingrese el precio de la habitación: ";
                        cin >> precio;
                        cout << "Ingrese la capacidad de la habitación: ";
                        cin >> capacidad;
                        DTHabitacion *habitacion = new DTHabitacion(numeroHabitacion, precio, capacidad); //! eleiminar dtHabitacion 2
                        hos->ingresarHabitacion(habitacion, nombreHostal);
                        int opcion;
                        cout << "Ingrese 1 para confirmar, o 2 para cancelar: ";
                        cin >> opcion;
                        if (opcion == 1) {
                            hos->confirmarAltaHabitacion();
                            cout << "Se ingreso la habitacion al sistema." << endl;
                        }
                        else {
                            hos->cancelarAltaHabitacion();
                            cout << "Se cancelo el alta." << endl;
                        }
                        // delete habitacion;
                        delete habitacion; //! delete 2
                    }
                }
                catch (string nombreHostal)
                {
                    cout << "El Hostal: " << nombreHostal << " no pertenece a los hostales registrados\n";
                }
            }
            for (map<string, DTHostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it) //! delete 1
            {
                DTHostal *borrar = it->second;
                delete borrar;
            }
            hostales.clear();
            break;
        }
        case 5: // Asignar Empleado a Hostal
        {
            bool condicion1 = true;
            cin.ignore();
            InterfazHostal *iHostal = fabrica->getInterfazHostal();
            string nombreHostal;
            map<string, DTHostal *> hostales = iHostal->obtenerHostales(); //! hay que hacer delete 1
            while (condicion1)
            {
                // Listo los hostales
                for (map<string, DTHostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it)
                {
                    cout << *it->second << endl;
                }
                // El usuario seleciona un hostal
                cout << "Ingrese el nombre del hostal elegido: \n";
                getline(cin, nombreHostal);
                // cin.clear();

                try
                {

                    if (hostales.find(nombreHostal) == hostales.end())
                    {
                        throw nombreHostal;
                    }
                    else
                    {
                        condicion1 = false;
                        bool condicion2 = true;
                        // cin.ignore();

                        // Listo los empleados
                        InterfazUsuario *iUsuario = fabrica->getInterfazUsuario();
                        string emailEmpleado;
                        map<string, DTEmpleado *> empleados = iUsuario->obtenerEmpleados(); //! hay que hacer delete 2
                        while (condicion2)
                        {
                            for (map<string, DTEmpleado *>::iterator it = empleados.begin(); it != empleados.end(); ++it)
                            {
                                cout << *it->second << endl;
                            }
                            // El usuario seleciona un empleado
                            cout << "Ingrese el mail del empleado elegido: \n";
                            getline(cin, emailEmpleado);

                            try
                            {
                                if (empleados.find(emailEmpleado) == empleados.end())
                                {
                                    throw emailEmpleado;
                                }
                                else
                                {
                                    condicion2 = false;
                                    // El usuario confirma o cancela
                                    iUsuario->ingresarEmpleado(nombreHostal, emailEmpleado);
                                    int opcion;
                                    cout << "Ingrese 1 para confirmar, o 2 para cancelar: ";
                                    cin >> opcion;
                                    if (opcion == 1)
                                    {
                                        iUsuario->confirmarAsignacion();
                                        cout << "Se asignó el empleado al hostal." << endl;
                                    }
                                    else
                                    {
                                        iUsuario->cancelarAsignacion();
                                        cout << "Se canceló la asignación." << endl;
                                    }
                                }
                            }
                            catch (string emailEmpleado)
                            {
                                cout << "El email: " << emailEmpleado << " no pertenece a los empleados registrados\n";
                            }
                        }
                        for (map<string, DTEmpleado *>::iterator it = empleados.begin(); it != empleados.end(); ++it) //! delete 2
                        {
                            DTEmpleado *borrar = it->second;
                            delete borrar;
                        }
                        empleados.clear();
                    }
                }
                catch (string nombreHostal)
                {
                    cout << "El Hostal: " << nombreHostal << " no pertenece a los hostales registrados\n";
                }
            }
            for (map<string, DTHostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it) //! delete 1
            {
                DTHostal *borrar = it->second;
                delete borrar;
            }
            hostales.clear();
            break;
        }
        case 6: // Realizar Reserva
        {
            InterfazHostal *iHostal = fabrica->getInterfazHostal();
            bool bandera = true;
            cin.ignore();
            map<string, DTHostal *> colHostales = iHostal->obtenerHostales(); //! hay que hacer delete 1
            string nombreHostal;
            while (bandera)
            {
                cout << "Hostales: " << endl;
                for (map<string, DTHostal *>::iterator it = colHostales.begin(); it != colHostales.end(); ++it)
                {
                    cout << *it->second << endl;
                }
                cout << "Seleccione un hostal de la lista: ";
                getline(cin, nombreHostal);
                try
                {
                    if (colHostales.find(nombreHostal) == colHostales.end())
                    {
                        throw nombreHostal; // mal ingresado el nombre hostal
                    }
                    else
                    {
                        bandera = false;
                        date fechaCI;
                        int num;
                        cout << "Ingresar el dia del check in: ";
                        cin >> num;
                        fechaCI.setDia(num);
                        cout << "Ingresar el mes del check in: ";
                        cin >> num;
                        fechaCI.setMes(num);
                        cout << "Ingresar el año del check in: ";
                        cin >> num;
                        fechaCI.setAnio(num);
                        cout << "Ingresar la hora del check in: ";
                        cin >> num;
                        fechaCI.setHora(num);

                        date fechaCO;
                        cout << "Ingresar el dia del check out: ";
                        cin >> num;
                        fechaCO.setDia(num);
                        cout << "Ingresar el mes del check out: ";
                        cin >> num;
                        fechaCO.setMes(num);
                        cout << "Ingresar el año del check out: ";
                        cin >> num;
                        fechaCO.setAnio(num);
                        cout << "Ingresar la hora del check out: ";
                        cin >> num;
                        fechaCO.setHora(num);

                        cout << "Ingrese 1 para registrar una reserva individual, 2 para una reserva grupal: ";
                        int i;
                        cin >> i;
                        InterfazReserva *iReserva = fabrica->getInterfazReserva();
                        if (i == 1)
                            iReserva->ingresarReserva(fechaCI, fechaCO, false);
                        else
                            iReserva->ingresarReserva(fechaCI, fechaCO, true);
                        //* aca tengo que hacer otro try catch porque tiene que ingresar habitaciones
                        bool bandera2 = true;
                        int numeroHab;
                        iReserva->almacenarNombreHostal(nombreHostal);
                        map<int, DTHabitacion *> colHabitaciones = iHostal->obtenerHabDisponibles(nombreHostal, fechaCI, fechaCO); //! hay que  hacer delete 2
                        while (bandera2)
                        {
                            cout << "Habitaciones del hostal:" << endl;
                            for (map<int, DTHabitacion *>::iterator it2 = colHabitaciones.begin(); it2 != colHabitaciones.end(); ++it2)
                            {
                                cout << *it2->second << endl;
                            }
                            cout << "Seleccione una habitación de la lista: ";
                            cin >> numeroHab;
                            try
                            {
                                if (colHabitaciones.find(numeroHab) == colHabitaciones.end())
                                {
                                    throw numeroHab; // mal ingresado el numero habitacion
                                }
                                else
                                {
                                    bandera2 = false;
                                    map<int, DTHabitacion *>::iterator it = colHabitaciones.find(numeroHab);
                                    int capacidad = it->second->getCapacidad();
                                    InterfazUsuario *iUsuario = fabrica->getInterfazUsuario();
                                    map<string, DTHuesped *> colHuespedes = iUsuario->obtenerHuespedes(); //! hay que hacer delete 3
                                    bool bandera3 = true;
                                    string huesResp;
                                    while (bandera3)
                                    {
                                        for (map<string, DTHuesped *>::iterator it3 = colHuespedes.begin(); it3 != colHuespedes.end(); ++it3)
                                        {
                                            cout << *it3->second << endl;
                                        }
                                        cout << "Ingrese el email del huesped responsable de la reserva: ";

                                        cin >> huesResp;
                                        //*aca hago otro try catch para ver que el huesped este bien ingresado
                                        try
                                        {
                                            if (colHuespedes.find(huesResp) == colHuespedes.end())
                                            {
                                                throw huesResp; // se ingreso mal el email  del huesped
                                            }
                                            else
                                            {
                                                bandera3 = false;
                                                iReserva->ingresarResponsable(huesResp);
                                                capacidad = capacidad - 1;
                                                if (i == 2)
                                                {
                                                    cout << "Ingrese el email del resto de los huespedes de la reserva (Ingrese 0 para terminar la operación): ";
                                                    string hues;
                                                    bool bandera4 = true;
                                                    while (hues != "0" && capacidad != 0 && bandera4)
                                                    {
                                                        cin >> hues;
                                                        //*aca otro try catch para asegurarme que ingrese bien los huespedes del grupo
                                                        if (hues == "0")
                                                        {
                                                            bandera4 = false;
                                                        }
                                                        else
                                                        {

                                                            try
                                                            {
                                                                if (colHuespedes.find(hues) == colHuespedes.end())
                                                                {
                                                                    throw hues;
                                                                }
                                                                else
                                                                {
                                                                    iReserva->ingresarHuesped(hues);
                                                                    cout << "Ingrese el siguiente huesped :";
                                                                }
                                                            }
                                                            catch (string hues)
                                                            {
                                                                cout << "El Huesped: " << hues << " es incorrecto\n";
                                                            }
                                                        }
                                                    }
                                                    if (capacidad == 0)
                                                        cout << "La habitacion ya esta llena." << endl;
                                                    cout << "Ingrese 1 para confirmar la reserva, 2 para cancelarla: ";
                                                    int opcion;
                                                    cin >> opcion;
                                                    if (opcion == 1)
                                                    {
                                                        iReserva->confirmarReserva(numeroHab);
                                                        cout << "Se realizo la reserva." << endl;
                                                    }
                                                    else {
                                                        iReserva->cancelarReserva();
                                                        cout << "Se cancelo la reserva." << endl;
                                                    }
                                                } else {
                                                    int opcion;
                                                    cout << "Ingrese 1 para confirmar la reserva, 2 para cancelarla: ";
                                                    cin >> opcion;
                                                    if (opcion == 1)
                                                    {
                                                        iReserva->confirmarReserva(numeroHab);
                                                        cout << "Se realizo la reserva." << endl;
                                                    }
                                                    else {
                                                        iReserva->cancelarReserva();
                                                        cout << "Se cancelo la reserva." << endl;
                                                    }
                                                }

                                                
                                            }
                                        }
                                        catch (string huesResp)
                                        {
                                            cout << "El Huesped: " << huesResp << " es incorrecto\n";
                                        }
                                    }
                                    for (map<string, DTHuesped *>::iterator it3 = colHuespedes.begin(); it3 != colHuespedes.end(); ++it3) //! delete 3
                                    {
                                        delete it3->second;
                                    }
                                    colHuespedes.clear();
                                }
                            }
                            catch (int numeroHab)
                            {
                                cout << "El numero de Habitacion: " << numeroHab << " es incorrecto\n";
                            }
                        }
                        for (map<int, DTHabitacion *>::iterator it2 = colHabitaciones.begin(); it2 != colHabitaciones.end(); ++it2) //! delete 2
                        {
                            delete it2->second;
                        }
                        colHabitaciones.clear();
                    }
                }
                catch (string nombreHostal)
                {
                    cout << "El Hostal: " << nombreHostal << " no pertenece a los hostales registrados\n";
                }
            }
            for (map<string, DTHostal *>::iterator it = colHostales.begin(); it != colHostales.end(); ++it) //! delete 1
            {
                delete it->second;
            }
            colHostales.clear();
            break;
        }
        case 7: // Consultar top 3 de hostales
        {
            InterfazHostal *iHostal = fabrica->getInterfazHostal();
            DTHostal **top3 = iHostal->obtenerTop3(); //! hay que hacer delete 1
            cout << "Top 3 de Hostales:" << endl;

            string nombreHostal;
            cin.ignore();
            bool condicion = true;
            while (condicion)
            {
                for (int i = 0; i <= 2 && (top3[i] != NULL); i++)
                {
                    cout << "Top " << i + 1 << ":" << endl;
                    cout << *top3[i] << endl;
                }

                cout << "Escriba el nombre de un hostal si quiere conocer sus calificacion, sino escriba un 0: ";
                getline(cin, nombreHostal);
                try
                {
                    if (nombreHostal != "0")
                    {
                        int i = 0;
                        while (i <= 2 && top3[i] != NULL && top3[i]->getNombre() != nombreHostal)
                            i++;
                        if (i > 2 || top3[i] == NULL)
                            throw nombreHostal;
                        else
                        {
                            condicion = false;
                            set<DTCalificacion *> calificaciones = iHostal->obtenerCalificacionesHostal(nombreHostal); //! hay que hacer delete 2
                            cout << "Calificaciones del hostal " << nombreHostal << ":" << endl;

                            if (calificaciones.empty())
                            {
                                cout << "El Hostal no tiene calificaciones" << endl;
                            }

                            for (set<DTCalificacion *>::iterator it = calificaciones.begin(); it != calificaciones.end(); ++it)
                            {
                                cout << **it << endl;
                                delete *it; //! delete 2
                            }
                        }
                    }
                    else
                    {
                        condicion = false;
                    }
                }
                catch (string nombreHostal)
                {
                    cout << "El hostal " << nombreHostal << " no pertenece al top 3 de hostales." << endl;
                }
            }

            for (int i = 0; i <= 2; i++) //! delete 1
            {
                if (top3[i] != NULL)
                    delete top3[i];
            }

            delete[] top3;
            break;
        }
        case 8: // Registrar Estadía
        {
            InterfazHostal *iHostal = fabrica->getInterfazHostal();
            map<string, DTHostal *> colHostales = iHostal->obtenerHostales(); //! hya que hacer delete 1

            string nombreHostal;
            cin.ignore();
            bool condition = true;
            while (condition)
            {
                cout << "Hostales: " << endl;
                for (map<string, DTHostal *>::iterator it = colHostales.begin(); it != colHostales.end(); ++it)
                {
                    cout << *it->second << endl;
                }
                cout << "Seleccione un hostal de la lista: ";
                getline(cin, nombreHostal);
                try
                {
                    if (colHostales.find(nombreHostal) == colHostales.end())
                        throw nombreHostal;
                    else
                    {
                        condition = false;
                        cout << "Ingrese el email del huesped para registrar una estadía: ";
                        string emailHues;
                        cin >> emailHues;
                        map<int, DTReserva *> reservasNoCancel = iHostal->obtenerReservasNoCanceladas(nombreHostal, emailHues); //! hay que hacer delete 2
                        int codigoReserva;
                        bool condition2 = true;
                        while (condition2)
                        {
                            cout << "Reservas no canceladas del huesped:" << endl;
                            for (map<int, DTReserva *>::iterator it = reservasNoCancel.begin(); it != reservasNoCancel.end(); ++it)
                            {
                                date cIn = it->second->getCheckIn();
                                date cOut = it->second->getCheckOut();
                                cout << "La reserva " << it->second->getCodigo() << ", con fechas: " << cIn << " hasta " << cOut << endl;
                            }
                            cout << "Seleccione una reserva de la lista: ";
                            cin >> codigoReserva;
                            try
                            {
                                if (reservasNoCancel.find(codigoReserva) == reservasNoCancel.end())
                                    throw codigoReserva;
                                else
                                {
                                    condition2 = false;
                                    InterfazReserva *iReserva = fabrica->getInterfazReserva();
                                    iReserva->registrarEstadia(codigoReserva, emailHues);
                                    cout << "La estadia fue registrada " << endl;
                                }
                            }
                            catch (int codigoReserva)
                            {
                                cout << "La reserva " << codigoReserva << "no se encuentra en el listado." << endl;
                            }
                        }
                        for (map<int, DTReserva *>::iterator it = reservasNoCancel.begin(); it != reservasNoCancel.end(); ++it) //! delete 2
                        {
                            delete it->second;
                        }
                        reservasNoCancel.clear();
                    }
                }
                catch (string nombreHostal)
                {
                    cout << "El hostal " << nombreHostal << " no pertenece a los hostales registrados." << endl;
                }
            }
            for (map<string, DTHostal *>::iterator it = colHostales.begin(); it != colHostales.end(); ++it) //! delete 1
            {
                delete it->second;
            }
            colHostales.clear();
            break;
        }
        case 9: // Finalizar Estadía
        {
            InterfazHostal *iHostal = fabrica->getInterfazHostal();
            InterfazUsuario *iUsuario = fabrica->getInterfazUsuario();
            map<string, DTHostal *> colHostales = iHostal->obtenerHostales(); //! hay que hacer delete 1
            string emailHues;
            string nombreHostal;
            bool bandera = true;
            cin.ignore();
            while (bandera)
            {
                for (map<string, DTHostal *>::iterator it = colHostales.begin(); it != colHostales.end(); ++it)
                {
                    cout << *it->second << endl;
                }
                cout << "Seleccione un hostal de la lista: " << endl;
                getline(cin, nombreHostal);
                try
                {
                    if (colHostales.find(nombreHostal) == colHostales.end())
                    {
                        throw nombreHostal;
                    }
                    else
                    {
                        bandera = false;
                        bool bandera2 = true;
                        map<string, DTUsuario *> colUsuarios = iUsuario->obtenerUsuarios(); //! Hay  que hacer delete 2
                        while (bandera2)
                        {
                            cout << "Ingrese el email del huesped para finalizar su estadía" << endl;
                            cin >> emailHues;
                            try
                            {

                                if (colUsuarios.find(emailHues) == colUsuarios.end())
                                {
                                    throw emailHues;
                                }
                                else
                                {
                                    bandera2 = false;
                                    iHostal->finalizarEstadia(emailHues, nombreHostal);
                                    cout << "La estadía fue finalizada." << endl;
                                }
                            }
                            catch (string emailHues)
                            {
                                cout << "El email: " << emailHues << " es incorrecto";
                            }
                        }
                        for (map<string, DTUsuario *>::iterator it = colUsuarios.begin(); it != colUsuarios.end(); ++it) //! delete 2
                        {
                            delete it->second;
                        }
                        colUsuarios.clear();
                    }
                }
                catch (string nombreHostal)
                {
                    cout << "El nombre de Hostal: " << nombreHostal << " es incorrecto";
                }
            }
            for (map<string, DTHostal *>::iterator it = colHostales.begin(); it != colHostales.end(); ++it) //! delete 1
            {
                delete it->second;
            }
            colHostales.clear();
            break;
        }
        case 10: // Calificar Estadía
        {
            InterfazHostal *iHostal = fabrica->getInterfazHostal();
            map<string, DTHostal *> colHostales = iHostal->obtenerHostales(); //! hay que hacer delete 1
            bool bandera = true;
            cin.ignore();
            while (bandera)
            {
                cout << "Hostales: " << endl;
                for (map<string, DTHostal *>::iterator it = colHostales.begin(); it != colHostales.end(); ++it)
                {
                    cout << *it->second << endl;
                }
                cout << "Seleccione un hostal de la lista: " << endl;
                string nombreHostal;
                getline(cin, nombreHostal);
                try
                {
                    if (colHostales.find(nombreHostal) == colHostales.end())
                    {
                        throw nombreHostal;
                    }
                    else
                    {
                        bandera = false;
                        cout << "Ingrese el email del huesped que desea calificar su estadía: " << endl;
                        string emailHuesped;
                        cin >> emailHuesped;
                        set<DTEstadia *> estadiasFin;
                        estadiasFin = iHostal->obtenerEstadiasFinalizadas(emailHuesped, nombreHostal); //! hay que hacer delete 2
                        if (estadiasFin.empty())
                        {
                            cout << "No hay estadías finalizadas para este huesped" << endl;
                            break;
                        }
                        bool bandera2 = true;
                        while (bandera2)
                        {
                            cout << "Se listan las estadías finalizadas asociadas al huesped: ";
                            for (set<DTEstadia *>::iterator it = estadiasFin.begin(); it != estadiasFin.end(); ++it)
                            {
                                DTEstadia *estadia = *it;
                                cout << *estadia << endl;
                            }
                            cout << "Ingrese el codigo de reserva de la estadía a calificar: " << endl;
                            int codigoRes;
                            cin >> codigoRes;
                            try
                            {
                                set<DTEstadia *>::iterator it = estadiasFin.begin();
                                DTEstadia *est = *it;
                                while ((it != estadiasFin.end()) && (est->getReserva() != codigoRes))
                                {
                                    ++it;
                                    est = *it;
                                }
                                if (it == estadiasFin.end())
                                {
                                    throw codigoRes;
                                }
                                else
                                {
                                    bandera2 = false;
                                    InterfazReserva *iReserva = fabrica->getInterfazReserva();
                                    cout << "Ingrese la nota de su calificación (1...5)" << endl;
                                    int nota;
                                    cin >> nota;
                                    cout << "¿Desea agregar un comentario a su calificación? (1 = Si/2 = No)" << endl;
                                    int respuesta;
                                    cin >> respuesta;
                                    cin.ignore();
                                    if (respuesta == 1)
                                    {
                                        cout << "Ingrese su comentario: " << endl;
                                        string texto;
                                        getline(cin, texto);
                                        iReserva->calificar(texto, nota, emailHuesped, codigoRes, nombreHostal);
                                    }
                                    else
                                    {
                                        string textoVacio;
                                        textoVacio = "0";
                                        iReserva->calificar(textoVacio, nota, emailHuesped, codigoRes, nombreHostal);
                                    }
                                    cout << "Su calificación fue realizada con éxito." << endl;
                                }
                            }
                            catch (int codigoRes)
                            {
                                cout << "La estadía con código de reserva " << codigoRes << " no está listada." << endl;
                            }
                        }
                        for (set<DTEstadia *>::iterator it = estadiasFin.begin(); it != estadiasFin.end(); ++it)
                        {
                            DTEstadia *elim = *it;
                            delete elim;
                        }
                        estadiasFin.clear();
                    }
                }
                catch (string nombreHostal)
                {
                    cout << "El hostal " << nombreHostal << " no está registrado en el sistema." << endl;
                }
            }
            for (map<string, DTHostal *>::iterator it = colHostales.begin(); it != colHostales.end(); ++it)
            {
                delete it->second;
            }
            colHostales.clear();

            break;
        }
        case 11: // Comentar Calificación
        {
            InterfazUsuario *iUsuario = fabrica->getInterfazUsuario();
            map<string, DTEmpleado *> empleados = iUsuario->obtenerEmpleados(); //! hay que hacer delete 1
            string emailEmpleado;
            bool bandera = true;
            while (bandera)
            {
                for (map<string, DTEmpleado *>::iterator it = empleados.begin(); it != empleados.end(); ++it)
                {
                    cout << it->first << endl;
                }
                cout << "Seleccione el email del empleado a comentar la calificación" << endl;
                cin >> emailEmpleado;
                try
                {
                    if (empleados.find(emailEmpleado) == empleados.end())
                    {
                        throw emailEmpleado;
                    }
                    else
                    {
                        bandera = false;
                        bool bandera2 = true;
                        set<DTCalificacion *> sinResp = iUsuario->obtenerComentariosSinResponder(emailEmpleado); //! hay que hacer delete 2

                        int code;
                        while (bandera2)
                        {
                            bool bandera3 = true;
                            while (bandera3)
                            {
                                cout << "Se muestran las calificaciones sin responder asociadas al empleado" << endl;
                                for (set<DTCalificacion *>::iterator it = sinResp.begin(); it != sinResp.end(); ++it)
                                {
                                    DTCalificacion *dt = *it;
                                    cout << *dt << endl;
                                }
                                cout << "Ingrese el código de la Reserva:" << endl;
                                cin >> code;

                                bool encontrado = false;

                                for (set<DTCalificacion *>::iterator it = sinResp.begin(); it != sinResp.end(); ++it)
                                {
                                    DTCalificacion *dt = *it;
                                    int codReserva = dt->getReserva();
                                    // si encuentro el codigo, salgo y continuo
                                    if (codReserva == code)
                                    {
                                        encontrado = true;
                                    }
                                }
                                try
                                {
                                    if (!encontrado)
                                    {
                                        throw code;
                                    }
                                    else
                                    {

                                        bandera3 = false;
                                        bool bandera4 = true;
                                        string emailHuesped;
                                        while (bandera4)
                                        {

                                            cout << "Ingrese el email del huesped" << endl;
                                            cin >> emailHuesped;
                                            bool salida2 = true;
                                            // recorro buscando si el  email esta bien ingresado

                                            for (set<DTCalificacion *>::iterator it = sinResp.begin(); it != sinResp.end(); ++it)
                                            {
                                                DTCalificacion *dt = *it;
                                                if (emailHuesped == dt->getHuesped())
                                                    salida2 = false;
                                            }
                                            try
                                            {
                                                if (salida2)
                                                {
                                                    throw emailHuesped;
                                                }
                                                else
                                                {
                                                    bandera2 = false;
                                                    cin.ignore();
                                                    bandera4 = false;
                                                    cout << "Ingrese el texto a responder la calificación" << endl;
                                                    string texto;
                                                    getline(cin, texto);
                                                    InterfazReserva *iReserva = fabrica->getInterfazReserva();
                                                    iReserva->responder(emailEmpleado, texto, emailHuesped, code);
                                                    cout << "La respuesta fue relizada con exito." << endl;
                                                }
                                            }
                                            catch (string emailHuesped)
                                            {

                                                cout << "El email del Huesped " << emailHuesped << " es incorrecto" << endl;
                                            }
                                        }
                                    }
                                }
                                catch (int code)
                                {
                                    cout << "El codigo de Reserva " << code << " es incorrecto";
                                }
                            }
                            for (set<DTCalificacion *>::iterator it = sinResp.begin(); it != sinResp.end(); ++it) //! delete 2
                            {
                                delete *it;
                            }
                            sinResp.clear();
                        }
                    }
                }
                catch (string emailEmpleado)
                {
                    cout << "El email: " << emailEmpleado << " es incorrecto";
                }
            }
            for (map<string, DTEmpleado *>::iterator it = empleados.begin(); it != empleados.end(); ++it) //! delete 1
            {
                delete it->second;
            }
            empleados.clear();
            break;
        }
        case 12: // Consulta de Usuario
        {
            InterfazUsuario *user = fabrica->getInterfazUsuario();
            map<string, DTUsuario *> usuarios = user->obtenerUsuarios(); //! hay que hacer delete 1
            string email;
            bool condition = true;
            while (condition)
            {
                for (map<string, DTUsuario *>::iterator it = usuarios.begin(); it != usuarios.end(); ++it)
                    cout << it->second->getNombre() << ", con el mail: " << it->first << endl;

                cout << "Ingrese el mail del usuario a consultar" << endl;
                cin >> email;
                try
                {
                    if (usuarios.find(email) == usuarios.end())
                        throw email;
                    else
                    {
                        condition = false;
                        DTUsuario *usuario = user->infoUsuario(email); //! hay que hacer delete 2
                        cout << "Datos del usuario:" << endl;
                        cout << *usuario << endl;
                        delete usuario; //! delete 2
                    }
                }
                catch (string email)
                {
                    cout << "El usuario " << email << " no se cuentra en el listado." << endl;
                }
            }
            for (map<string, DTUsuario *>::iterator it = usuarios.begin(); it != usuarios.end(); ++it) //! delete 1
            {
                delete it->second;
            }
            usuarios.clear();
            break;
        }
        case 13: // Consulta de Hostal
        {
            bool bandera = true; // caso error, si el nombre no esta en la coleccion de hostales, empiezo de vuelta
            cin.ignore();
            InterfazHostal *ihostal = fabrica->getInterfazHostal();
            map<string, DTHostal *> hostales = ihostal->obtenerHostales(); //! hay que hacer delete 1
            while (bandera)
            {
                for (map<string, DTHostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it)
                    cout << *it->second << endl;
                cout << "Ingrese el nombre del hostal a consultar: \n";
                string nombre;
                getline(cin, nombre);
                try
                {
                    if (hostales.find(nombre) == hostales.end())
                    {
                        throw nombre;
                    }
                    else
                    {
                        bandera = false;
                        DTHostalExtendido *hostalextend = ihostal->infoHostal(nombre); //! hay que hacer delete 2
                                                                                       //* hay que hacer delete al set<DTCalificacion *>
                                                                                       //* hay que hacer delete al map<int, DTReserva *>
                        cout << "Datos del hostal:" << endl;
                        cout << *hostalextend << endl;
                        set<DTCalificacion *> calif = hostalextend->getCalificaciones(); //! delete 2 calificaciones
                        for (set<DTCalificacion *>::iterator it = calif.begin(); it != calif.end(); ++it)
                            delete *it;
                        map<int, DTReserva *> rese = hostalextend->getReservas(); //! delete 2 reservas
                        for (map<int, DTReserva *>::iterator it = rese.begin(); it != rese.end(); ++it)
                            delete it->second;
                        delete hostalextend; //! fin delete 2
                    }
                }
                catch (string nombre)
                {
                    cout << "El Hostal: " << nombre << " no pertenece a los hostales registrados\n";
                }
            }
            for (map<string, DTHostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it) //! delete 1
                delete it->second;
            hostales.clear();
            break;
        }
        case 14: // Consulta de Reservas.
        {
            bool cond = true;
            InterfazHostal *iHostal = fabrica->getInterfazHostal();
            map<string, DTHostal *> hostales = iHostal->obtenerHostales(); //! hay que hacer delete 1
            string nombreHostal;
            cin.ignore();
            while (cond)
            {
                cout << "Hostales en el sistema: " << endl;
                for (map<string, DTHostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it)
                {
                    cout << *it->second << endl;
                }

                cout << "Ingrese el nombre del hostal a consultar: " << endl;
                getline(cin, nombreHostal);
                try
                {
                    if (hostales.find(nombreHostal) == hostales.end())
                    {
                        throw nombreHostal;
                    }
                    else
                    {
                        cond = false;
                        // Recorro las reservas asociadas al hostal y las devuelvo
                        map<int, DTReserva *> aRetornar = iHostal->obtenerReservas(nombreHostal); //! hay que hacer delete 2
                        cout << "Se listan las reservas vinculadas al hostal: " << endl;

                        if (aRetornar.empty())
                        {
                            cout << "No hay Reservas" << endl;
                        }

                        for (map<int, DTReserva *>::iterator it = aRetornar.begin(); it != aRetornar.end(); ++it)
                        {
                            cout << *it->second << endl;
                        }

                        for (map<int, DTReserva *>::iterator it = aRetornar.begin(); it != aRetornar.end(); ++it) //! delete 2
                        {
                            delete it->second;
                        }
                        aRetornar.clear();
                    }
                }
                catch (string nombreHostal)
                {
                    cout << "El Hostal: " << nombreHostal << " no pertenece a los hostales registrados\n";
                }
            }
            for (map<string, DTHostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it) //! delete 1
            {
                delete it->second;
            }
            hostales.clear();

            break;
        }
        case 15: // Consulta de Estadias
        {
            InterfazHostal *iHostal = fabrica->getInterfazHostal();
            InterfazReserva *iReserva = fabrica->getInterfazReserva();
            InterfazUsuario *iUsuario = fabrica->getInterfazUsuario();
            map<string, DTHostal *> hostales = iHostal->obtenerHostales(); //! hay que hacer delete 1
            string nombreHostal;
            bool bandera = true;
            cin.ignore();
            while (bandera)
            {
                cout << "Seleccione el hostal donde quiere consultar las estadías: " << endl;
                for (map<string, DTHostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it)
                {
                    cout << *it->second << endl;
                }
                cout << "Ingrese el nombre del hostal a consultar: " << endl;
                getline(cin, nombreHostal);
                try
                {
                    if (hostales.find(nombreHostal) == hostales.end())
                    {
                        throw nombreHostal;
                    }
                    else
                    {
                        bandera = false;
                        set<DTEstadia *> estadias = iHostal->obtenerEstadias(nombreHostal); //! hay que hacer delete 2
                        cout << "Se listan las estadías para el hostal: " << endl;
                        DTEstadia *estad;

                        int codigoReserva;
                        bool bandera2 = true;
                        while (bandera2)
                        {
                            //*aca se listan las estadias con la informacion minima
                            //*y luego abajo se usa la sobrecarga en mostrarEstadia(), porque no tiene sentido mostrar la misma informacion 2 veces
                            for (set<DTEstadia *>::iterator it2 = estadias.begin(); it2 != estadias.end(); ++it2)
                            {
                                cout << "Estadia: " << endl;
                                estad = *it2;
                                cout << "Codigo de Reserva: " << estad->getReserva() << endl;
                                cout << "Email del Huesped: " << estad->getHuesped() << endl;
                                cout << endl;
                            }
                            cout << "Ingrese el código de reserva de la estadía a consultar: " << endl;
                            cin >> codigoReserva;
                            map<int, DTReserva *> reservas = iHostal->obtenerReservas(nombreHostal); //! hay que hacer delete 3
                            try
                            {
                                if (reservas.find(codigoReserva) == reservas.end())
                                {
                                    throw codigoReserva;
                                }
                                else
                                {
                                    bandera2 = false;
                                    string emailHues;
                                    bool bandera3 = true;
                                    map<string, DTHuesped *> huespedes = iUsuario->obtenerHuespedes(); //! hay que hacer delete 4
                                    while (bandera3)
                                    {
                                        cout << "Ingrese el email del huesped asociado a la estadía: " << endl;
                                        cin >> emailHues;
                                        try
                                        {
                                            if (huespedes.find(emailHues) == huespedes.end())
                                            {
                                                throw emailHues;
                                            }
                                            else
                                            {
                                                bandera3 = false;
                                                cout << "Se muestra la estadía vinculada al huesped y codigo de reserva ingresados: " << endl;
                                                DTEstadia *estadia = iHostal->mostrarEstadia(emailHues, codigoReserva);
                                                if (estadia != NULL)
                                                {
                                                    cout << *estadia << endl;
                                                }
                                                //*le puse para ingresar 1 y 2 solo para ser consistente
                                                //*con los otros casos que ya hicieron
                                                cout << "¿Desea ver la calificación y su respuesta? (1 = Si/2 = No)" << endl;
                                                int respuesta;
                                                cin >> respuesta;
                                                if (respuesta == 1)
                                                {
                                                    DTCalificacion *aMostrar = iReserva->darCalificacionRespuesta(codigoReserva, emailHues); //! hay que hacer delete 5

                                                    if (aMostrar == NULL)
                                                    {
                                                        cout << "No hay Calificacion" << endl;
                                                    }
                                                    else
                                                    {
                                                        cout << *aMostrar << endl;
                                                        delete aMostrar; //! delete 5
                                                    }
                                                }
                                                cout << "¿Desea ver la información de la reserva asociada a la estadía? (1 = Si/2 = No)" << endl;
                                                int respuesta2;
                                                cin >> respuesta2;
                                                if (respuesta2 == 1)
                                                {
                                                    DTReserva *res;
                                                    res = iHostal->mostrarReserva(nombreHostal, codigoReserva); //! hay que hacer delete 6
                                                    cout << *res << endl;
                                                    delete res; //! delete 6
                                                }
                                            }
                                        }
                                        catch (string emailHues)
                                        {
                                            cout << "el email ingresado " << emailHues << "es incorrecto";
                                        }
                                    }
                                    for (map<string, DTHuesped *>::iterator it = huespedes.begin(); it != huespedes.end(); ++it) //! delete 4
                                    {
                                        delete it->second;
                                    }
                                    huespedes.clear();
                                }
                            }
                            catch (int codigoReserva)
                            {
                                cout << "El codigo de Reserva: " << codigoReserva << " es incorrecto." << endl;
                            }
                            for (map<int, DTReserva *>::iterator it = reservas.begin(); it != reservas.end(); ++it) //! delete 3
                            {
                                delete it->second;
                            }
                            reservas.clear();
                        }
                        for (set<DTEstadia *>::iterator it2 = estadias.begin(); it2 != estadias.end(); ++it2) //! delete 2
                        {
                            delete *it2;
                        }
                        estadias.clear();
                    }
                }
                catch (string nombreHostal)
                {
                    cout << "el Hostal ingresado: " << nombreHostal << " es incorrecto";
                }
            }
            for (map<string, DTHostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it) //! delete 1
            {
                delete it->second;
            }
            hostales.clear();
            break;
        }
        case 16: // Baja de Reserva
        {
            InterfazReserva *ireserva = fabrica->getInterfazReserva();
            InterfazHostal *ihostal = fabrica->getInterfazHostal();

            map<string, DTHostal *> hostales = ihostal->obtenerHostales(); //! hay que hacer delete 1
            bool bandera = 1;
            cin.ignore();
            while (bandera)
            {
                for (map<string, DTHostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it)
                    cout << *it->second << endl;
                cout << "Ingrese el nombre del hostal a consultar: ";
                string nombre;
                getline(cin, nombre);
                try
                {
                    if (hostales.find(nombre) == hostales.end())
                        throw nombre;
                    else
                    {
                        bandera = false;
                        map<int, DTReserva *> aRetornar = ihostal->obtenerReservas(nombre); //! hay  que hacer delete 2
                        ireserva->almacenarNombreHostal(nombre);
                        cout << "Se listan las reservas vinculadas al hostal: " << endl;
                        ireserva->almacenarNombreHostal(nombre); //?alamceno en el controlador el nombre hostal
                        bool bandera2 = 1;
                        while (bandera2)
                        {
                            for (map<int, DTReserva *>::iterator it = aRetornar.begin(); it != aRetornar.end(); ++it)
                                cout << *it->second << endl;
                            cout << "Ingrese el codigo de la reserva a eliminar: ";
                            int numero;
                            cin >> numero;
                            try
                            {
                                if (aRetornar.find(numero) == aRetornar.end())
                                    throw numero;
                                else
                                {
                                    bandera2 = false;
                                    ireserva->identificarReserva(numero);
                                    cout << "Ingrese 1 para confirmar, 2 para cancelar: ";
                                    cin >> numero;
                                    if (numero == 1) {
                                        ireserva->confirmarBajaReserva();
                                        cout << "Baja de reserva realizada." << endl;
                                    }
                                    else {
                                        ireserva->cancelarBajaReserva();
                                        cout << "Baja de reserva cancelada." << endl;
                                    }
                                }
                            }
                            catch (int numero)
                            {
                                cout << "El numero de la reserva " << numero << " es incorrecto";
                            }
                        }
                        for (map<int, DTReserva *>::iterator it = aRetornar.begin(); it != aRetornar.end(); ++it) //! delete 2
                            delete it->second;
                        aRetornar.clear();
                    }
                }
                catch (string nombre)
                {
                    cout << "El nombre del Hostal " << nombre << " es incorrecto";
                }
            }
            for (map<string, DTHostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it) //! delete 1
                delete it->second;
            hostales.clear();
            break;
        }
        case 17: // Suscribirse a Notificaciones
        {
            InterfazUsuario *iUsuario = fabrica->getInterfazUsuario();
            map<string, DTEmpleado *> colEmpleados = iUsuario->obtenerEmpleados(); //! hay que hcaer delete 1

            string emailEmpleado;
            bool condition = true;
            while (condition)
            {
                cout << "Empleados en el sistema:" << endl;
                for (map<string, DTEmpleado *>::iterator it = colEmpleados.begin(); it != colEmpleados.end(); ++it)
                    cout << *it->second << endl;
                cout << "Ingrese el mail del empleado a suscribir: ";
                cin >> emailEmpleado;
                try
                {
                    if (colEmpleados.find(emailEmpleado) == colEmpleados.end())
                        throw emailEmpleado;
                    else
                    {
                        condition = false;
                        iUsuario->suscribirse(emailEmpleado);
                        cout << "El empleado se suscribio correctamente." << endl;
                    }
                }
                catch (string emailEmpleado)
                {
                    cout << "El empleado " << emailEmpleado << " no se encuentra en la lista." << endl;
                }
            }
            for (map<string, DTEmpleado *>::iterator it = colEmpleados.begin(); it != colEmpleados.end(); ++it) //! delete 1
                delete it->second;
            break;
        }
        case 18: // Consulta de Notificaciones
        {
            InterfazUsuario *iUsuario = fabrica->getInterfazUsuario();
            map<string, DTEmpleado *> colEmpleados = iUsuario->obtenerEmpleados(); //! Hay que hacer delete 1
            string emailEmpleado;
            bool condition = true;
            while (condition)
            {
                cout << "Empleados en el sistema:" << endl;
                for (map<string, DTEmpleado *>::iterator it = colEmpleados.begin(); it != colEmpleados.end(); ++it)
                    cout << *it->second << endl;
                cout << "Ingrese el mail del empleado para consultar sus notificaciones: ";
                cin >> emailEmpleado;
                try
                {
                    if (colEmpleados.find(emailEmpleado) == colEmpleados.end())
                        throw emailEmpleado;
                    else
                    {
                        condition = false;
                        set<Notificacion *> colNoti = iUsuario->obtenerNotificaciones(emailEmpleado);
                        cout << "Notificaciones del empleado: ";
                        if (colNoti.empty())
                            cout << "No hay." << endl;
                        else
                        {
                            cout << endl;
                            for (set<Notificacion *>::iterator it = colNoti.begin(); it != colNoti.end(); ++it)
                                cout << **it << endl;
                        }
                        iUsuario->eliminarNotificaciones(emailEmpleado);
                    }
                }
                catch (string emailEmpleado)
                {
                    cout << "El empleado " << emailEmpleado << " no se encuentra en la lista." << endl;
                }
            }
            for (map<string, DTEmpleado *>::iterator it = colEmpleados.begin(); it != colEmpleados.end(); ++it) //! delete 1
                delete it->second;
            colEmpleados.clear();
            break;
        }
        case 19: // Eliminar Suscripción
        {
            InterfazUsuario *iUsuario = fabrica->getInterfazUsuario();
            map<string, DTEmpleado *> colEmpleados = iUsuario->obtenerEmpleados(); //! hay que hacer delete 1
            string emailEmpleado;
            bool condition = true;
            while (condition)
            {
                cout << "Empleados en el sistema:" << endl;
                for (map<string, DTEmpleado *>::iterator it = colEmpleados.begin(); it != colEmpleados.end(); ++it)
                    cout << *it->second << endl;
                cout << "Ingrese el mail del empleado a desuscribir: ";
                cin >> emailEmpleado;
                //! falta verificar el empleado esté suscrito, sino, se rompe
                try
                {
                    if (colEmpleados.find(emailEmpleado) == colEmpleados.end())
                        throw emailEmpleado;
                    else
                    {
                        condition = false;
                        iUsuario->eliminarSuscripcion(emailEmpleado); //!Revisar, al probarlo borra a el empleado de la listaEmpleados(¿Delete?)
                        cout << "Se eliminó la suscripción correctamente" << endl;
                    }
                }
                catch (string emailEmpleado)
                {
                    cout << "El empleado " << emailEmpleado << " no se encuentra en la lista." << endl;
                }
            }
            for (map<string, DTEmpleado *>::iterator it = colEmpleados.begin(); it != colEmpleados.end(); ++it) //! delete 1
                delete it->second;
            colEmpleados.clear();
            break;
        }
        case 20: // Modificar Fecha del Sistema
        {
            date fechaCI;
            int num;
            cout << "Ingresar el dia del check in: ";
            cin >> num;
            fechaCI.setDia(num);
            cout << "Ingresar el mes del check in: ";
            cin >> num;
            fechaCI.setMes(num);
            cout << "Ingresar el año del check in: ";
            cin >> num;
            fechaCI.setAnio(num);
            cout << "Ingresar la hora del check in: ";
            cin >> num;
            fechaCI.setHora(num);
            InterfazFecha *iFecha = fabrica->getInterfazFecha();
            iFecha->actualizarFecha(fechaCI);
            cout << "Fecha del sistema actualizada." << endl;
            break;
        }
        }
    } while (opcion != 0);
    return 0;
}
