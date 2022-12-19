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
    T* datos = nullptr;
    int tamanio = 0;

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
    if (tamanio == 0) {
        datos = new T[1];
    }
    else {
        T* nuevo = new T[tamanio + 1];

        for (int i = 0; i < tamanio; i++) {
            *(nuevo + i) = *(datos + i);
        }

        delete[] datos;
        datos = nuevo;
    }

    datos[tamanio] = elemento;
    tamanio++;
}

template<typename T>
T Arreglo<T>::obtener(int indice) {
    int valor = *(datos + indice);
    return valor;
}

//Funcion para imprimir con barras el resultado 
template <typename T>
void Arreglo<T>::imprimir() {
    int x = 5;
    int y = 5;
    for (int i = 0; i < tamanio; i++) {
        //animacion.gotoxi(x, y++); std::cout << *(datos + i) << "\t\t" << animacion.generarFilas(*(datos + i));
        animacion.gotoxi(x, y++); std::cout << *(datos + i); 
        animacion.gotoxi(x + 10, (y++)-0.123); std::cout << animacion.generarFilas(*(datos + i));
    }
    Sleep(500);
}

template <typename T>
void Arreglo<T>::borrar() {
    int x = 5;
    int y = 5;

    for (int i = 0; i < tamanio; i++) {
        animacion.gotoxi(x, y++); std::cout << "                                                                                                                                                                   "   
        << "                                                                                                                                                                                                       ";
    }
    Sleep(1);
}


template <typename T>
void Arreglo<T>::ordenar() {
    merge_sort(0, tamanio - 1);
}

template<typename T>
int Arreglo<T>::tamano() {
    return tamanio;
}

template <typename T>
void Arreglo<T>::imprimirArreglo() {
    std::cout << "[";

    for (int i = 0; i < tamanio; i++) {
        std::cout << *(datos + i);

        if (i != tamanio - 1) {
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
    
    //arreglos temporales 
    int const subArregloUno = medio - inicio + 1;  // almacena el numero de elementos de la parte izquierda
    int const subArregloDos = fin - medio; // almacena el numero de elemento de la parte derecha

    // declaramos dos arreglos inicial y final con el numero de elementos que contendra cada uno
    int* arregloInicial = new int[subArregloUno], * arregloFinal = new int[subArregloDos]; 
    
    // Copiar datos en los arreglos temporales
    for (int i = 0; i < subArregloUno; i++) {
        *(arregloInicial + i) = *(datos + inicio + i);
        //arregloInicial[i] = arreglo[inicio+i]
        
    }

    // Asiganar los valores que le corresponen al arreglo Final o derecho
    for (int j = 0; j < subArregloDos; j++) {
        *(arregloFinal + j) = *(datos + medio + 1 + j);
        //arregloFinal[j] = arreglo[medio+1+j]
    }

     // Fusionar los arreglos temporales de nuevo en un arreglo.
    int indiceArregloUno = 0, indiceArregloDos = 0; // int i = 0, j = 0
    int indiceArregloUnido = inicio; // int k = inicio

    // Mesclando los valores del arreglo Inicial y Final
    // Copiar los elementos restantes del arreglo temporal uno, si hay alguno.
    while (indiceArregloUno < subArregloUno && indiceArregloDos < subArregloDos) {
        // En cado de que el elemento del arreglo Inicial sea menor o igual a del arreglo Final
        if (*(arregloInicial + indiceArregloUno) <= *(arregloFinal + indiceArregloDos)) {
            // arregloInicial[i] <= arregloFinal[j]
            // arreglo[k] = arregloInicial[i]
            // i++;
            
    
            // Cambiamos posiciones el indiceArregloUnido obtendra el elemento del arreglo Inicial
            *(datos + indiceArregloUnido) = *(arregloInicial + indiceArregloUno);
            indiceArregloUno++;
        }
        else {
            // Caso contrario el indiceArregloUnido obtendra el elemento del arrreglo Final            
            // arreglo[k] = arregloFinal[j]
            // j++;

            *(datos + indiceArregloUnido) = *(arregloFinal + indiceArregloDos);
            indiceArregloDos++;
        }
        // Aumentamos el valor 
        // k++
        indiceArregloUnido++;
    }

    // Vacial al arreglo Inicial
    // Copiar los elementos restantes del arreglo temporal dos, si hay alguno.
    while (indiceArregloUno < subArregloUno) {
        // i < izquierda
        // arreglo[k] = arregloFinal[i]
        // i++
        // k++
        *(datos + indiceArregloUnido) = *(arregloInicial + indiceArregloUno);
        indiceArregloUno++;
        indiceArregloUnido++;
    }

    // Vacial el arreglo Inicial
    while (indiceArregloDos < subArregloDos) {
        // j < derecha
        // arreglo[k] = arregloFinal[j]
        // j++
        // k++

        *(datos + indiceArregloUnido) = *(arregloFinal + indiceArregloDos);
        indiceArregloDos++;
        indiceArregloUnido++;
    }
}

/*
    Como Funciona: 
    Vamos a obtener el indice para poder dividir nuestro arreglo en dos uno inicial y otro final.
    Ahora tenemos un arreglo Incial y otro Final a los cuales vamos a seguir dividiendolos hasta
    que solo tengamos un arreglo con un elemento.
    Una vez tengamos los subarreglos dividos con un solo elementos vamos a proceder a comprar la parte
    Inicial y Final para ver cual es el elemento de menor valor.
    Este procesos de mezcla se va a repertir con todos los subArreglos hasta que regresemos al arreglo original.
*/

// Función para dividir el arreglo en dos partes
template <typename T>
void Arreglo<T>::merge_sort(int inicio, int final) {
    if (inicio >= final)
        return;

    int medio = inicio + (final - inicio) / 2;  // hasta donde divir del arreglo

    merge_sort(inicio, medio); // dividir la parte izquierda recursivamente
    merge_sort(medio + 1, final); // dividir la parte derecha recursivamente
    merge(inicio, medio, final); // Aqui es donde se hace la mezcla

    // Parte de la animacion
    imprimir();
    borrar();

}

//      Fin de las funciones necesarias para      
//      el algoritmo de ordenamiento MergeSort  
//===================================================