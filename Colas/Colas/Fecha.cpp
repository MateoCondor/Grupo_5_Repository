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

#include "Persona.h"
#include "Fecha.h"



int Fecha::getDia(void)
{
   return dia;
}


void Fecha::setDia(int newDia)
{
   dia = newDia;
}


int Fecha::getMes(void)
{
   return mes;
}


void Fecha::setMes(int newMes)
{
   mes = newMes;
}


int Fecha::getYear(void)
{
   return year;
}


void Fecha::setYear(int newYear)
{
   year = newYear;
}


Fecha::Fecha()
{
   persona = NULL;
}

Fecha::~Fecha()
{
   // TODO : implement
}