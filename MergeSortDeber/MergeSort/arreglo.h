/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS
         ~~ ESPE ~~
     INGENIERIA EN SOFTWARE

           GRUPO #5
MIEMBROS:
    - Luis Burbano
    - Mateo Condor
    - Camila Morales
    - Ricardo Rivadeneira
    - Steven Pozo
    - Jairo Quilumbaquin
    - Edwin Cantuña

Fecha de creacion:
    - 12 / 12 / 2022

Fecha de modificacion:
    - 18 / 12 / 2022

*/

#pragma once
#include "Animacion.h"
#include <Windows.h>


Animacion animacion;

template <typename T>
class Arreglo {
private:
    T* _datos = nullptr;
    int _tamano = 0;

public:
    Arreglo();
    void agregar(int elemento);
    T obtener(int indice);
    void imprimir();
    void borrar();
    void ordenar();
    int tamano();
    void imprimirArreglo();

    void merge(int inicio, int medio, int fin);
    void merge_sort(int inferior, int superior);
};

template <typename T>
Arreglo<T>::Arreglo() {}

template <typename T>
void Arreglo<T>::agregar(int elemento) {
    if (_tamano == 0) {
        _datos = new T[1];
    }
    else {
        T* nuevo = new T[_tamano + 1];

        for (int i = 0; i < _tamano; i++) {
            *(nuevo + i) = *(_datos + i);
        }

        delete[] _datos;
        _datos = nuevo;
    }

    _datos[_tamano] = elemento;
    _tamano++;
}

template<typename T>
T Arreglo<T>::obtener(int indice) {
    int valor = *(_datos + indice);
    return valor;
}


//Funcion para imprimir con barras el resultado 
template <typename T>
void Arreglo<T>::imprimir() {
    int x = 5;
    int y = 5;
    for (int i = 0; i < _tamano; i++) {
        animacion.gotoxi(x, y++); std::cout << *(_datos + i) << "   \t   " << animacion.generarFilas(*(_datos + i));
        //animacion.gotoxi(x, y++); std::cout << *(_datos + i); animacion.gotoxi(x + 5, y++); std::cout << animacion.generarFilas(*(_datos + i));
    }
    Sleep(600);
}

template <typename T>
void Arreglo<T>::borrar() {
    int x = 5;
    int y = 5;

    for (int i = 0; i < _tamano; i++) {
        animacion.gotoxi(x, y++); std::cout << "                                                                                                   " << "                                                                                       ";
    }
    Sleep(1);
}


template <typename T>
void Arreglo<T>::ordenar() {
    merge_sort(0, _tamano - 1);
}

template<typename T>
int Arreglo<T>::tamano() {
    return _tamano;
}

template <typename T>
void Arreglo<T>::imprimirArreglo() {
    std::cout << "[";

    for (int i = 0; i < _tamano; i++) {
        std::cout << *(_datos + i);

        if (i != _tamano - 1) {
            std::cout << ", ";
        }
    }

    std::cout << "]" << std::endl;
}

//===================================================
//      Inicio de las funciones necesarias para      
//      el algoritmo de ordenamiento MergeSort  



// Función para fusionar las dos partes del arreglo
template <typename T>
void Arreglo<T>::merge(int inicio, int medio, int fin) {
    auto const subArregloUno = medio - inicio + 1;
    auto const subArregloDos = fin - medio;

    //arreglos temporales 
    auto* arregloInicial = new int[subArregloUno];
    auto* arregloFinal = new int[subArregloDos];

    // Copiar datos en los arreglos temporales
    for (auto i = 0; i < subArregloUno; i++) {
        *(arregloInicial + i) = *(_datos + inicio + i);
    }

    for (auto j = 0; j < subArregloDos; j++) {
        *(arregloFinal + j) = *(_datos + medio + 1 + j);
    }

    // Fusionar los arreglos temporales de nuevo en un arreglo.
    auto indiceArregloUno = 0, indiceArregloDos = 0;
    int indiceArregloUnido = inicio;

    while (indiceArregloUno < subArregloUno && indiceArregloDos < subArregloDos) {
        if (*(arregloInicial + indiceArregloUno) <= *(arregloFinal + indiceArregloDos)) {
            *(_datos + indiceArregloUnido) = *(arregloInicial + indiceArregloUno);
            indiceArregloUno++;
        }
        else {
            *(_datos + indiceArregloUnido) = *(arregloFinal + indiceArregloDos);
            indiceArregloDos++;
        }

        indiceArregloUnido++;
    }

    // Copiar los elementos restantes del arreglo temporal uno, si hay alguno.
    while (indiceArregloUno < subArregloUno) {
        *(_datos + indiceArregloUnido) = *(arregloInicial + indiceArregloUno);
        indiceArregloUno++;
        indiceArregloUnido++;
    }

    // Copiar los elementos restantes del arreglo temporal dos, si hay alguno.
    while (indiceArregloDos < subArregloDos) {
        *(_datos + indiceArregloUnido) = *(arregloFinal + indiceArregloDos);
        indiceArregloDos++;
        indiceArregloUnido++;
    }
}


// Función para dividir el arreglo en dos partes
template <typename T>
void Arreglo<T>::merge_sort(int inferior, int superior) {
    if (inferior >= superior)
        return;

    auto medio = inferior + (superior - inferior) / 2;
    merge_sort(inferior, medio);
    merge_sort(medio + 1, superior);
    merge(inferior, medio, superior);
    imprimir();
    borrar();
}



//      Fin de las funciones necesarias para      
//      el algoritmo de ordenamiento MergeSort  
//===================================================