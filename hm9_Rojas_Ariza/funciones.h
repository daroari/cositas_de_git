#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

 
// Funcion v(t) = d(y)/dt
float func_v (int v0, int t){
    double a = -9.8;
    return v0 + a*t;
}

// Función y(t)
float func_posicion (int v0, double X0, int t){
    double a = -9.8;
    return X0 + v0*t + (1/2)*a*pow(t, 2);
    
}

// Rungekutta 
double* rungekutta (int v0, double X0, double deltat, int t){
    //Variable en la que se guardan las velocidades.
    double tiempo;
    //Variable en la que se guardan las posiciones y(t).
    double posicion;
    //Calcular posición actual 
    double pos_actual = func_posicion(v0, X0, t);
    //Aplicar RK4 a la funcion de velocidad, que es una ecuación diferenical para v = dx/dt.
    double k1, k2, k3, k4;
    k1 = func_v(v0, t); 
    k2 = func_v(v0 + k1 * (1/2), t + deltat/2) * deltat; 
    k3 = func_v(v0 + k2 * (1/2), t + deltat/2) * deltat; 
    k4 = func_v(v0  + k3, t + deltat) * deltat; 
    //Actualización de pasos
    tiempo = t + deltat;
    posicion = pos_actual + (1/6)*(k1 + 2*k2 + 2*k3 + k4);
    // Vector en que se guardan los pares de posiciones y velocidades.
    double* V_y_T = new double[2];
    
    V_y_T[0] = tiempo;
    V_y_T[1] = posicion;
    return V_y_T;
        
    }

// Funcion para calcular el tiempo que dura en el aire.
double t_en_aire(int v0){
    double a_magnitud = 9.8;
    return 2*v0/a_magnitud;

}



