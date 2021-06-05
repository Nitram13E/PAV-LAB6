exec = exec #Nombre del archivo ejecutable

obj = src/main.o \
	  \
	  src/Class/Asignatura.o \
	  src/Class/Clase.o \
	  src/Class/Docente.o \
	  src/Class/Estudiante.o \
	  src/Class/Participacion.o \
	  src/Class/Perfil.o \
	  src/Class/Rol.o \
	  src/Class/AsisteVivo.o \
	  src/Class/AsisteDiferido.o \
	  src/Class/Monitoreo.o \
	  src/Class/Practico.o \
	  src/Class/Teorico.o \
	  \
	  src/Controller/CAltaAsignatura.o \
	  \
	  src/Handlers/ManejadorAsignatura.o \
	  src/Handlers/ManejadorClase.o \
	  src/Handlers/ManejadorPerfil.o \
	  \
	  src/Controller/CAsistenciaClaseVivo.o\
	  \
	  src/DataTypes/DtFecha.o \
	  src/DataTypes/DtLog.o \
	  src/DataTypes/DtPerfil.o \
	  src/DataTypes/DtTimeStamp.o \
	  src/DataTypes/DtInstanciaClase.o \
	  src/DataTypes/DtAsignatura.o \
	  src/DataTypes/DtInfoClase.o \
	  src/DataTypes/DtInfoTeorico.o \
	  src/DataTypes/DtInfoMonitoreo.o \
	  src/DataTypes/DtIniciarClase.o \
	  src/DataTypes/DtIniciarClaseFull.o \
	  src/DataTypes/DtIniciarMonitoreo.o \
	  src/DataTypes/DtParticipacion.o \
	  src/DataTypes/DtAsistir.o 
	  
all: $(obj)
	g++ $(obj) -o $(exec)
	@ echo "\n\nEjecutar con: ./$(exec)\n\n"

$(obj): %.o: %.cpp

<<<<<<< HEAD
debug:
	g++ -g -c src/DataTypes/*.cpp
	g++ -g -c src/Class/*.cpp
	g++ -g -c src/Controller/*.cpp
	g++ -g -c src/Handlers/*.cpp
	g++ -g -c src/main.cpp

=======
>>>>>>> 9d7a712e4fe0cc9be9c439bb8dfe9395aa1d2ec3
clean:
	@ rm -f $(obj)
	@ echo "archivos de compilacion eliminados."