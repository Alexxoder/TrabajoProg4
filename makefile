TARGET = $(BINDIR)/ejecutable

#lsita de todos los .o  y se le agrega la variable
#de la carpeta "/"archivo.o donde queremos incluir
OBJS   = $(OBJDIR)/main.o $(OBJDIR)/date.o $(OBJDIR)/DTHabitacion.o $(OBJDIR)/DTHuesped.o \
		 $(OBJDIR)/DTReserva.o \
		 $(OBJDIR)/Habitacion.o $(OBJDIR)/Huesped.o $(OBJDIR)/Reserva.o $(OBJDIR)/ReservaGrupal.o \
		 $(OBJDIR)/ReservaIndividual.o $(OBJDIR)/Fabrica.o $(OBJDIR)/Calificacion.o \
		 $(OBJDIR)/ControladorHostal.o $(OBJDIR)/ControladorReserva.o $(OBJDIR)/ControladorUsuario.o \
		 $(OBJDIR)/DTCalificacion.o $(OBJDIR)/DTEmpleado.o $(OBJDIR)/DTEstadia.o \
		 $(OBJDIR)/DTHostal.o $(OBJDIR)/DTUsuario.o $(OBJDIR)/Empleado.o $(OBJDIR)/Estadia.o \
		 $(OBJDIR)/FechaSistema.o $(OBJDIR)/Hostal.o $(OBJDIR)/Usuario.o $(OBJDIR)/Notificacion.o \
		

#posicion relativa de la ubicacion del makefile
INCDIR = include
BINDIR = bin
OBJDIR = obj
SRCDIR = src
CFLAGS = -Wall -Werror -I$(INCDIR) -g

#regla : dependencias
#->(tab) accion
# el mkdir -p me crea la carpeta en caso de que no haya
# la segunda accion es la compilacion, g++ los flags, los .o -o el nombre del ejecutable
$(TARGET): $(OBJS)
	mkdir -p $(BINDIR)
	g++ $(CFLAGS) $(OBJS) -o $(TARGET)

#le indico donde se generan los .o en el directorio obj
#regla patron $< $@ 10.5.2 Pattern Rule Examples de la doc de GNU Makefile
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	g++ -c -MD $(CFLAGS) $< -o $@

-include $(OBJDIR)/*.d

clean: 
	rm -r $(OBJDIR) $(BINDIR)