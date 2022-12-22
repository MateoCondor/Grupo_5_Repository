/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
		INGENIERA DE SOFTWARE
                
	AUTORES:
		Mateo Javier Condor Sosa 	 
		Luis Ariel Burbano Pacheco       
	FECHA DE CREACION:
		16/11/2022         	
	FECHA DE MODIFICACION:
		21/11/2022   
*/

#include <iostream>
#include "ListaSimple.hpp"
#include "Validacion.hpp"


using namespace std;

int main() {
        ListaSimple<Persona> *lista = new ListaSimple<Persona>();
        Persona p1 = Persona("172832", "Mateo", "Condor");
        Persona p2 = Persona("172232", "Luis", "Burbano");

        lista->insertarPorInicio(p1);
        lista->insertarPorInicio(p2);

        lista->mostrarPersonas(*lista);


        /*int opcion;
        int dato;
        int posicion;
        ListaSimple<int> lista;
        Validacion validacion;
        do{
                system("cls");
                cout<<"|----------------------------------------------------------------|"<<endl;
                cout<<"|                     .:MENU Lista Simple:.                      |"<<endl;
                cout<<"!----------------------------------------------------------------|"<<endl;
                cout<<"| 1. Insertar dato por cabeza    | 4. Eliminar dato por cabeza   |"<<endl;
                cout<<"| 2. Insertar dato por cola      | 5. Eliminar dato por cola     |"<<endl;
                cout<<"| 3. Insertar dato por posicion  | 6. Eliminar dato por posicion |"<<endl;
                cout<<"!----------------------------------------------------------------|"<<endl;
                cout<<"|                    ~ 7. Mostrar lista ~                        |"<<endl;
                cout<<"|                    ~ 8. Buscar dato ~                          |"<<endl;
                cout<<"|                    ~ 9. MCM Y MCD ~                            |"<<endl;
                cout<<"|                    ~ 0. Salir ~                                |"<<endl;
                cout<<"|----------------------------------------------------------------|"<<endl;
                opcion = validacion.charToInt();

                switch (opcion){
                        case 1:
                                cout<<"\nIngrese el dato que se va ingresar por cabeza: ";
                                dato = validacion.charToInt();
                                lista.insertarPorInicio(dato);
                                cout<<"\n";
                                system("pause");
                                break;
                        case 2:
                                cout<<"\nIngrese el dato que se va ingresar por cola: ";
                                dato = validacion.charToInt();
                                lista.insertarPorFin(dato);
                                cout<<"\n";
                                system("pause");
                                break;
                        case 3:
                                cout << "\n" << endl;
                                if(lista.mostrar() == true){
                                system("pause");
                                }else {
                                cout<<"\nIngrese el dato que se va ingresar por posicion: ";
                                dato = validacion.charToInt();
                                cout<<"\nIngrese la posicion donde se va a insertar el dato: ";
                                posicion = validacion.charToInt();
                                lista.insertarPorPosicion(dato,posicion);
                                cout<<"\n";
                                system("pause");
                                }
                                break;
                        case 4:
                                lista.eliminarPorInicio();
                                cout<<"\n";
                                system("pause");
                                break;
                        case 5:
                                lista.eliminarPorFin();
                                cout<<"\n";
                                system("pause");
                                break;
                        case 6:
                                cout << "\n" << endl;
                                if(lista.mostrar() == true){
                                system("pause");
                                }else {
                                cout<<"\nIngrese la posicion del dato que se va a eliminar: ";
                                posicion = validacion.charToInt();
                                lista.eliminarPorPosicion(posicion);
                                cout<<"\n";
                                system("pause"); 
                                }
                                break;

                        case 7:
                                cout<<"\n";
                                lista.mostrar();
                                cout<<"\n";
                                system("pause");
                                break;

                        case 8:
                                cout<<"\nIngrese el dato que se va a buscar: ";
                                dato = validacion.charToInt();
                                lista.buscar(dato);
                                cout<<"\n";
                                system("pause");
                                break;
                        case 9:
                                cout<<"\n";
                                lista.mcmmcdDeLista();
                                cout<<"\n";
                                system("pause");
                                break;
                        case 0:
                                cout<<"\n\n\tSaliendo... \nGracias por usar nuestro programa!"<<endl;
                                break;
                }
        }while(opcion != 0);*/

}
