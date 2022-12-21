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
#include "Generador.hpp"


int main(int argc, char const *argv[])
{
    Cola<Cliente> *cola = new Cola<Cliente>();
    Generador *generador = new Generador();


    generador->generarPrimerCliente(*cola);
    generador->generarCliente(*cola);

    cout<<"Tiempo de llegada: "<<cola->getInicio()->getDato().getTiempoLlegada()<<endl;
    return 0;
}


