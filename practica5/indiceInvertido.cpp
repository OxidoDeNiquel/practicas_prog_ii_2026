//*****************************************************************
// File:   indiceInvertido.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   Marzo 2026
// Coms:   Fichero de implementacion del módulo de biblioteca para gestionar 
// 		un índice invertido muy sencillo
//*****************************************************************

#include <iostream>
#include <iomanip>

#include "indiceInvertido.hpp"
#include "vectorVarEnt.hpp"

#include <string> 
#include <vector> 
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

VectorVarEnt extraerDocumentos(string ids){
    VectorVarEnt resultado;
    stringstream ss(ids);
    string doc;
    
    while (getline(ss, doc, ',')) {
    	if (!doc.empty() && doc != "\r") {
            anadirFinal(resultado, stoi(doc));
        }
    }
    
    return resultado;
}

// PRE: fichero existe AND ordenadoLexicográficamentePorLíneas(fichero)
// POST: indice = [entrada_0, ..., entrada_n-1] AND 
//      FORALL (0<=id_0<#indice AND 0<=id_1<#indice AND id_0 < id_1) => indice[id_0].palabra < indice[id_1].palabra
void cargaIndice (string fichero, IndiceInvertido &indice){

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
        
        string palabra, frecuencia, ids;
        
        getline(ss, palabra, '\t');
        getline(ss, frecuencia, '\t');
        getline(ss, ids, '\t');
        
        VectorVarEnt documentos=extraerDocumentos(ids);
        
        EntradaIndice ei;
        
        ei.palabra=palabra;
        ei.documentos=documentos;
        
        anadirEntrada(indice,ei);
    }
    
    fich.close();
    
}

// PRE: indice = [entrada_0, ..., entrada_n-1] 
// POST: indice = [entrada_0, ..., entrada_n-1, ent] AND 
//      FORALL entrada_i in indice. entrada_i.palabra < ent.palabra
void anadirEntrada (IndiceInvertido &indice, const EntradaIndice &ent){
	indice.push_back(ent);
}

// Búsqueda binaria recursiva adaptada para buscar strings en el índice
int buscaDicotomicaAux(const IndiceInvertido &indice, const string &palabra, int p, int f) {
	if(p>f){	
		return -1;
	}
	
	int medio= p+(f-p)/2;
	string palabraMedio=accedePos(indice, medio).palabra;
	
	if (palabraMedio == palabra) {
        return medio;
    } 
    else if (palabraMedio > palabra) {
        // Buscar mitad izquierda
        return buscaDicotomicaAux(indice, palabra, p, medio - 1);
    } 
    else {
        // Buscar mitad derecha
        return buscaDicotomicaAux(indice, palabra, medio + 1, f);
    }
}

// PRE: indice = [entrada_0, ..., entrada_n-1] AND palabra != ""
// POST: buscaPalabraSimple(indice,palabra) = pos AND 
//      (palabra IN {entrada_i.palabra | entrada_i in indice} => indice[pos].palabra == palabra) 
//      AND (palabra NOT IN {entrada_i.palabra | entrada_i in indice} => pos = -1)
int buscaPalabraSimple (const IndiceInvertido &indice, const string palabra){
	if (tamano(indice) == 0) return -1;
    return buscaDicotomicaAux(indice, palabra, 0, tamano(indice) - 1);
}

// PRE: indice = [entrada_0, ..., entrada_n-1] AND FORALL palabra IN palabras.palabra != ""
// POST: buscaPalabras(indice,palabra) = result = [pos_0,...,pos_i] AND 
//      (FORALL palabra_i in palabras. buscaPalabraSimple(indice,palabra) != -1 ) <=>  
//          buscaPalabraSimpe(indice,palabra_i) == pos_i AND 
//          result = intersección(indice[pos_i].documentos para todo pos_i) 
//      AND 
//      NOT (FORALL palabra_i in palabras. buscaPalabraSimple(indice,palabra) != -1 )
//          result = [] 
VectorVarEnt buscaPalabras (const IndiceInvertido &indice, const vector<string> palabras){
	VectorVarEnt resultado;
    
    if (palabras.empty()) {
        return resultado; 
    }

    int posPrimera = buscaPalabraSimple(indice, palabras[0]);
    if (posPrimera == -1) {
        // Si la primera palabra no está, la intersección será siempre vacía
        return resultado; 
    }
    
    resultado = accedePos(indice, posPrimera).documentos;

    for (int i = 1; i < palabras.size(); i++) {
        int posActual = buscaPalabraSimple(indice, palabras[i]);
        
        if (posActual == -1) {
            // Si UNA de las palabras no existe, la intersección de TODAS es vacía
            vaciar(resultado); 
            return resultado;
        }
        
        VectorVarEnt docsActual = accedePos(indice, posActual).documentos;
        
        // interseccion
        resultado = elementosCompartidos(resultado, docsActual);
    }

    return resultado;
}

void muestraIndiceAux(const IndiceInvertido &v, int i){
	if(i==0){
        cout << "Palabra: " << v.at(i).palabra << "\nNum documentos: " << tamano(v.at(i).documentos) << endl;
    }else{
        muestraIndiceAux(v,i-1);
        cout << "Palabra: " << v.at(i).palabra << "\nNum documentos: " << tamano(v.at(i).documentos) << endl;
    }
}

// PRE: TRUE
// POST: muestra por pantalla los contenidos del índice
void muestraIndice (const IndiceInvertido &indice){
	muestraIndiceAux(indice, indice.size() - 1);
}

// PRE: TRUE
// POST: #indice 
int tamano(const IndiceInvertido &indice){
	return indice.size();
}

// PRE: 0<=pos<#indice 
// POST: accedePos(indice, pos) == indice[pos]
EntradaIndice accedePos(const IndiceInvertido &indice, int pos){
	return indice.at(pos);
}
