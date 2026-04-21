//***************************************************************************
// File:   pruebasLaberinto.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   18/02/2026
// Coms:   Implementación del tipo "Laberinto" para la práctica 4 de la asignatura
//***************************************************************************

#include <iostream>
#include <cstring>
#include "laberinto.hpp"
#include <unistd.h> // para "usleep"

using namespace std;

int main(){
	// =======================================================
    // PRUEBA 1: CARGAR LABERINTO DESDE FICHERO
    // =======================================================
        cout << "--- PRUEBA 1: CARGAR LABERINTO ---" << endl;
        Laberinto labFichero;
        string ruta="datos/lab1.txt"; 
        
        cargarLaberinto(ruta, labFichero);
        
        cout << "Laberinto cargado desde: " << ruta << endl;
        mostrarLaberinto(labFichero);

        bool encontrado = false;
        buscarCamino(labFichero, encontrado);

        if (encontrado) {
            cout << "\n¡Camino encontrado!" << endl;
        } else {
            cout << "\nNo hay salida posible." << endl;
        }
        // Mostramos cómo ha quedado marcado el mapa
        mostrarLaberinto(labFichero);
        cout << "----------------------------------\n\n";

    // =======================================================
    // PRUEBA 2: GENERAR LABERINTO ALEATORIO
    // =======================================================
    cout << "--- PRUEBA 2: LABERINTO ALEATORIO ---" << endl;
    Laberinto labAleatorio;
    // Asignamos unas dimensiones de prueba
    labAleatorio.alto = 15;
    labAleatorio.ancho = 30;
    double densidad = 0.3; // 30% de muros

    // Llamamos a tu función recursiva empezando en la fila 0, columna 0
    generarLaberinto(labAleatorio, densidad, 0, 0);

    cout << "Laberinto generado (" << labAleatorio.alto << "x" << labAleatorio.ancho 
         << "), Densidad: " << densidad << endl;
    mostrarLaberinto(labAleatorio);

    bool encontradoAleatorio = false;
    buscarCamino(labAleatorio, encontradoAleatorio);

    if (encontradoAleatorio) {
        cout << "\n¡Camino encontrado en el aleatorio!" << endl;
    } else {
        cout << "\nEl ratón se quedó atrapado." << endl;
    }
    mostrarLaberinto(labAleatorio);
	return 0;
}
