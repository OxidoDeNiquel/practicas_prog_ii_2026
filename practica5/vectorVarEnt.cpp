//*****************************************************************
// File:   vectorVarEnt.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   Marzo 2026
// Coms:   Fichero de implementación del módulo de biblioteca vectorEnt
//*****************************************************************

#include "vectorVarEnt.hpp"

#include <iostream>
#include <string> 
#include <vector> 

using namespace std; 

// PRE: True
// POST: estaVacio(v) = TRUE
void vaciar(VectorVarEnt &v){
	v.clear();
}

// PRE:  v = [x_0, ...., x_n] 
// POST: v = [x_0, ...., x_n, dato]
void anadirFinal(VectorVarEnt &v, int dato){
	v.push_back(dato);
}

// Función auxiliar
bool busquedaBinariaRecursiva(const VectorVarEnt &v, int dato, int p, int f) {
    // Caso base: el rango de búsqueda se ha cruzado, el elemento no existe
    if (p>f) {
        return false;
    }

    // Calculamos la posición central
    int medio =(f-p)/2;
    int valorMedio = accedePos(v, medio);

    if (valorMedio == dato) {
        return true;
    }
    else if (valorMedio > dato) {
        return busquedaBinariaRecursiva(v, dato, p, medio - 1);
    } 
    else {
        return busquedaBinariaRecursiva(v, dato, medio + 1, f);
    }
}
// PRE: v1 = [x_0, ...., x_n] AND v2 = [y_0, ...., y_m]
// POST: elementosCompartidos(v1,v2) = newV AND 
//      (x in v1 AND x in v2) <=> x in newV
VectorVarEnt elementosCompartidos(const VectorVarEnt &v1, const VectorVarEnt &v2){
	VectorVarEnt vectElemCompart;
    
    // Posible caso base
    if (estaVacio(v1) || estaVacio(v2)) {
        return vectElemCompart;
    }

    for(int i = 0; i < tamano(v1); i++){
        int valorV1 = accedePos(v1, i);
        
        // Aplicamos Divide y Vencerás para buscar valorV1 en v2
        bool encontrado = busquedaBinariaRecursiva(v2, valorV1, 0, tamano(v2) - 1);
        
        // Si la búsqueda binaria devuelve true, esta en ambos
        if(encontrado){
            anadirFinal(vectElemCompart, valorV1);
        }
    }
    
    return vectElemCompart;
}


// PRE: True
// POST: estaVacio(v) = (#v = 0)
bool estaVacio(const VectorVarEnt &v){
	return v.size()==0;
}

// PRE: True
// POST: tamano(v) = #v
int tamano(const VectorVarEnt &v){
	return v.size();
}

void muestraVectorAux(const VectorVarEnt &v, int i){
	if(i==0){
		cout << v.at(i) << endl;
	}else{
		muestraVectorAux(v,i-1);
		cout << v.at(i) << endl;
	}
}

// PRE: True
// POST: Muestra por pantalla los contenidos del vector 
void muestraVector(const VectorVarEnt &v){
	if (!estaVacio(v)) { 
        muestraVectorAux(v, v.size() - 1);
    } else {
        cout << "Vector vacío." << endl;
    }
}

// PRE: 0 <= i < #v
// POST: accedePos(v,i) = v[i]
int accedePos(const VectorVarEnt &v, int i){
	return v.at(i);
}
