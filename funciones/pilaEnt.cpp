//*****************************************************************
// File:   pilaEnt.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   09/03/2026
// Coms:   Fichero de código del módulo de biblioteca pilaEnt
//*****************************************************************

#ifndef PILAENT_HPP
#define PILAENT_HPP
#include "pilaEnt.hpp"

// Pre:  ---
// Post: p = []
void vaciar(PilaEnt &p){
	p.cima=0;
}

// Pre:  p = [d_1, d_2, ..., d_K] AND K >= 0 AND K < DIM
// Post: p = [d_1, d_2, ..., d_K, nuevo]
void apilar(PilaEnt &p, const int nuevo){
	p.datos[p.cima]=nuevo;
	p.cima++;
}

// Pre:  p = [d_1, d_2, ...,d_(K-1), d_K] AND K > 0
// Post: p = [d_1, d_2, ..., d_(K-1)]
void desapilar(PilaEnt &p){
	p.cima--;
}
