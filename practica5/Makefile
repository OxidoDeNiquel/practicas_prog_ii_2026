#------------------------------------------------------------------------------
# File:   Makefile
# Author: Programación II-Unizar
# Date:   20/04/2026
# Coms:   Makefile para la práctica 5 de Programación II
#------------------------------------------------------------------------------

#---------------------------------------------------------
# Definición de macros
CC = g++                   # compilador
CPPFLAGS = -std=c++11        # opciones de compilación
RM = rm -f                 # comando para borrar ficheros

all: tpb pruebaVectores pruebasDataset pruebasIndiceInvertido
#-----------------------------------------------------------
# Compilación de objetos

vectorVarEnt.o: vectorVarEnt.cpp vectorVarEnt.hpp
	${CC} -c vectorVarEnt.cpp ${CPPFLAGS}

dataset.o: dataset.cpp dataset.hpp
	${CC} -c dataset.cpp ${CPPFLAGS}

indiceInvertido.o: indiceInvertido.cpp indiceInvertido.hpp vectorVarEnt.hpp
	${CC} -c indiceInvertido.cpp ${CPPFLAGS}

tpb.o: tpb.cpp dataset.hpp indiceInvertido.hpp vectorVarEnt.hpp
	${CC} -c tpb.cpp ${CPPFLAGS}

pruebaVectores.o: pruebaVectores.cpp
	${CC} -c pruebaVectores.cpp ${CPPFLAGS}
	
pruebasDataset.o: pruebasDataset.cpp
	${CC} -c pruebasDataset.cpp ${CPPFLAGS}
	
pruebasIndiceInvertido.o: pruebasIndiceInvertido.cpp
	${CC} -c pruebasIndiceInvertido.cpp ${CPPFLAGS}

#-----------------------------------------------------------
# Linkado
tpb: tpb.o dataset.o indiceInvertido.o vectorVarEnt.o 
	${CC} tpb.o dataset.o indiceInvertido.o vectorVarEnt.o -o tpb

pruebaVectores: pruebaVectores.o vectorVarEnt.o
	${CC} pruebaVectores.o vectorVarEnt.o -o pruebaVectores
	
pruebasDataset: pruebasDataset.o dataset.o
	${CC} pruebasDataset.o dataset.o -o pruebasDataset
	
pruebasIndiceInvertido: pruebasIndiceInvertido.o indiceInvertido.o
	${CC} pruebasIndiceInvertido.o indiceInvertido.o -o pruebasIndiceInvertido
#-----------------------------------------------------------    
# LIMPIEZA de todo lo generado
clean:
	${RM} *.o tpb pruebaVectores pruebasDataset pruebasIndiceInvertido
