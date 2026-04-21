//***************************************************************************
// File:   laberinto.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   18/02/2026
// Coms:   Implementación del tipo "Laberinto" para la práctica 4 de la asignatura
//***************************************************************************

#include "laberinto.hpp"
#include <unistd.h> // para "usleep"
#include <cstdlib>
#include <fstream>

//*************************************************************************
// Encontrar un camino en el laberinto
//*************************************************************************

// Función auxiliar que no va en el .hpp, solo en tu .cpp
void explorar(Laberinto& lab, int f, int c, bool &encontrado) {
	// Comprobar si hemos encontrado la salida en otra rama de recursividad
	if(encontrado){
		return;
	}
	
    // Caso Base de FRACASO (limites del laberinto)
    if (f < 0 || f >= lab.alto || c < 0 || c >= lab.ancho || lab.mapa[f][c] != LIBRE) {
        return; // Terminamos esta rama sin hacer nada
    }
    
    // Caso Base de ÉXITO (Llegamos a la meta)
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
	//	Abrimos el fichero
    ifstream fichero(nombFichero);

    // Comprobamos si se ha abierto correctamente
    if (!fichero) {
        cerr << "Error al abrir el archivo." << endl;
        return; // Salimos si hay error
    }
    
    string lineaActual;
    int contadorFilas = 0;

    // Leemos línea por línea hasta que no haya más
    while (getline(fichero, lineaActual)) {
        
        lab.ancho = lineaActual.length(); 

        // Recorremos la línea carácter por carácter con un for
        for (int i = 0; i < lab.ancho; i++) {
            
            char letra = lineaActual[i]; 
            
            // Validamos si la letra es uno de los caracteres permitidos
			if (letra == LIBRE || letra == MURO || letra == CAMINO || letra == IMPOSIBLE) {
				lab.mapa[contadorFilas][i] = letra;
			}
        }
        
        // Pasamos a la siguiente fila
        contadorFilas++;
    }
    
    lab.alto=contadorFilas;

    // Cerramos el fichero
    fichero.close();
}


double randDouble(const double a, const double b){
	return a + ((double)rand()/RAND_MAX)*(b-a);
}

void generarLaberinto(Laberinto &lab, double densidad, int fila, int col) {
	double x = randDouble(0.0,1.0);
	
	if(fila==lab.alto) return;	//Caso Base
	
	if (fila == 0 || fila == lab.alto - 1 || col == 0 || col == lab.ancho - 1) {
        // 1. Bordes exteriores: SIEMPRE MURO
        lab.mapa[fila][col] = MURO;
        
    } else if ((fila == 1 && col == 1) || (fila == lab.alto - 2 && col == lab.ancho - 2)) {
        // 2. Casillas de Inicio y Meta: SIEMPRE LIBRES
        lab.mapa[fila][col] = LIBRE;
        
    } else {
    
    	//Procesar la casilla actual
		if(x<=densidad){
			lab.mapa[fila][col]=MURO;
		}else{
			lab.mapa[fila][col]=LIBRE;
		}
    
    }
	
	if (col < lab.ancho - 1) {
        // Si no he llegado al final de la fila, avanzo una columna a la derecha
        generarLaberinto(lab, densidad, fila, col + 1);
    } else {
        // Si ya llegué al final de la fila, salto a la fila de abajo y vuelvo a la columna 0
        generarLaberinto(lab, densidad, fila + 1, 0);
    }
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
        
        cout << endl;
    }
}


// Pre:  "lab" es un laberinto correcto
// Post:  Se ha mostrado el laberinto por la salida estándar
// Coms:  Versión recursiva
void mostrarLaberintoR(const Laberinto& lab) {

    // COMPLETAR
}
