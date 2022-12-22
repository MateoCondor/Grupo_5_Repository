/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
        INGENIERA DE SOFTWARE

    AUTORES:
        Mateo Javier Condor Sosa
        Luis Ariel Burbano Pacheco
    FECHA DE CREACION:
        16/11/2022
    FECHA DE MODIFICACION:
        21/11/2022
*/
#pragma once
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "Nodo.hpp"
#include "Funciones.h"
#include "Persona.hpp"

template <typename T>

class ListaSimple : public Funciones
{
private:
    Nodo<T> *inicio = nullptr;
    Nodo<T> *fin = nullptr;
    int tam = 0;

public:
    Nodo<T> *getInicio()
    {
        return inicio;
    }

    Nodo<T> *getFin()
    {
        return fin;
    }

    int getTam()
    {
        return tam;
    }

    void setInicio(Nodo<T> *inicio)
    {
        this->inicio = inicio;
    }

    void setFin(Nodo<T> *fin)
    {
        this->fin = fin;
    }

    void setTam(int tam)
    {
        this->tam = tam;
    }

    void insertarPorInicio(T dato)
    {
        Nodo<T> *nuevo = new Nodo<T>(dato);
        if (this->inicio == NULL)
        {
            this->inicio = nuevo;
            this->fin = nuevo;
        }
        else
        {
            nuevo->setSiguiente(inicio);
            this->inicio = nuevo;
        }
        tam++;
    }

    void insertarPorFin(T dato)
    {
        Nodo<T> *nuevo = new Nodo<T>(dato);
        if (inicio == NULL)
        {
            inicio = nuevo;
            fin = nuevo;
        }
        else
        {
            fin->setSiguiente(nuevo);
            fin = nuevo;
        }
        tam++;
    }

    void insertarPorPosicion(T dato, int posicion)
    {
        Nodo<T> *nuevo = new Nodo<T>(dato);
        if (posicion == 0)
        {
            insertarPorInicio(dato);
        }
        else if (posicion == tam)
        {
            insertarPorFin(dato);
        }
        else if (posicion > 0 && posicion < tam)
        {
            Nodo<T> *aux = inicio;
            for (int i = 0; i < posicion - 1; i++)
            {
                aux = aux->getSiguiente();
            }
            nuevo->setSiguiente(aux->getSiguiente());
            aux->setSiguiente(nuevo);
            tam++;
        }
        else
        {
            cout << "\n\tPosicion no valida" << endl;
        }
    }

    void eliminarPorInicio()
    {
        if (inicio == NULL)
        {
            cout << "\n\tLista vacia" << endl;
        }
        else
        {
            Nodo<T> *aux = inicio;
            inicio = inicio->getSiguiente();
            delete aux;
            tam--;
        }
    }

    void eliminarPorFin()
    {
        if (inicio == NULL)
        {
            cout << "\n\tLista vacia" << endl;
        }
        else
        {
            Nodo<T> *aux = inicio;
            while (aux->getSiguiente() != fin)
            {
                aux = aux->getSiguiente();
            }
            delete fin;
            fin = aux;
            fin->setSiguiente(NULL);
            tam--;
        }
    }

    void eliminarPorPosicion(int posicion)
    {
        if (posicion == 0)
        {
            eliminarPorInicio();
        }
        else if (posicion == tam - 1)
        {
            eliminarPorFin();
        }
        else if (posicion > 0 && posicion < tam - 1)
        {
            Nodo<T> *aux = inicio;
            for (int i = 0; i < posicion - 1; i++)
            {
                aux = aux->getSiguiente();
            }
            Nodo<T> *aux2 = aux->getSiguiente();
            aux->setSiguiente(aux2->getSiguiente());
            delete aux2;
            tam--;
        }
        else
        {
            cout << "\n\tPosicion no valida" << endl;
        }
    }

    void buscar(T dato)
    {
        Nodo<T> *aux = inicio;
        int cont = 1;
        bool encontrado = false;
        if (inicio == NULL)
        {
            cout << "\n\tLista vacia" << endl;
        }
        else
        {
            while (aux)
            {
                if (aux->getDato() == dato)
                {
                    encontrado = true;
                    break;
                }
                else
                {
                    encontrado = false;
                }
                aux = aux->getSiguiente();
                cont++;
            }
            if (encontrado == true)
            {
                cout << "\nEl dato " << dato << " se encuentra en la posicion " << cont + 1 << endl;
            }
            else
            {
                cout << "\nEl dato " << dato << " no se encuentra en la lista" << endl;
            }
        }
    }

