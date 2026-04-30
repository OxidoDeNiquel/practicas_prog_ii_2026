//***************************************************************************
// File:   tpb.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   18/02/2026
// Coms:   Contiene las funciones necesarias para implementar la funcionalidad 
//         propuesta de acuerdo a los requisitos establecidos
//***************************************************************************

#include <iostream>
#include <string>
#include <vector>

#include "dataset.hpp"
#include "indiceInvertido.hpp"
#include "vectorVarEnt.hpp"

using namespace std; 

// prototipos
void inicioPrograma(int argc, char* argv[]);
void imprimirResultados(const VectorVarEnt& docs, const Dataset& ds);
void buscaAutor(const string& autor, const IndiceInvertido& idx, const Dataset& ds);
void buscaKeyword(const string& kw, const IndiceInvertido& idx, const Dataset& ds);
void buscaKeywordsMultiples(const vector<string>& kws, const IndiceInvertido& idx, const Dataset& ds);

int main(int argc, char* argv[]){
    inicioPrograma(argc,argv);
    return 0;
}

void imprimirResultados(const VectorVarEnt& docs, const Dataset& ds) {
    int numDocs = tamano(docs);
    for (int i = 0; i < numDocs; i++) {
    
        int id = accedePos(docs, i); 
        
        EntradaDataset ed = accedeId(ds, id - 1); 
        
        cout << id << " :: " << ed.autor << "\n"<< ed.cita << endl;
    }
}

void buscaAutor(const string& autor, const IndiceInvertido& idx, const Dataset& ds){
    int pos = buscaPalabraSimple(idx, autor);
    if (pos != -1) {
        EntradaIndice ent = accedePos(idx, pos);
        imprimirResultados(ent.documentos, ds);
    }
}

void buscaKeyword(const string& kw, const IndiceInvertido& idx, const Dataset& ds){
    int pos = buscaPalabraSimple(idx, kw);
    if (pos != -1) {
        EntradaIndice ent = accedePos(idx, pos);
        imprimirResultados(ent.documentos, ds);
    }
}

void buscaKeywordsMultiples(const vector<string>& kws, const IndiceInvertido& idx, const Dataset& ds){
    VectorVarEnt docs = buscaPalabras(idx, kws);
    if (tamano(docs) > 0) {
        imprimirResultados(docs, ds);
    } else {
        cout << "No se han encontrado citas que contengan TODAS las palabras a la vez." << endl;
    }
}

void inicioPrograma(int argc, char* argv[]){
    if (argc < 3) {
        cout << "Error: Faltan argumentos." << endl;
        return;
    }
    
    string opcion = argv[1];
    Dataset ds;
    cargaDataset("LISSS_2000_cleanIDs.txt", ds);
    
    if (opcion == "-a") {
        if (argc != 3) {
            cout << "Error. Uso correcto: -a <autor>" << endl;
            return;
        }
        string autor = argv[2];
        IndiceInvertido idxAutores;
        cargaIndice("LISSS_inv_idx_auth.txt", idxAutores);
        buscaAutor(autor, idxAutores, ds);

    } 
    else if (opcion == "-k") {
        if (argc != 3) {
            cout << "Error. Uso correcto: -k <keyword>" << endl;
            return;
        }
        string keyword = argv[2];
        IndiceInvertido idxPalabras;
        cargaIndice("LISSS_inv_idx_words.txt", idxPalabras);
        buscaKeyword(keyword, idxPalabras, ds);

    } 
    else if (opcion == "-mk") {
        vector<string> keywords;
        for (int i = 2; i < argc; i++) {
            keywords.push_back(argv[i]);
        }
        IndiceInvertido idxPalabras;
        cargaIndice("LISSS_inv_idx_words.txt", idxPalabras);
        buscaKeywordsMultiples(keywords, idxPalabras, ds);

    } 
    else {
        cout << "Error: Opcion '" << opcion << "' no reconocida." << endl;
    }
}
