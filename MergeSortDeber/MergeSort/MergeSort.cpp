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

#include <iostream>
#include "arreglo.h"
#include "val.h"

int main() { 

    Arreglo<int> arreglo;

    do {
        float n = val::leerNumero("ingrese un numero: ");
        arreglo.agregar(n);
    } while (val::confirmar("Desea agregar otro numero? "));
    system("cls");

    std::cout << "Arreglo Desordenado" << std::endl;
    arreglo.imprimirArreglo();

    arreglo.ordenar();
    arreglo.imprimir();

    std::cout << "\n\n" << std::endl;
    std::cout << "Arreglo Ordenado" << std::endl;
    arreglo.imprimirArreglo();

    std::cout << std::endl;
    system("pause");

    return 0;
}