    bool mostrar()
    {
        bool vacio = false;
        Nodo<T> *aux = this->inicio;
        if (inicio != NULL)
        {
            while (aux)
            {
                cout << aux->getDato() << " -> ";
                aux = aux->getSiguiente();
            }
            cout << "NULL" << endl;
        }
        else
        {
            cout << "\n\tLista vacia" << endl;
            return vacio = true;
        }
        cout << "La lista tiene " << tam << " elementos " << endl;
    }

    int calcularMCD(int a, int b)
    {
        if (a == 0)
        {
            return b;
        }
        else if (b == 0)
        {
            return a;
        }
        else if (a == b)
        {
            return a;
            // return calcularMCD(b, a%b);
        }
        else if (a > b)
        {
            return calcularMCD(a - b, b);
        }
        return calcularMCD(a, b - a);
    }

    int calcularMCM(int a, int b)
    {
        return (a * b) / calcularMCD(a, b);
    }

    void mcmmcdDeLista()
    {
        Nodo<T> *aux = inicio;
        int mcm = 0;
        int mcd = 0;
        int a = 0;
        int b = 0;
        if (inicio == NULL)
        {
            cout << "\n\tLista vacia" << endl;
        }
        else if (inicio->getSiguiente() == NULL)
        {
            cout << "\n\tSolo hay un elemento en la lista" << endl;
            cout << "\n\tSe necesitan minimo 2 elementos" << endl;
        }
        else if (inicio != NULL)
        {
            a = aux->getDato();
            b = aux->getSiguiente()->getDato();
            mcm = calcularMCM(a, b);
            mcd = calcularMCD(a, b);
            while (aux->getSiguiente() != NULL)
            {
                aux = aux->getSiguiente();
                mcm = calcularMCM(mcm, aux->getDato());
                mcd = calcularMCD(mcd, aux->getDato());
            }
            cout << "\n\t~El MCM: " << mcm << endl;
            cout << "\n\t~El MCD: " << mcd << endl;
        }
    }

    bool mostrarPersonas(ListaSimple<Persona> &lista)
    {
        bool vacio = false;
        Nodo<Persona> *aux = lista.getInicio();
        if (aux != NULL)
        {
            while (aux)
            {
                cout << aux->getDato().getCedula() << ";" << aux->getDato().getApellido() << ";" << aux->getDato().getNombre() << " -> ";
                aux = aux->getSiguiente();
            }
            cout << "NULL" << endl;
        }
        else
        {
            cout << "\n\tLista vacia" << endl;
            return vacio = true;
        }
        cout << "La lista tiene " << tam << " elementos " << endl;
    }

    Nodo<Persona> *obtenerNodo(int indice)
    {
        if (indice < 0 || indice >= tam)
        {
            return nullptr;
        }

        int cont = 0;
        Nodo<Persona> *tmp = inicio;

        if (tmp == nullptr)
            return nullptr;

        do
        {
            if (cont == indice)
            {
                return tmp;
            }

            tmp = tmp->getSiguiente();
            cont++;
        } while (tmp != inicio);
        return nullptr;
    }

    void merge(int inicio, int mitad, int final)
    {
        int i, j, k;
        int elementosIzq = mitad - inicio + 1;
        int elementosDer = final - mitad;

        ListaSimple izquierda, derecha, mezcla;

        for (int i = 0; i < elementosIzq; i++)
        {
            izquierda.insertarPorFin(atoi(obtenerNodo(inicio + i)->getDato().getCedula()));
        }

        for (int j = 0; j < elementosDer; j++)
        {
            derecha.insertarPorFin(atoi(obtenerNodo(mitad + 1 + j)->getDato().getCedula()));
        }

        i = 0;
        j = 0;
        k = inicio;

        while (i < elementosIzq && j < elementosDer)
        {
            if (izquierda.obtenerNodo(i)->getDato() <= derecha.obtenerNodo(j)->getDato())
            {
                modificarPosicion(obtenerNodo(k), izquierda.obtenerNodo(i)->getDato());
                i++;
            }
            else
            {
                modificarPosicion(obtenerNodo(k), derecha.obtenerNodo(j)->getDato());
                j++;
            }
            k++;
        }

        while (j < elementosDer)
        {
            modificarPosicion(obtenerNodo(k), derecha.obtenerNodo(j)->getDato());
            j++;
            k++;
        }

        while (i < elementosIzq)
        {
            modificarPosicion(obtenerNodo(k), izquierda.obtenerNodo(i)->getDato());
            i++;
            k++;
        }
    }

    void mergeSort(int inicio, int final)
    {
        if (inicio < final)
        {
            int mitad = inicio + (final - inicio) / 2;
            mergeSort(inicio, mitad);
            mergeSort(mitad + 1, final);
            merge(inicio, mitad, final);
        }
    }
 
};
