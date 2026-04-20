//*****************************************************************
// File:   vectorVarEnt.hpp
// Author: Programación II. Universidad de Zaragoza
// Date:   Marzo 2026
// Coms:   Fichero de interfaz del módulo de biblioteca vectorEnt
//*****************************************************************

#ifndef VECTORVARENT_HPP
#define VECTORVARENT_HPP

#include <string> 
#include <vector> 

using namespace std; 

typedef vector<int> VectorVarEnt;  

// PRE: True
// POST: estaVacio(v) = TRUE
void vaciar(VectorVarEnt &v);

// PRE:  v = [x_0, ...., x_n] 
// POST: v = [x_0, ...., x_n, dato]
void anadirFinal(VectorVarEnt &v, int dato); 

// PRE: v1 = [x_0, ...., x_n] AND v2 = [y_0, ...., y_m]
// POST: elementosCompartidos(v1,v2) = newV AND 
//      (x in v1 AND x in v2) <=> x in newV
VectorVarEnt elementosCompartidos(const VectorVarEnt &v1, const VectorVarEnt &v2); 

// PRE: True
// POST: estaVacio(v) = (#v = 0)
bool estaVacio(const VectorVarEnt &v);

// PRE: True
// POST: tamano(v) = #v
int tamano(const VectorVarEnt &v); 

// PRE: True
// POST: Muestra por pantalla los contenidos del vector 
void muestraVector(const VectorVarEnt &v); 

// PRE: 0 <= i < #v
// POST: accedePos(v,i) = v[i]
int accedePos(const VectorVarEnt &v, int i); 

#endif
