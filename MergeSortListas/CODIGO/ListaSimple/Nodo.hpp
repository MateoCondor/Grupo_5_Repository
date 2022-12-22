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
using namespace std;

template <typename T>

class Nodo {
    private:
        private:
        T dato;
        Nodo *siguiente;

    public:
        
        Nodo(T dato){
            this->dato = dato;
            this->siguiente = NULL;
        }

        ~Nodo(){
            
        }

        void setDato(T dato){
            this->dato = dato;
        }

        void setSiguiente(Nodo *sig){
            this->siguiente = sig;
        }

        T getDato(){
            return this->dato;
        }

        Nodo *getSiguiente(){
            return this->siguiente;
        }

};
