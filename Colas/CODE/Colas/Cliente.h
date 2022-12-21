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

#if !defined(__ObjectOrientedModel_1_Cliente_h)
#define __ObjectOrientedModel_1_Cliente_h

#include <iostream>


class Cliente
{
public:

   int getTiempoLlegada(void);
   void setTiempoLlegada(int newTiempoLlegada);
   int getTiempoEspera(void);
   void setTiempoEspera(int newTiempoEspera);
   int getTiempoSinAtender(void);
   void setTiempoSinAtender(int newTiempoSinAtender);
   int getTiempoServicio(void);
   void setTiempoServicio(int newTiempoServicio);
   int getTiempoSalida(void);
   void setTiempoSalida(int newTiempoSalida);
   int getTiempoEntreLlegada(void);
   void setTiempoEntreLlegada(int newTiempoEntreLlegada);


   Cliente();
   ~Cliente();




protected:
private:
   int tiempoLlegada;
   int tiempoEspera;
   int tiempoSinAtender;
   int tiempoServicio;
   int tiempoSalida;
   int tiempoEntreLlegada;


};

#endif