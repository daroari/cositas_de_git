s#include "funciones.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

int main () {
    
    double X0 = 8.5; // m 
    int v0 = 20; // m/s
    double a = -9.8; // m/s
    int deltat = 0.01; // s
    int t_inicial = 0; // s
    int n = 10;
    int t = t_en_aire(v0); //s
    
    // Altura en un tiempo t
    double altura = func_posicion(v0, X0, t);
    
    // Se calcula el número de iteraciones necesarias para definir el tamaño de los arreglos que contendrán los resultados.
    int iter_1 = t/deltat;
    double *Tiempo = new double[iter_1];
    double *Altura_2 = new double[iter_1];
    
    
    int cont_1=0; 
    double t_2=0;
    int cont_2 = 0; 
    double iter_2= t/deltat;
    
    for (cont_1 < n - 1; cont_1++){
        double* RK = rungekutta(v0, X0, deltat, t_2);
            
        Tiempo[cont_1]=RK[0];
        Altura_2[cont_1]=RK[1];
        t_2+=.01;            
    }
    
    for (cont_2 < iter_1; cont_2++;){

    cout << Tiempo[cont_2] <<" "<<  Altura_2[cont_2] <<endl;
    }
    
    return 0;   
}