//*****************************************************************
// File:   pruebasIndiceInvertido.cpp
// Author: Niobe
// Date:   Marzo 2026
// Coms:   Programa de pruebas para el módulo indiceInvertido
//*****************************************************************

#include <iostream>
#include <vector>
#include <string>

#include "indiceInvertido.hpp"
#include "vectorVarEnt.hpp"

using namespace std;

int main() {
    cout << "==================================================" << endl;
    cout << "   INICIANDO PRUEBAS DE INDICE INVERTIDO" << endl;
    cout << "==================================================" << endl;

    // -------------------------------------------------------------------------
    // PRUEBA A: ÍNDICE DE AUTORES (LISSS_inv_idx_auth.txt)
    // -------------------------------------------------------------------------
    IndiceInvertido idxAutores;
    string ficheroAutores = "LISSS_inv_idx_auth.txt";
    
    cout << "\nCargando indice de autores desde: " << ficheroAutores << "..." << endl;
    cargaIndice(ficheroAutores, idxAutores);
    
    if (tamano(idxAutores) == 0) {
        cout << "¡ERROR! No se pudo cargar el fichero de autores." << endl;
        return 1;
    }
    cout << "Carga completada. Total de entradas leidas: " << tamano(idxAutores) << endl;

    // Búsqueda 1: "unamuno"
    cout << "\n--- Buscando autor: 'unamuno' ---" << endl;
    cout << "[ESPERADO] Posicion: (depende de la carga) | Documentos: 3 (Ids: 1746, 1614, 1867)" << endl;
    
    int posUnamuno = buscaPalabraSimple(idxAutores, "unamuno");
    if (posUnamuno != -1) {
        EntradaIndice ent = accedePos(idxAutores, posUnamuno);
        cout << "[OBTENIDO] Posicion: " << posUnamuno << " | Documentos: " << tamano(ent.documentos) << " (Ids: ";
        for (int i = 0; i < tamano(ent.documentos); i++) {
            cout << accedePos(ent.documentos, i) << (i < tamano(ent.documentos)-1 ? ", " : "");
        }
        cout << ")" << endl;
    } else {
        cout << "[OBTENIDO] ERROR: No encontrado (-1)" << endl;
    }

    // Búsqueda 2: "agatha"
    cout << "\n--- Buscando autor: 'agatha' ---" << endl;
    cout << "[ESPERADO] Posicion: (depende de la carga) | Documentos: 6 (Ids: 100, 765, 698, 1653, 1984, 681)" << endl;
    
    int posAgatha = buscaPalabraSimple(idxAutores, "agatha");
    if (posAgatha != -1) {
        EntradaIndice ent = accedePos(idxAutores, posAgatha);
        cout << "[OBTENIDO] Posicion: " << posAgatha << " | Documentos: " << tamano(ent.documentos) << " (Ids: ";
        for (int i = 0; i < tamano(ent.documentos); i++) {
            cout << accedePos(ent.documentos, i) << (i < tamano(ent.documentos)-1 ? ", " : "");
        }
        cout << ")" << endl;
    } else {
        cout << "[OBTENIDO] ERROR: No encontrado (-1)" << endl;
    }


    // -------------------------------------------------------------------------
    // PRUEBA B: ÍNDICE DE PALABRAS (LISSS_inv_idx_words.txt)
    // -------------------------------------------------------------------------
    IndiceInvertido idxPalabras;
    string ficheroPalabras = "LISSS_inv_idx_words.txt";
    
    cout << "\n--------------------------------------------------" << endl;
    cout << "Cargando indice de palabras desde: " << ficheroPalabras << "..." << endl;
    cargaIndice(ficheroPalabras, idxPalabras);
    
    if (tamano(idxPalabras) == 0) {
        cout << "¡ERROR! No se pudo cargar el fichero de palabras." << endl;
        return 1;
    }

    // Búsqueda 3: "yate"
    cout << "\n--- Buscando palabra: 'yate' ---" << endl;
    cout << "[ESPERADO] Documentos: 1 (Id: 600)" << endl;
    
    int posYate = buscaPalabraSimple(idxPalabras, "yate");
    if (posYate != -1) {
        EntradaIndice ent = accedePos(idxPalabras, posYate);
        cout << "[OBTENIDO] Documentos: " << tamano(ent.documentos) << " (Id: ";
        for (int i = 0; i < tamano(ent.documentos); i++) {
            cout << accedePos(ent.documentos, i) << (i < tamano(ent.documentos)-1 ? ", " : "");
        }
        cout << ")" << endl;
    } else {
        cout << "[OBTENIDO] ERROR: No encontrado (-1)" << endl;
    }


    // -------------------------------------------------------------------------
    // PRUEBA C: INTERSECCIÓN DE PALABRAS (buscaPalabras)
    // -------------------------------------------------------------------------
    cout << "\n--------------------------------------------------" << endl;
    cout << "Prueba de Interseccion: 'yate' AND 'yacer'" << endl;
    cout << "(yate esta en [600] y yacer esta en [1215])" << endl;
    cout << "[ESPERADO] Documentos en comun: 0" << endl;
    
    vector<string> busquedaMultiple = {"yate", "yacer"};
    VectorVarEnt docsComunes = buscaPalabras(idxPalabras, busquedaMultiple);
    
    cout << "[OBTENIDO] Documentos en comun: " << tamano(docsComunes) << endl;
    
    if (tamano(docsComunes) > 0) {
        cout << "Ids obtenidos en la interseccion: ";
        for (int i = 0; i < tamano(docsComunes); i++) {
            cout << accedePos(docsComunes, i) << " ";
        }
        cout << endl;
    }


    // -------------------------------------------------------------------------
    // PRUEBA D: PALABRA INEXISTENTE
    // -------------------------------------------------------------------------
    cout << "\n--------------------------------------------------" << endl;
    cout << "Buscando palabra que no existe: 'zzzzzzzz'" << endl;
    cout << "[ESPERADO] Resultado de busqueda simple: -1" << endl;
    
    int posFallo = buscaPalabraSimple(idxPalabras, "zzzzzzzz");
    cout << "[OBTENIDO] Resultado de busqueda simple: " << posFallo << endl;

    cout << "\n==================================================" << endl;
    cout << "   FIN DE LAS PRUEBAS" << endl;
    cout << "==================================================" << endl;

    return 0;
}
