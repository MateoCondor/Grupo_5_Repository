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
    int cantidad=0;
    Cola<Cliente> *cola = new Cola<Cliente>();
    Generador *generador = new Generador();

    std::cout<<"Ingrese la cantiadd de personas que desea generar:"<<endl;
    std::cin>>cantidad;

    for (int i = 0; i < cantidad; i++)
    {
        if (i==0)
        {
            generador->generarPrimerCliente(*cola);            
        }else{
            generador->generarCliente(*cola);
        }
        
    }
    
    generador->imprimirCola(*cola);
    return 0;
}


