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

#include <unistd.h> // para "usleep"
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std; 

// PRE: fichero existe
// POST: dataset=[entrada_0, ..., entrada_n-1] AND 
//          ALL entrada_i.id = i (pos) 
void cargaDataset(string fichero, Dataset &dataset){

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
    
    //Ahora el mappeo
    string lineaActual;
    
    while(getline(fich, lineaActual)){
    
    	stringstream ss(lineaActual);
        
        string id, cita, autor;
        
        getline(ss, id, '\t');
        getline(ss, cita, '\t');
        getline(ss, autor, '\t');
        
        EntradaDataset ed;
        
        ed.id = stoi(id); //Pasamos a int
        ed.cita = cita;
        ed.autor = autor;
        
        anadirEntrada(dataset,ed);
    }
    
    fich.close();
    
}

// PRE: dataset=[entrada_0, ..., entrada_n-1] AND ent.id = n
// POST: dataset=[entrada_0, ..., entrada_n-1, ent]  
void anadirEntrada(Dataset &dataset, const EntradaDataset &ent){
	dataset.push_back(ent);
}

// PRE: 0 <= id < #dataset
// POST: accedeId(id) = dataset[id]
EntradaDataset accedeId(const Dataset &dataset, const int id){
	return dataset.at(id);
}

// PRE: True
// POST: muestra por pantalla los contenidos de ent
void muestraEntrada(const EntradaDataset &ent){
	cout << "Id: " << ent.id << "\n";
	cout << "Cita: " << ent.cita << "\n";
	cout << "Autor: " << ent.autor << "\n";
	cout << "------------------------" << endl;
}

// PRE: 0 <= id < #dataset
// POST: muestra por pantalla los contenidos de dataset[id]
void muestraEntrada(const Dataset &dataset, int id){
	EntradaDataset ed= accedeId(dataset,id);
	muestraEntrada(ed);
}
