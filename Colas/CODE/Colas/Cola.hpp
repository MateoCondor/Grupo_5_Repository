/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
		INGENIERA DE SOFTWARE
                
	AUTORES:
		-Luis Burbano
        -Mateo Condor
        -Camila Morales
        -Ricardo Rivadeneira
        -Steven Pozo
        -Jairo Quilumbaquin
        -Edwin Cantuña

	FECHA DE CREACION:
		19/12/2022         	
	FECHA DE MODIFICACION:
		20/11/2022   
*/

#pragma once
#include <iostream>
#include "Nodo.hpp"

template <typename T>
class Cola{
    private:
        Nodo<T> *inicio=nullptr;
        Nodo<T> *fin=nullptr;
        int size=0;
    public:
        Cola(){
            this->inicio = NULL;
            this->fin = NULL;
        }

        ~Cola(){
            
        }
        
        Nodo<T>* getInicio(){
            return this->inicio;
        }

        Nodo<T>* getFin(){
            return this->fin;
        }

        int getSize(){
            return this->size;
        }

        void insertar(T dato){
            Nodo<T> *nuevo = new Nodo<T>(dato);
            if(this->inicio== NULL){
                this->inicio= nuevo;
                inicio->setSiguiente(NULL);
                this->fin = nuevo;
            }else{
                this->fin->setSiguiente(nuevo);
                nuevo->setSiguiente(NULL);
                this->fin = nuevo;
            }
            this->size++;
        }

        T eliminar(){
            T dato = this->inicio->getDato();
            Nodo<T> *aux = this->inicio;
            this->inicio = this->inicio->getSiguiente();
            delete aux;
            this->size--;
            return dato;
        }

        bool vacia(){
            return this->inicio== NULL;
        }

        void mostrar(){
            Nodo<T> *aux = this->inicio;
            while(aux != NULL){
                std::cout << aux->getDato() << " -> ";
                aux = aux->getSiguiente();
            }
            std::cout << " NULL ";
            std::cout << std::endl;
        }


};