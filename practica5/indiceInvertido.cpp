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

using namespace std; 

// PRE: fichero existe AND ordenadoLexicográficamentePorLíneas(fichero)
// POST: indice = [entrada_0, ..., entrada_n-1] AND 
//      FORALL (0<=id_0<#indice AND 0<=id_1<#indice AND id_0 < id_1) => indice[id_0].palabra < indice[id_1].palabra
void cargaIndice (string fichero, IndiceInvertido &indice){
}

// PRE: indice = [entrada_0, ..., entrada_n-1] 
// POST: indice = [entrada_0, ..., entrada_n-1, ent] AND 
//      FORALL entrada_i in indice. entrada_i.palabra < ent.palabra
void anadirEntrada (IndiceInvertido &indice, const EntradaIndice &ent){
}

// PRE: indice = [entrada_0, ..., entrada_n-1] AND palabra != ""
// POST: buscaPalabraSimple(indice,palabra) = pos AND 
//      (palabra IN {entrada_i.palabra | entrada_i in indice} => indice[pos].palabra == palabra) 
//      AND (palabra NOT IN {entrada_i.palabra | entrada_i in indice} => pos = -1)
int buscaPalabraSimple (const IndiceInvertido &indice, const string palabra){
	return 0;
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
	VectorVarEnt v;
	return v;
}

// PRE: TRUE
// POST: muestra por pantalla los contenidos del índice
void muestraIndice (const IndiceInvertido &indice){
}

// PRE: TRUE
// POST: #indice 
int tamano(const IndiceInvertido &indice){
	return 0;
}

// PRE: 0<=pos<#indice 
// POST: accedePos(indice, pos) == indice[pos]
EntradaIndice accedePos(const IndiceInvertido &indice, int pos){
	EntradaIndice e;
	return e;
}
