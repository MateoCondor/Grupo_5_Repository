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
template <typename T>
class Nodo{
    private:
        T dato;
        Nodo<T> *siguiente;
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

        T getDato(){
            return this->dato;
        }

        void setSiguiente(Nodo<T> *siguiente){
            this->siguiente = siguiente;
        }

        Nodo<T> *getSiguiente(){
            return this->siguiente;
        }

};