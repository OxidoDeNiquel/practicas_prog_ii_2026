//*****************************************************************
// File:   pruebasCal.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   14/01/2026
// Coms:   Programa de pruebas del comportamiento de las funciones
//         definidas en el módulo calculos
//*****************************************************************

#include <iostream>
#include "pilaEnt.hpp"

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
void probarCifraMayor(const int n, const int b, const int resultado){
    int r = cifraMayor(n, b);
    if (r == resultado) {
        cout << "Ok. cifraMayor(" << n << "," << b << ") = " << r << endl;
    } else {
        cout << "Mal. cifraMayor(" << n << "," << b << ") = " << r << ", pero debería ser "
             << resultado << endl;
    }
}

void probarCifraMayor(){
    cout << "--- CASOS EN BASE 10 ---" << endl;
    probarCifraMayor(52786, 10, 8);
    probarCifraMayor(52986, 10, 9);
    probarCifraMayor(52767, 10, 7); 
    probarCifraMayor(654321, 10, 6); 
    probarCifraMayor(45321, 10, 5); 
    probarCifraMayor(111611, 10, 6); 
    probarCifraMayor(7, 10, 7); // Caso base: una sola cifra
    probarCifraMayor(0, 10, 0); // Caso límite con el cero

    cout << "\n--- CASOS EN BASE 2 (Binario) ---" << endl;
    // En base 2 las únicas cifras posibles son 0 y 1.
    // 5 en binario es "101". La mayor cifra es 1.
    probarCifraMayor(5, 2, 1);
    // 8 en binario es "1000". La mayor cifra es 1.
    probarCifraMayor(8, 2, 1);
    // 0 en binario es "0". La mayor cifra es 0.
    probarCifraMayor(0, 2, 0);

    cout << "\n--- CASOS EN BASE 8 (Octal) ---" << endl;
    // En base 8 las cifras posibles van del 0 al 7.
    // 8 en decimal = "10" en octal. La mayor cifra es 1.
    probarCifraMayor(8, 8, 1);
    // 63 en decimal = "77" en octal. La mayor cifra es 7.
    probarCifraMayor(63, 8, 7);
    // 34 en decimal = "42" en octal. La mayor cifra es 4.
    probarCifraMayor(34, 8, 4);
    // 15 en decimal = "17" en octal. La mayor cifra es 7.
    probarCifraMayor(15, 8, 7);
}


// Prueba el comportamiento de cifraMasSignificativa(n,b) para diferentes números naturales
// en las bases de numeración 2, 8 y 10
void probarCifraMasSignificativa(const int n, const int b, const int resultado){
    int r = cifraMasSignificativa(n, b);
    if (r == resultado) {
        cout << "Ok. cifraMasSignificativa(" << n << "," << b << ") = " << r << endl;
    } else {
        cout << "Mal. cifraMasSignificativa(" << n << "," << b << ") = " << r << ", pero debería ser "
             << resultado << endl;
    }
}

void probarCifraMasSignificativa(){
    cout << "--- CASOS EN BASE 10 ---" << endl;
    // Cambiadas todas las llamadas a la nueva función
    probarCifraMasSignificativa(52786, 10, 5);
    probarCifraMasSignificativa(52986, 10, 5);
    probarCifraMasSignificativa(52767, 10, 5); 
    probarCifraMasSignificativa(654321, 10, 6); 
    probarCifraMasSignificativa(45321, 10, 4); 
    probarCifraMasSignificativa(111611, 10, 1); 
    probarCifraMasSignificativa(7, 10, 7); // Caso base: una sola cifra
    probarCifraMasSignificativa(0, 10, 0); // Caso límite con el cero

    cout << "\n--- CASOS EN BASE 2 (Binario) ---" << endl;
    // 5 en binario es "101". La cifra más significativa es 1.
    probarCifraMasSignificativa(5, 2, 1);
    // 8 en binario es "1000". La cifra más significativa es 1.
    probarCifraMasSignificativa(8, 2, 1);
    // 0 en binario es "0". La cifra más significativa es 0.
    probarCifraMasSignificativa(0, 2, 0);

    cout << "\n--- CASOS EN BASE 8 (Octal) ---" << endl;
    // 8 en decimal = "10" en octal. La cifra más significativa es 1.
    probarCifraMasSignificativa(8, 8, 1);
    // 63 en decimal = "77" en octal. La cifra más significativa es 7.
    probarCifraMasSignificativa(63, 8, 7);
    // 34 en decimal = "42" en octal. La cifra más significativa es 4.
    probarCifraMasSignificativa(34, 8, 4);
    // 15 en decimal = "17" en octal. La cifra más significativa es 1.
    probarCifraMasSignificativa(15, 8, 1);
}


// Prueba el comportamiento de probarSumaCifras(n,b) para diferentes números naturales
// en las bases de numeración 2, 8 y 10
// Función auxiliar para comprobar un caso individual
void probarSumaCifras(const int n, const int b, const int resultado){
    int r = sumaCifras(n, b);
    if (r == resultado) {
        cout << "Ok. sumaCifras(" << n << ", " << b << ") = " << r << endl;
    } else {
        cout << "Mal. sumaCifras(" << n << ", " << b << ") = " << r 
             << ", pero deberia ser " << resultado << endl;
    }
}

// Función que agrupa todos los casos de prueba
void probarSumaCifras(){
    cout << "--- CASOS EN BASE 10 ---" << endl;
    // 1 + 2 + 3 = 6
    probarSumaCifras(123, 10, 6);
    // 9 + 0 + 9 = 18
    probarSumaCifras(909, 10, 18);
    // 6 + 5 + 4 + 3 + 2 + 1 = 21
    probarSumaCifras(654321, 10, 21);
    // Casos base
    probarSumaCifras(7, 10, 7); 
    probarSumaCifras(0, 10, 0); 

    cout << "\n--- CASOS EN BASE 2 (Binario) ---" << endl;
    // 5 en binario es "101". 1 + 0 + 1 = 2.
    probarSumaCifras(5, 2, 2);
    // 15 en binario es "1111". 1 + 1 + 1 + 1 = 4.
    probarSumaCifras(15, 2, 4);
    // 8 en binario es "1000". 1 + 0 + 0 + 0 = 1.
    probarSumaCifras(8, 2, 1);

    cout << "\n--- CASOS EN BASE 8 (Octal) ---" << endl;
    // 15 en decimal = "17" en octal. 1 + 7 = 8.
    probarSumaCifras(15, 8, 8);
    // 63 en decimal = "77" en octal. 7 + 7 = 14.
    probarSumaCifras(63, 8, 14);
    // 8 en decimal = "10" en octal. 1 + 0 = 1.
    probarSumaCifras(8, 8, 1);
}


// Ejecuta una secuencia de pruebas de las funciones definidas en el módulo calculos.hpp
int main() {
    // Pruebas del comportamiento de numCifras(n,b)
    //probarNumCifras();
    // Pruebas del comportamiento de cifra(n,i,b)
    //probarCifra();    
    // Pruebas del comportamiento de cifraMayor(n,b)
    //probarCifraMayor();    
    // Pruebas del comportamiento de cifraMasSignificativa(n,b)
    //probarCifraMasSignificativa();
    // Pruebas del comportamiento de sumaCifras(n,b)
    probarSumaCifras();

    return 0;
}
