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
	g++ *.o -g -o $(exec)

clean:
	@ rm -f obj/*.o $(exec)
	@ echo "archivos de compilacion eliminados."