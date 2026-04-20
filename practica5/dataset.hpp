//*****************************************************************
// File:   dataset.hpp
// Author: Programación II. Universidad de Zaragoza
// Date:   Marzo 2026
// Coms:   Fichero de interfaz del módulo de dataset
//*****************************************************************

#ifndef DATASET_HPP
#define DATASET_HPP

#include <iostream>
#include <iomanip>
#include <string> 
#include <vector> 

using namespace std; 

struct EntradaDataset {
	int id; 
	string cita; 
	string autor; 
};

typedef vector<EntradaDataset> Dataset; 

// PRE: fichero existe
// POST: dataset=[entrada_0, ..., entrada_n-1] AND 
//          ALL entrada_i.id = i (pos) 
void cargaDataset(string fichero, Dataset &dataset); 

// PRE: dataset=[entrada_0, ..., entrada_n-1] AND ent.id = n
// POST: dataset=[entrada_0, ..., entrada_n-1, ent]  
void anadirEntrada(Dataset &dataset, const EntradaDataset &ent); 

// PRE: 0 <= id < #dataset
// POST: accedeId(id) = dataset[id]
EntradaDataset accedeId(const Dataset &dataset, const int id); 

// PRE: True
// POST: muestra por pantalla los contenidos de ent
void muestraEntrada(const EntradaDataset &ent); 

// PRE: 0 <= id < #dataset
// POST: muestra por pantalla los contenidos de dataset[id]
void muestraEntrada(const Dataset &dataset, int id); 

#endif 
