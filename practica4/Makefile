#------------------------------------------------------------------------------
# File:   Makefile
# Author: Programación II-Unizar
# Date:   18/02/2026
# Coms:   Ejemplo de Makefile para la práctica 4 de Programación II
#------------------------------------------------------------------------------

#---------------------------------------------------------
# Definición de macros
CC = g++                   # compilador
CPPFLAGS = -std=c++11      # opciones de compilación
RM = rm -f                 # comando para borrar ficheros

all: mainLab pruebasLaberinto
#-----------------------------------------------------------
# Compilacion
pruebasLaberinto.o: pruebasLaberinto.cpp
	${CC} -c pruebasLaberinto.cpp -I ../funciones ${CPPFLAGS}
laberinto.o: laberinto.cpp laberinto.hpp
	${CC} -c laberinto.cpp -I ../funciones ${CPPFLAGS}
mainLab.o: mainLab.cpp
	${CC} -c mainLab.cpp -I ../funciones ${CPPFLAGS}

# Linkado
pruebasLaberinto: pruebasLaberinto.o laberinto.o 
	${CC} pruebasLaberinto.o laberinto.o -o pruebasLaberinto
	
mainLab: mainLab.o laberinto.o
	${CC} mainLab.o laberinto.o -o mainLab

#-----------------------------------------------------------	
# LIMPIEZA de todo lo generado. Ojo: se borrarán sin preguntar
clean:
	${RM} *.o mainLab pruebasLaberinto
