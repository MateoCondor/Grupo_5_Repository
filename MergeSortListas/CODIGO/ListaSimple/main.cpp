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
		03/12/2023   
*/

#include <iostream>
#include "ListaSimple.hpp"
#include "Validacion.hpp"


using namespace std;

int main() {
        ListaSimple<Persona> *lista = new ListaSimple<Persona>();
        int opcion;
        Persona *persona = new Persona();
        Validacion validacion;
        do{
                system("cls");
                cout<<"|----------------------------------------------------------------|"<<endl;
                cout<<"|                     .:MENU Lista Simple:.                      |"<<endl;
                cout<<"!----------------------------------------------------------------|"<<endl;
                cout<<"|                   ~ 1. Insertar dato en la lista ~             |"<<endl;
                cout<<"|                   ~ 2. Ordenar por Cedula ~                    |"<<endl;
                cout<<"|                   ~ 3. Ordenar por Apellido ~                  |"<<endl;
                cout<<"|                   ~ 4. Mostrar lista ~                         |"<<endl;
                cout<<"|                   ~ 0. Salir ~                                 |"<<endl;
                cout<<"|----------------------------------------------------------------|"<<endl;
                opcion = validacion.charToInt();

                switch(opcion){
                case 1:
                        cout<<"\nIngrese los datos de la persona: "<<endl;
                        persona->ingresarPersona();
                        lista->insertarPorFin(*persona);
                        cout<<"\n";
                        system("pause");
                        break;
                case 2:
                        cout<<"\n";
                        lista->mergeSort(0,lista->getTam()-1);
                        lista->mostrarPersonas(*lista);
                        system("pause");
                        break;
                case 3:
                        cout<<"\n";
                        lista->mergeSortApellido(0,lista->getTam()-1);
                        lista->mostrarPersonas(*lista);
                        system("pause");
                        break;
                case 4:
                        cout<<"\n";
                        lista->mostrarPersonas(*lista);
                        system("pause");
                        break;
                }

         }while(opcion != 0);

        

}
