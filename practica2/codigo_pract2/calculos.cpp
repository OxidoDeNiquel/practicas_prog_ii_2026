//*****************************************************************
// File:   calculos.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   14/01/2026
// Coms:   Programa de desarrollo del comportamiento de las funciones
//         definidas en el módulo calculos
//*****************************************************************

#include <iostream>
#include <cmath>
#include "calculos.hpp"

using namespace std;


// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: (n = 0 -> numCifras(n,b) = 1) ∧
//       (n > 0 -> numCifras(n,b) = NC ∧  n >= b^(NC-1) ∧ n < b^NC)
int numCifras(const int n, const int b){
	if(n<b){
		return 1;
	}else{
		return 1 + numCifras(n/b, b);
	}
}

// Pre:  n >= 0 ∧ i >= 1 ∧ 2 <= b <= 10
// Post: cifra(n,i,b) = (n / b^(i-1)) % b
int cifra(const int n, const int i, const int b){
	if(i==1){
		return n % b;
	}else{
		int potencia = pow(b, i - 1);
		return (n / potencia) % b;
	}
}

// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: cifraMayor(n,b) = (Max α∊[1,∞].cifra(n,α,b))
int cifraMayor(const int n, const int b){
    if(numCifras(n,b) == 1){
        return n;
    }else{
        int a = numCifras(n,b); 
        
        // 1. Usas tu función para sacar la primera cifra (la de más a la izquierda)
        int primeraCifra = cifra(n, a, b); 
        
        // 2. Le "cortas" esa primera cifra al número para hacerlo más pequeño.
        int potencia = pow(b, a - 1);
        int restoDelNumero = n % potencia; 
        
        // 3. Llamada recursiva con el número ya recortado
        int mayorDelResto = cifraMayor(restoDelNumero, b);
        
        // 4. Ahora sí, comparas la cifra que sacaste con la mayor de las que quedan
        if(primeraCifra > mayorDelResto){
            return primeraCifra;
        }else{
            return mayorDelResto;
        }
    }
}

// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: cifraMasSignificativa(n,bvp ) = n / b^(NC-1)
//       ∧ (n >= b^(NC-1) ∧ n < b^NC)
int cifraMasSignificativa(const int n, const int b){
	if(numCifras(n,b)==1){
		return n;
	}else{
		return cifraMasSignificativa(n/b,b);
	}
}


// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: sumaCifras(n,b) = (∑ α∊[1,∞].cifra(n,α,b))
int sumaCifras(const int n, const int b){
	if(numCifras(n,b)==1){
		return n;
	}else{
		int ultimaCifra = cifra(n,1,b);
		return ultimaCifra + sumaCifras(n/b, b);
	}
}
