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

#if !defined(__ObjectOrientedModel_1_Funciones_h)
#define __ObjectOrientedModel_1_Funciones_h



class Funciones
{
public:

   int generarNumeroAleatorio (int , int );
   int maximo(int n1,int n2);
   int tiempoDeLlegada ( int tiempoDeLlegadaAnterior);
   int tiempoSalida (int tiempoLlegada, int tiempoEspera, int tiempoServicio) ;
   int tiempoServicio () ;
   int tiempoEntreLLegada (int tiempoLlegadaActual, int tiempoLlegadaAnterior, int tam);
   int tiempoEspera (int tiempoLlegadaActual, int tiempoSalidaAnterior) ;
   int tiempoNoTrabajaCajero(int tiempoLlegadaActual, int tiempoSalidaAnterior, int tam);

   Funciones();
   ~Funciones();

protected:
private:

};

#endif