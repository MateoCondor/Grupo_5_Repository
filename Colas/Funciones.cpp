#include "Funciones.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>



int Funciones::generarNumeroAleatorio (int min, int max) {
    int num, c;
    srand(time(NULL));
    num = rand() % ((max+1) - min);
    return num;
}

int Funciones::maximo(int n1,int n2) {
    if (n1 > n2) {
        return n1;
    } else {
        return n2;
    }
}

int Funciones::tiempoDeLlegada ( int tiempoDeLlegadaAnterior) {
        return generarNumeroAleatorio(1, 25) + tiempoDeLlegadaAnterior;
}

int Funciones::tiempoSalida (int tiempoLlegada, int tiempoEspera, int tiempoServicio) {
    return tiempoLlegada + tiempoEspera + tiempoServicio;
}

int Funciones::tiempoServicio () {
    int tiempoServicio = generarNumeroAleatorio(1, 16);
    return tiempoServicio;
}

int Funciones::tiempoEntreLLegada (int tiempoLlegadaActual, int tiempoLlegadaAnterior, int tam) {
    if (tam == 1) {
        return tiempoLlegadaActual;
    }else {
        return tiempoLlegadaActual - tiempoLlegadaAnterior;
    }
}

int Funciones::tiempoEspera (int tiempoLlegadaActual, int tiempoSalidaAnterior) {
    return maximo(tiempoSalidaAnterior, tiempoLlegadaActual) - tiempoLlegadaActual;
}

int Funciones::tiempoNoTrabajaCajero(int tiempoLlegadaActual, int tiempoSalidaAnterior, int tam){
    if (tam == 1) {
        return 0;
    }else{
        return maximo(tiempoLlegadaActual,tiempoSalidaAnterior) - tiempoSalidaAnterior;
    }
}
    

Funciones::Funciones()
{
    //ctor
}

Funciones::~Funciones()
{
    //dtor
}
