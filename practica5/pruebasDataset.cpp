//*****************************************************************
// File:   pruebasDataset.cpp
// Author: Níobe CLavería Cubero
// Date:   Abril 2026
// Coms:   Programa de prueba para el módulo dataset
//*****************************************************************

#include <iostream>
#include "dataset.hpp"

using namespace std;

int main() {
    cout << "--- INICIANDO PRUEBAS DEL MODULO DATASET ---" << endl << endl;

    Dataset miDataset;

    // ---------------------------------------------------------
    // PRUEBA 1: anadirEntrada y accedeId (Prueba Manual)
    // ---------------------------------------------------------
    cout << "1. Probando anadirEntrada() y accedeId()..." << endl;
    
    EntradaDataset e1 = {0, "Cita de prueba manual", "Autor Manual"};
    anadirEntrada(miDataset, e1);
    
    EntradaDataset recuperada = accedeId(miDataset, 0);
    
    // Verificamos que lo que hemos metido es exactamente lo que sacamos
    if (recuperada.id == 0 && recuperada.cita == "Cita de prueba manual" && recuperada.autor == "Autor Manual") {
        cout << "   [EXITO] Los datos se han anadido y recuperado correctamente." << endl;
    } else {
        cout << "   [FALLO] Los datos recuperados no coinciden." << endl;
    }

    // ---------------------------------------------------------
    // PRUEBA 2: muestraEntrada (ambas sobrecargas)
    // ---------------------------------------------------------
    cout << "\n2. Probando muestraEntrada(). Deberias ver la cita manual dos veces:" << endl;
    cout << "   -> Usando muestraEntrada(EntradaDataset):" << endl;
    cout << "      ";
    muestraEntrada(recuperada); 
    
    cout << "   -> Usando muestraEntrada(Dataset, id):" << endl;
    cout << "      ";
    muestraEntrada(miDataset, 0);


    // ---------------------------------------------------------
    // PRUEBA 3: cargaDataset desde tu fichero real
    // ---------------------------------------------------------
    cout << "\n3. Probando cargaDataset() con el fichero 'LISSS_2000_cleanIDs.txt'..." << endl;
    
    string nombreFichero = "LISSS_2000_cleanIDs.txt";
    Dataset datasetCargado; 
    
    // Llamamos a tu función de lectura
    cargaDataset(nombreFichero, datasetCargado);
    
    // Verificamos si se ha cargado contenido
    if (datasetCargado.size() > 0) {
        cout << "   [EXITO] Se han cargado " << datasetCargado.size() << " entradas desde el fichero." << endl;
        
        cout << "\n   Mostrando la PRIMERA entrada leida del fichero:" << endl;
        cout << "   ";
        muestraEntrada(datasetCargado, 0);
        
        cout << "\n   Mostrando la ULTIMA entrada leida del fichero:" << endl;
        cout << "   ";
        muestraEntrada(datasetCargado, datasetCargado.size() - 1);
        
    } else {
        cout << "   [FALLO] El dataset esta vacio. Comprueba que el fichero se llama asi y esta en la misma carpeta que el ejecutable." << endl;
    }

    cout << "\n--- FIN DE LAS PRUEBAS ---" << endl;
    
    return 0;
}
