//***************************************************************************
// File:   laberinto.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   18/02/2026
// Coms:   Implementación del tipo "Laberinto" para la práctica 4 de la asignatura
//***************************************************************************

#include "laberinto.hpp"
#include <unistd.h> // para "usleep"

//*************************************************************************
// Encontrar un camino en el laberinto
//*************************************************************************

// Función auxiliar que no va en el .hpp, solo en tu .cpp
void explorar(Laberinto& lab, int f, int c, bool &encontrado) {
	// 0. Comprobar si hemos encontrado la salida en otra rama de recursividad
	if(encontrado){
		return;
	}
	
    // 1. Caso Base de FRACASO (limites del laberinto)
    if (f < 0 || f >= lab.alto || c < 0 || c >= lab.ancho || lab.mapa[f][c] != LIBRE) {
        return; // Terminamos esta rama sin hacer nada
    }
    
    // 2. Caso Base de ÉXITO (Llegamos a la meta)
    if (f == lab.alto - 2 && c == lab.ancho - 2) {
        lab.mapa[f][c] = CAMINO; // Marcamos la casilla final
        encontrado = true;       // ¡Avisamos a las demás llamadas que ya terminamos!
        return; 
    }
    
    lab.mapa[f][c]=CAMINO;
    
    explorar(lab,f+1,c,encontrado);	//Abajo
    explorar(lab,f-1,c,encontrado);	//Arriba
    explorar(lab,f,c+1,encontrado);	//Derecha
    explorar(lab,f,c-1,encontrado);	//Izda
    
    // Backtracking
    // Si después de mirar a los 4 lados no encontramos la salida, significa que este camino no era el correcto. Lo desmarcamos.
    if (!encontrado) {
        lab.mapa[f][c] = IMPOSIBLE;
    }
}

void buscarCamino(Laberinto& lab, bool &encontrado) {
    encontrado = false;
    // El enunciado dice que empieza en (1,1)
    explorar(lab, 1, 1, encontrado); 
}

//*************************************************************************
// Generar el laberinto
//*************************************************************************

void cargarLaberinto(const string nombFichero, Laberinto& lab) {

    // COMPLETAR
}


void generarLaberinto(Laberinto &lab, double densidad, int fila, int col) {

    // COMPLETAR
}

//*************************************************************************
// Visualizar el camino encontrado
//*************************************************************************

// Pre:   "lab" es un laberinto correcto
// Post:  Se ha mostrado el laberinto por la salida estándar
// Coms:  Versión iterativa
void mostrarLaberinto(const Laberinto& lab) {
    for (int i = 0; i < lab.alto; i++) {
        for (int j = 0; j < lab.ancho; j++) {
            cout << lab.mapa[i][j];
        }
        // Al acabar una fila, se cambia de línea
        cout << endl;
    }
}


// Pre:  "lab" es un laberinto correcto
// Post:  Se ha mostrado el laberinto por la salida estándar
// Coms:  Versión recursiva
void mostrarLaberintoR(const Laberinto& lab) {

    // COMPLETAR
}
