//***************************************************************************
// File:   mainLab.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   18/02/2026
// Coms:   Programa del laberinto para la práctica 4 de la asignatura
//***************************************************************************

#include <iostream>
#include <cstring>
#include "laberinto.hpp"
#include <unistd.h> // para "usleep"

using namespace std;

void inicioPrograma(int argc, char* argv[]);

int main(int argc, char* argv[]){

	inicioPrograma(argc,argv);
	/*
	string ruta = argv[1];
	
	Laberinto lab;
	cargarLaberinto(cargarLaberinto,lab);
	*/
	
	return 0;
}

void cargarLaberintoDesdeDir(char* argv[], Laberinto lab){

	cargarLaberinto(argv[1],lab);
			
	cout << "Laberinto cargado desde: " << argv[1] << endl;
	mostrarLaberinto(lab);

	bool encontrado = false;
	buscarCamino(lab, encontrado);

	if (encontrado) {
		   cout << "\n¡Camino encontrado!" << endl;
	} else {
		   cout << "\nNo hay salida posible." << endl;
	}
	// Mostramos cómo ha quedado marcado el mapa
	mostrarLaberinto(lab);
	
}

void generarLaberinto(Laberinto lab){
	string alto,ancho,densidad;
			
	cout << "Altura: ";
	cin >> alto;
			
    int altura = stoi(alto);
    		
	cout << "Anchura: ";
	cin >> ancho;
			
	int anchura = stoi(ancho);
			
	cout << "Densidad: ";
	cin >> densidad;
			
	double dens = stod(densidad);
			
	lab.alto=altura;
	lab.ancho=anchura;
			
	generarLaberinto(lab, dens, 0, 0);
			
	cout << "Laberinto generado (" << lab.alto << "x" << lab.ancho 
         		<< "), Densidad: " << dens << endl;
	mostrarLaberinto(lab);

	bool encontradoAleatorio = false;
	buscarCamino(lab, encontradoAleatorio);

	if (encontradoAleatorio) {
		cout << "\n¡Camino encontrado en el aleatorio!" << endl;
	} else {
		cout << "\nEl ratón se quedó atrapado." << endl;
	}
	mostrarLaberinto(lab);
}

void inicioPrograma(int argc, char* argv[]){

	string respuesta;

	do{
		cout << "=== BIENVENIDO A LABERINTO ===\n";
		
		cout << "\n---> 1. Cargar laberinto\n---> 2. Generar laberinto\n\n 0. Salir\n" << endl;
		
		cout << "Escribe el número: ";
		cin >> respuesta;
		
		Laberinto lab;
		
		if(respuesta=="1"){ //Cargar laberinto
		
			cargarLaberintoDesdeDir(argv,lab);
			break;
			
		}else if(respuesta =="2"){	//Generar laberinto
			
			generarLaberinto(lab);
			break;
		
		}else if(respuesta == "0"){	//Salir
			cout << "Hasta la próxima :))" << endl;
		}else{
			cout << "Error! Escribe una opción correcta :(" << endl;
		}
		
    }while(respuesta=="1"||respuesta=="2");
    
    
}

