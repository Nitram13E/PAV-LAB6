exec = exec #Nombre del archivo ejecutable

obj = src/main.o \
	  \
	  src/DataTypes/DtFecha.o \
	  src/DataTypes/DtLog.o \
	  src/DataTypes/DtPerfil.o \
	  src/DataTypes/DtTimeStamp.o \
	  src/DataTypes/DtInstanciaClase.o 

all: $(obj)
	@ mkdir -p ./obj
	@ mv $(obj) ./obj
	g++ obj/*.o -g -o $(exec)
	@ echo "\nEjecutar con: ./$(exec)"

$(obj): %.o: %.cpp

debug:
	g++ *.o -g -o $(exec)

clean:
	@ rm -f obj/*.o $(exec)
	@ echo "archivos de compilacion eliminados."