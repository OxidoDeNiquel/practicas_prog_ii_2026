//*****************************************************************
// File:   pruebasCal.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   14/01/2026
// Coms:   Programa de pruebas del comportamiento de las funciones
//         definidas en el módulo calculos
//*****************************************************************

#include <iostream>
#include "calculos.hpp"

using namespace std;


// Pre:  <cifras> es el número de cifras de <n> cuando se escribe en base <b>
//       y <b> está comprendido entre 2 y 10
// Post: Informa si el valor devuelto al ejecutar numCifras(n, b) es igual
//       a <cifras> o no lo es
void probarNumCifras(const int n, const int b, const int cifras){
    int r = numCifras(n, b);
    if (r == cifras) {
        cout << "Ok. numCifras(" << n << "," << b << ") = " << r << endl;
    } else {
        cout << "Mal. numCifras(" << n << "," << b << ") = " << r << ", pero debería ser "
             << cifras << endl;
    }
}


// Prueba el comportamiento de numCifras(n,10) para los siguientes valores de n:
// 0, 1, 9, 10, 99, 100, 999, 1000, ... , 99999, 100000, 99999 y 1000000
// y prueba el comportamiento de numCifras(n,2) para los siguientes valores de n:
// 0, 1, 1, 2, 3, 4, 7, 8, 15, 16, 31, 32, ..., 4095, 4096, 8191 y 8192
void probarNumCifras(){
    // Prueba el comportamiento de numCifras(n) para los siguientes valores de n:
    // 0, 1, 9, 10, 99, 100, 999, 1000, ..., 99999, 100000, 99999 y 1000000
    probarNumCifras(0, 10, 1);
    probarNumCifras(1, 10, 1);
    int n = 10;
    int cifras = 2;
    while (n <= 1000000) {
        probarNumCifras(n-1, 10, cifras-1);
        probarNumCifras(n, 10, cifras);
        n = 10*n;
        cifras = cifras + 1;
    }
    cout << endl;
    // Prueba el comportamiento de numCifras(n,2) para los siguientes valores de n:
    // 0, 1, 1, 2, 3, 4, 7, 8, 15, 16, 31, 32, ..., 4095, 4096, 8191 y 8192
    probarNumCifras(0, 2, 1);
    probarNumCifras(1, 2, 1);
    n = 2;
    cifras = 2;
    while (n <= 10000) {
        probarNumCifras(n-1, 2, cifras-1);
        probarNumCifras(n, 2, cifras);
        n = 2 * n;
        cifras = cifras + 1;
    }
    cout << endl;
}

// Pre:  <cifras> es el número de cifras de <n> cuando se escribe en base <b>
//       y <b> está comprendido entre 2 y 10
// Post: Informa si el valor devuelto al ejecutar numCifras(n, b) es igual
//       a <cifras> o no lo es
void probarCifra(const int n, const int i, const int b, const int resultado){
    int r = cifra(n, i, b);
    if (r == resultado) {
        cout << "Ok. cifra(" << n << "," << b << ") = " << r << endl;
    } else {
        cout << "Mal. cifra(" << n << "," << i << "," << b << ") = " << r << ", pero debería ser "
             << resultado << endl;
    }
}


// Prueba el comportamiento de cifra(n,i,b) para diferentes números naturales
// en las bases de numeración 2 y 10
void probarCifra(){
    // Casos en base 10
    probarCifra(54321, 1, 10, 1); // Unidades
    probarCifra(54321, 3, 10, 3); // Centenas
    probarCifra(54321, 5, 10, 5); // La cifra más significativa
    
    // Casos en base 2 (binario)
    // El número 5 en binario es 101
    probarCifra(5, 1, 2, 1); // Último bit (1)
    probarCifra(5, 2, 2, 0); // Bit central (0)
    probarCifra(5, 3, 2, 1); // Primer bit (1)
}


// Prueba el comportamiento de cifraMayor(n,b) para diferentes números naturales
// en las bases de numeración 2, 8 y 10
void probarCifraMayor(){
    // Código a implementar en la práctica
}


// Prueba el comportamiento de cifraMasSignificativa(n,b) para diferentes números naturales
// en las bases de numeración 2, 8 y 10
void probarCifraMasSignificativa(){
    // Código a implementar en la práctica
}


// Prueba el comportamiento de probarSumaCifras(n,b) para diferentes números naturales
// en las bases de numeración 2, 8 y 10
void probarSumaCifras(){
    // Código a implementar en la práctica
}


// Ejecuta una secuencia de pruebas de las funciones definidas en el módulo calculos.hpp
int main() {
    // Pruebas del comportamiento de numCifras(n,b)
    probarNumCifras();
    // Pruebas del comportamiento de cifra(n,i,b)
    probarCifra();    
    // Pruebas del comportamiento de cifraMayor(n,b)
    //probarCifraMayor();    
    // Pruebas del comportamiento de cifraMasSignificativa(n,b)
    //probarCifraMasSignificativa();
    // Pruebas del comportamiento de sumaCifras(n,b)
    //probarSumaCifras();

    return 0;
}
