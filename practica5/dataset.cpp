//*****************************************************************
// File:   dataset.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   Marzo 2026
// Coms:   Fichero de implementación del módulo de dataset
//*****************************************************************


#include "dataset.hpp"

#include <iostream>
#include <iomanip>
#include <string> 
#include <vector> 

using namespace std; 

// PRE: fichero existe
// POST: dataset=[entrada_0, ..., entrada_n-1] AND 
//          ALL entrada_i.id = i (pos) 
void cargaDataset(string fichero, Dataset &dataset){
/*
	if(fichero==""){
        cerr << "Error. Nombre erroneo del fichero o dir." << endl;
        return; // Salimos si hay error
	}
	
	//	Abrimos el fichero
    ifstream fich(fichero);

    // Comprobamos si se ha abierto correctamente
    if (!fich) {
        cerr << "Error al abrir el archivo." << endl;
        return; // Salimos si hay error
    }
    */
    
}

// PRE: dataset=[entrada_0, ..., entrada_n-1] AND ent.id = n
// POST: dataset=[entrada_0, ..., entrada_n-1, ent]  
void anadirEntrada(Dataset &dataset, const EntradaDataset &ent){
}

// PRE: 0 <= id < #dataset
// POST: accedeId(id) = dataset[id]
EntradaDataset accedeId(const Dataset &dataset, const int id){
	EntradaDataset e;
	return e;
}

// PRE: True
// POST: muestra por pantalla los contenidos de ent
void muestraEntrada(const EntradaDataset &ent){
}

// PRE: 0 <= id < #dataset
// POST: muestra por pantalla los contenidos de dataset[id]
void muestraEntrada(const Dataset &dataset, int id){
}
