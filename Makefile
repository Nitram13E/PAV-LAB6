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
	  src/Class/Sesion.o \
	  \
	  src/Controller/CAsistenciaClaseVivo.o \
	  src/Controller/CAltaAsignatura.o \
	  src/Controller/CIniciarSesion.o \
	  src/Controller/CListadoClases.o \
	  \
	  src/Handlers/ManejadorAsignatura.o \
	  src/Handlers/ManejadorClase.o \
	  src/Handlers/ManejadorPerfil.o \
	  \
	  src/DataTypes/DtFecha.o \
	  src/DataTypes/DtLog.o \
	  src/DataTypes/DtAsistir.o \
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
	g++ $(obj) -o $(exec)
	@ echo "\n\nEjecutar con: ./$(exec)\n\n"

$(obj): %.o: %.cpp

clean:
	@ rm -f $(obj)
	@ echo "archivos de compilacion eliminados."