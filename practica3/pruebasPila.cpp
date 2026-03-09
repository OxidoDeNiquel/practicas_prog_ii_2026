//*****************************************************************
// File:   pruebasPila.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   18/02/2026
// Coms:   Programa pruebasPila.cpp de prueba del trabajo con pilas
//         de datos enteros y del comportamiento de las funciones
//         definidas en el fichero "funcionesPilaEnt.hpp"
//*****************************************************************

#include <iostream>
#include <cstring>
#include "funcionesPilaEnt.hpp"

using namespace std;


// Programa de prueba que ilustra el trabajo con pilas de datos de enteros
int main() {
    // Define una pila de datos, P, que almacena datos de tipo 'int'
    PilaEnt P;

    // Vacía la pila P
    vaciar(P);
/*
    // PRIMOS almacena los números primeros menores que 100
    const int PRIMOS[] = {
        2,  3,  5,  7, 11, 13, 17, 19, 23, 29,
        31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
        73, 79, 83, 89, 97
    };

    // Apila en P los NUM primeros números primos
    const int NUM = 15;
    for (int i = 1; i <= NUM; ++i) {
        apilar(P, PRIMOS[i-1]);
    }

    // Muestra por pantalla el contenido de P
    cout << "Se han apilado los " << numDatos(P)
         << " primeros numeros primos:" << endl << endl;
    mostrar(P);

    // Muestra por pantalla los datos de P en orden inverso
    cout << "Y esta es la pila invertida:" << endl << endl;
    mostrarInvertida(P);

    // Incluir más llamadas a funciones para comprobar su funcionamiento
*/

	if(P.cima==0){
		cout << "Ok. vaciar() funciona"<< endl;
	}
    return 0;
}
