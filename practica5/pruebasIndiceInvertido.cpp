//***************************************************************************
// File:   pruebasIndiceInvertido.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   18/02/2026
// Coms:   Pruebas :P
//***************************************************************************
#include <iostream>
#include <string> 
#include <vector> 
#include <sstream>
#include "vectorVarEnt.hpp"
#include "indiceInvertido.hpp"

using namespace std;

VectorVarEnt extraerDocumentos(string ids){
    VectorVarEnt resultado;
    stringstream ss(ids);
    string doc;
    
    while (getline(ss, doc, ',')) {
    	resultado.push_back(stoi(doc));
    }

    // Mostrar resultado
    for (const int& s : resultado) {
        cout << s << endl;
    }
    
    return resultado;
}

int main() {

	string ids = "1,2,3";
	VectorVarEnt res = extraerDocumentos(ids);
	
	return 0;
	
}


