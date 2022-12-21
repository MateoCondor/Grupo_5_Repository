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

#include "Cliente.h"



int Cliente::getTiempoLlegada(){
    return tiempoLlegada;
}

void Cliente::setTiempoLlegada(int tiempoLlegada){
    this->tiempoLlegada = tiempoLlegada;
}

int Cliente::getTiempoEspera(){
    return tiempoEspera;
}

void Cliente::setTiempoEspera(int tiempoEspera){
    this->tiempoEspera = tiempoEspera;
}

int Cliente::getTiempoSinAtender(){
    return tiempoSinAtender;
}

void Cliente::setTiempoSinAtender(int tiempoSinAtender){
    this->tiempoSinAtender = tiempoSinAtender;
}

int Cliente::getTiempoServicio(){
    return tiempoServicio;
}

void Cliente::setTiempoServicio(int tiempoServicio){
    this->tiempoServicio = tiempoServicio;
}

int Cliente::getTiempoSalida(){
    return tiempoSalida;
}

void Cliente::setTiempoSalida(int tiempoSalida){
    this->tiempoSalida = tiempoSalida;
}

int Cliente::getTiempoEntreLlegada(){
    return tiempoEntreLlegada;
}

void Cliente::setTiempoEntreLlegada(int tiempoEntreLlegada){
    this->tiempoEntreLlegada = tiempoEntreLlegada;
}

Cliente::Cliente()
{
}

Cliente::~Cliente()
{
}