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


std::string Persona::getCedula(void)
{
   return cedula;
}


void Persona::setCedula(std::string newCedula)
{
   cedula = newCedula;
}


std::string Persona::getNombre(void)
{
   return nombre;
}



void Persona::setNombre(std::string newNombre)
{
   nombre = newNombre;
}



std::string Persona::getApellido(void)
{
   return apellido;
}


void Persona::setApellido(std::string newApellido)
{
   apellido = newApellido;
}

Fecha Persona::getFecha(void)
{
   return fecha;
}

void Persona::setFecha(Fecha newFecha)
{
   fecha = newFecha;
}


Persona::Persona()
{
   
   this->fecha.setDia(0);
   this->fecha.setMes(0);
   this->fecha.setYear(0);
}


Persona::~Persona()
{
   // TODO : implement
}