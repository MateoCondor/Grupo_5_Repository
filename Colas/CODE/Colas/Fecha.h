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

#if !defined(__ObjectOrientedModel_1_Fecha_h)
#define __ObjectOrientedModel_1_Fecha_h

class Persona;

class Fecha
{
public:
   int getDia(void);
   void setDia(int newDia);
   int getMes(void);
   void setMes(int newMes);
   int getYear(void);
   void setYear(int newYear);
   Fecha();
   ~Fecha();


protected:
private:
   int dia;
   int mes;
   int year;


};

#endif