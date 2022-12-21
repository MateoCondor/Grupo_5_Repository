#pragma once
#include <iostream>
#include <functional>
#include "Nodo.h"

class Hash {
private:

    int cubo;
    Nodo<int>** tabla;
    
public:

    Hash(int v);

    void insertarItem(int v);

    void borrarItem(int clave);

    void buscarItem(int clave);

    int funcionHash(int v) {
        return (v % cubo);
    }

    int funcionHash2(int posicion) {
        posicion = posicion % cubo;
        posicion = (posicion + 1) % cubo;
        return posicion;
    }

    void imprimir();

};

Hash::Hash(int v) {
    this->cubo = v;
    tabla = new Nodo<int> *[cubo];
    for (int i = 0; i < v; i++) {
        tabla[i] = NULL;
    }
}

void Hash::insertarItem(int clave) {

    int indice = funcionHash(clave);
    Nodo<int>* aux = tabla[indice];
    
    if (tabla[indice] == NULL) {
        tabla[indice] = new Nodo<int>(clave);
        
    }
    else {
        int indice2 = funcionHash2(clave);
        if (tabla[indice2] == NULL) {
            tabla[indice2] = new Nodo<int>(clave);
        }
        else {
            cout << "No se puede insertar, el hash esta lleno" << endl;
        }
        /*
        aux = tabla[indice2];
        while (aux->getSiguiente() != NULL) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(new Nodo<int>(clave));
        */
    }
}

void Hash::borrarItem(int clave) {
    int indice = funcionHash(clave);
    Nodo<int>* aux = tabla[indice];
    while (aux == NULL)
    {
        indice++;
        aux = tabla[indice % cubo];
    }
    if (aux->getDato() == clave) {
        tabla[indice] = tabla[indice]->getSiguiente();
        delete aux;
    }
    else
    {
        while (aux == NULL)
        {
            indice++;
            aux = tabla[indice % cubo];
        }
        if (aux->getSiguiente() != NULL)
        {
            while (aux->getSiguiente()->getDato() != clave) {
                aux = aux->getSiguiente();
            }
        }
        else cout << "No existe ese elemento. Verifique que está en la lista." << endl;
    }

}

void Hash::imprimir() {
    for (int i = 0; i < cubo; i++) {
        Nodo<int>* aux = tabla[i];
        cout << i;
        while (aux != NULL) {
            cout << " --> " << aux->getDato() << " ";
            aux = aux->getSiguiente();
        }
        cout << endl;
        
    }
}

void Hash::buscarItem(int clave) {
    int indice = funcionHash(clave);
    Nodo<int>* aux = tabla[indice];
    while (aux == NULL)
    {
        indice++;
        aux = tabla[indice % cubo];
    }
    if (aux->getDato() == clave) {
        cout << "Se ha encontrado el valor " << clave << endl;
    }
    else
    {
        while (aux == NULL)
        {
            indice++;
            aux = tabla[indice % cubo];
        }
        if (aux->getSiguiente() != NULL)
        {
            while (aux->getSiguiente()->getDato() != clave) {
                aux = aux->getSiguiente();
            }
        }
        else cout << "No existe ese elemento. Verifique que está en la lista." << endl;
    }
}