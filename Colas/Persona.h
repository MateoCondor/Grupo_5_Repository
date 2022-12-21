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

#if !defined(__ObjectOrientedModel_1_Persona_h)
#define __ObjectOrientedModel_1_Persona_h

#include <iostream>
#include "Fecha.h"

class Persona
{
public:
   std::string getCedula(void);
   void setCedula(std::string newCedula);
   std::string getNombre(void);
   void setNombre(std::string newNombre);
   Fecha getFecha(void);
   void setFecha(Fecha newFecha);
   std::string getApellido(void);
   void setApellido(std::string newApellido);
   Persona();
   ~Persona();


protected:
private:
   std::string cedula;
   std::string nombre;
   Fecha fecha;
   std::string apellido;


};

#endif