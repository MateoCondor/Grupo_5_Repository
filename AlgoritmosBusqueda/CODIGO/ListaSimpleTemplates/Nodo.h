#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Nodo {
private:
    T dato;
    Nodo* siguiente;

public:
    Nodo(T dato) {
        this->dato = dato;
        this->siguiente = nullptr;
    }

    ~Nodo() {

    }

    void setDato(T dato) {
        this->dato = dato;
    }

    void setSiguiente(Nodo* sig) {
        this->siguiente = sig;
    }

    T getDato() {
        return this->dato;
    }

    Nodo* getSiguiente() {
        return this->siguiente;
    }
};

