//***************************************************************************
// File:   pruebaVectores.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   18/02/2026
// Coms:   Pruebas :P
//***************************************************************************
#include <iostream>
#include "vectorVarEnt.hpp"

using namespace std;

int main() {
    VectorVarEnt miVector;
    VectorVarEnt otroVector;

    cout << "--- INICIANDO PRUEBA DE TU MODULO vectorVarEnt ---" << endl;

    // 1. Probar estado inicial
    cout << "\n1. ¿Esta vacio al principio?: " 
         << (estaVacio(miVector) ? "SI" : "NO") << endl;

    // 2. Probar añadir elementos
    cout << "\n2. Anadiendo elementos (10, 20, 30)..." << endl;
    anadirFinal(miVector, 10);
    anadirFinal(miVector, 20);
    anadirFinal(miVector, 30);

    // 3. Probar tamaño y si está vacío ahora
    cout << "   Nuevo tamano: " << tamano(miVector) << endl;
    cout << "   ¿Sigue vacio?: " << (estaVacio(miVector) ? "SI" : "NO") << endl;

    // 4. Probar acceso a posiciones (accedePos)
    // OJO: Como devuelve 0 de momento, aquí verás que falla la lógica
    cout << "\n3. Probando accedePos:" << endl;
    cout << "   Elemento en posicion 0 (deberia ser 10): " << accedePos(miVector, 0) << endl;
    cout << "   Elemento en posicion 2 (deberia ser 30): " << accedePos(miVector, 2) << endl;

    // 5. Probar vaciar
    cout << "\n4. Probando vaciar()..." << endl;
    vaciar(miVector);
    cout << "   Tamano despues de vaciar: " << tamano(miVector) << endl;

    // 6. Probar elementosCompartidos (cuando lo programes)
    cout << "\n5. Probando elementosCompartidos..." << endl;
    anadirFinal(miVector, 1); anadirFinal(miVector, 2); anadirFinal(miVector, 3);
    anadirFinal(otroVector, 2); anadirFinal(otroVector, 3); anadirFinal(otroVector, 4);
    
    VectorVarEnt compartidos = elementosCompartidos(miVector, otroVector);
    cout << "   Tamano del vector de compartidos (deberia ser 2): " << tamano(compartidos) << endl;
	
    // 7. Probar muestraVector 
    cout << "\n6. Probando muestraVector (Cuidado, puede dar error de ejecucion):" << endl;
    // Descomenta la siguiente línea bajo tu propio riesgo hasta que corrijas la función ;)
   	muestraVector(miVector); 

    cout << "\n--- FIN DE LA PRUEBA ---" << endl;

    return 0;
}
