#pragma once

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "Nodo.h"


template <typename T>
class ListaSimple{
private:
    Nodo<T>* inicio = nullptr;
    Nodo<T>* fin = nullptr;
    int tam = 0;

public:

    void insertarPorInicio(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (inicio == NULL) {
            inicio = nuevo;
            fin = nuevo;
        }
        else {
            nuevo->setSiguiente(inicio);
            inicio = nuevo;
        }
        tam++;
    }

    void insertarPorFin(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (inicio == NULL) {
            inicio = nuevo;
            fin = nuevo;
        }
        else {
            fin->setSiguiente(nuevo);
            fin = nuevo;
        }
        tam++;
    }

    void insertarPorPosicion(T dato, int posicion) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (posicion == 0) {
            insertarPorInicio(dato);
        }
        else if (posicion == tam) {
            insertarPorFin(dato);
        }
        else if (posicion > 0 && posicion < tam) {
            Nodo<T>* aux = inicio;
            for (int i = 0; i < posicion - 1; i++) {
                aux = aux->getSiguiente();
            }
            nuevo->setSiguiente(aux->getSiguiente());
            aux->setSiguiente(nuevo);
            tam++;
        }
        else {
            cout << "\n\tPosicion no valida" << endl;
        }
    }

    void eliminarPorInicio() {
        if (inicio == NULL) {
            cout << "\n\tLista vacia" << endl;
        }
        else {
            Nodo<T>* aux = inicio;
            inicio = inicio->getSiguiente();
            delete aux;
            tam--;
        }
    }

    void eliminarPorFin() {
        if (inicio == NULL) {
            cout << "\n\tLista vacia" << endl;
        }
        else {
            Nodo<T>* aux = inicio;
            while (aux->getSiguiente() != fin) {
                aux = aux->getSiguiente();
            }
            delete fin;
            fin = aux;
            fin->setSiguiente(NULL);
            tam--;
        }
    }

    void eliminarPorPosicion(int posicion) {
        if (posicion == 0) {
            eliminarPorInicio();
        }
        else if (posicion == tam - 1) {
            eliminarPorFin();
        }
        else if (posicion > 0 && posicion < tam - 1) {
            Nodo<T>* aux = inicio;
            for (int i = 0; i < posicion - 1; i++) {
                aux = aux->getSiguiente();
            }
            Nodo<T>* aux2 = aux->getSiguiente();
            aux->setSiguiente(aux2->getSiguiente());
            delete aux2;
            tam--;
        }
        else {
            cout << "\n\tPosicion no valida" << endl;
        }
    }

    void buscar(T dato) {
        Nodo<T>* aux = inicio;
        int cont = 1;
        bool encontrado = false;
        if (inicio == NULL) {
            cout << "\n\tLista vacia" << endl;
        }
        else {
            while (aux) {
                if (aux->getDato() == dato) {
                    encontrado = true;
                    break;
                }
                else {
                    encontrado = false;
                }
                aux = aux->getSiguiente();
                cont++;
            }
            if (encontrado == true) {
                cout << "\nEl dato " << dato << " se encuentra en la posicion " << cont + 1 << endl;
            }
            else {
                cout << "\nEl dato " << dato << " no se encuentra en la lista" << endl;
            }
        }
    }

    bool mostrar() {
        bool vacio = false;
        Nodo<T>* aux = inicio;
        if (inicio != NULL) {
            while (aux) {
                cout << aux->getDato() << " -> ";
                aux = aux->getSiguiente();
            }
            cout << "NULL" << endl;
        }
        else {
            cout << "\n\tLista vacia" << endl;
            return vacio = true;
        }
        cout << "La lista tiene " << tam << " elementos " << endl;
    }

    Nodo<T>* obtenerNodo(int indice) {
        if (indice < 0 || indice >= tam) {
            return nullptr;
        }

        int cont = 0;
        Nodo<T>* tmp = inicio;

        if (tmp == nullptr)
            return nullptr;

        do {
            if (cont == indice) {
                return tmp;
            }

            tmp = tmp->getSiguiente();
            cont++;
        } while (tmp != inicio);
        return nullptr;
    }


    void merge(int inicio, int mitad, int final) {
        
        int i, j, k;
        int elementosIzq = mitad - inicio + 1;
        int elementosDer = final - mitad;

        ListaSimple izquierda, derecha, mezcla;

        for (int i = 0; i < elementosIzq; i++) {
            izquierda.insertarPorFin(obtenerNodo(inicio + i)->getDato());
        }

        for (int j = 0; j < elementosDer; j++) {
            derecha.insertarPorFin(obtenerNodo(mitad + 1 + j)->getDato());
        }

        i = 0; 
        j = 0;
        k = inicio;

        while (i < elementosIzq && j < elementosDer) {
            if (izquierda.obtenerNodo(i)->getDato() <= derecha.obtenerNodo(j)->getDato()) {
                modificarPosicion(obtenerNodo(k), izquierda.obtenerNodo(i)->getDato());
                i++;
            }
            else {
                modificarPosicion(obtenerNodo(k), derecha.obtenerNodo(j)->getDato());
                j++;
            }
            k++;
        }

        while (j < elementosDer) {
            modificarPosicion(obtenerNodo(k), derecha.obtenerNodo(j)->getDato());
            j++;
            k++;
        }

        while (i < elementosIzq) {
            modificarPosicion(obtenerNodo(k), izquierda.obtenerNodo(i)->getDato());
            i++;
            k++;
        }
        
    }

    void mergeSort(int inicio, int final) {
        if (inicio < final) {
            int mitad = inicio + (final - inicio) / 2;
            mergeSort(inicio, mitad);
            mergeSort(mitad + 1, final);
            merge(inicio, mitad, final);
        }
    }

    void busquedaBinaria(int dato) {

        int inicio = 0; 
        int final = tam - 1;
        int mitad;
       
        while (inicio <= final) {
            
            mitad = (inicio + final) / 2;

            if (obtenerNodo(mitad)->getDato() == dato) {
                cout << "Dato Encontrado: " << dato << endl;
                break;
            }
            if (obtenerNodo(mitad)->getDato() > dato) {
                final = mitad;
                mitad = (inicio + final) / 2;
            }
            if (obtenerNodo(mitad)->getDato() < dato) { 
                inicio = mitad;
                mitad = (inicio + final) / 2;
            }
			if (mitad == 1) {
				cout << "Dato no encontrado" << endl;
				break;
			}
        }
    }

    void busquedaSecuencial(int dato) {
		bool encontrado = false;
        for (int i = 0; i < tam; i++) {
            if (obtenerNodo(i)->getDato() == dato) {
                cout << "Dato Encontrado: " << dato << endl;
				encontrado = true;
            } 
        }
		if (encontrado == false) {
			cout << "Dato no encontrado" << endl;
		}
    }

    void modificarDatoLista(int dato, int nuevoDato) {
        Nodo<T> *actual = inicio;
        while (actual) {
            if (actual->getDato() == dato) {
                actual->setDato(nuevoDato);
                break;
            }
            actual = actual->getSiguiente();
        }
    }

    void modificarPosicion(Nodo<T>* posicion, int nuevo) {
        Nodo<T>* actual = inicio;
        while (actual) {
            if (actual == posicion) {
                actual->setDato(nuevo);
                break;
            }
            actual = actual->getSiguiente();
        }
    }
    
};