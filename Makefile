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
	  src/Handlers/ManejadorAsignatura.o \
	  src/Handlers/ManejadorClase.o \
	  src/Handlers/ManejadorPerfil.o \
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
	  src/DataTypes/DtParticipacion.o
	  
all: $(obj)
	@ mkdir -p ./obj
	@ mv $(obj) ./obj
	g++ obj/*.o -o $(exec)
	@ echo "\nEjecutar con: ./$(exec)"

$(obj): %.o: %.cpp

debug:
	g++ -g -c src/DataTypes/*.cpp
	g++ -g -c src/Class/*.cpp
	g++ -g -c src/main.cpp

clean:
	@ rm -f obj/*.o $(exec)
	@ rm -f ./*.o
	@ echo "archivos de compilacion eliminados."