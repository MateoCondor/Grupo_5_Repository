#include <iostream>
#include "ListaSimple.h"
#include "Hash.h"
#include "ValidarDatos.h"

using namespace std;

int main() {

    
    ValidarDatos val;
    ListaSimple<int> lista;
    Hash hash(7);



    int dato;
    int opcion;
    bool repetir = true;

    do {
        system("cls");
        cout << "\t\t\t------------------------------------" << endl;
        cout << "\n\t  1. Ingresar un Elemento a la Lista" << endl;
        cout << "\t  2. Mostrar Lista" << endl;
        cout << "\t  3. Ordenar Lista" << endl;
        cout << "\t  4. Busqueda Binaria" << endl;
        cout << "\t  5. Busqueda Secuencial" << endl;
        cout << "\t  6. Busqueda Hash" << endl;
        cout << "\t  0. Regresar" << endl;

        cout << endl;
        opcion = val.validarEntero("ingrese una opcion: ");

        switch (opcion) {
        case 1:
            cout << endl;
            dato = val.validarEntero("Ingrese un Numero: ");
            cout << endl;
            lista.insertarPorFin(dato);
            break;

        case 2:
            cout << endl;
            lista.mostrar();
            system("pause>nul");
            break;

        case 3:
            cout << endl;
            lista.mergeSort(0, lista.obtenerTamanio() - 1);
            system("pause>nul");
            break;

        case 4:
            cout << endl;
            dato = val.validarEntero("Ingrese el numero a buscar: ");
            lista.busquedaBinaria(dato);
            system("pause>nul");
            break;

        case 5:
            cout << endl;
            dato = val.validarEntero("Ingrese el numero a buscar: ");
            lista.busquedaSecuencial(dato);
            system("pause>nul");
            break;

        case 6:
            do {
                system("cls");
                cout << "\t\t\t-------------------------------" << endl;
                cout << "\n\t  1. Ingresar" << endl;
                cout << "\t  2. Eliminar" << endl;
                cout << "\t  3. Buscar" << endl;
                cout << "\t  4. Imprimir" << endl;
                cout << "\t  0. Regresar" << endl;

                cout << endl;
                opcion = val.validarEntero("Ingrese una opcion: ");

                switch (opcion) {
                case 1:
                    cout << endl;
                    dato = val.validarEntero("Ingrese un Numero: ");
                    cout << endl;
                    hash.insertarItem(dato);
                    system("pause>nul");
                    break;

                case 2:
                    cout << endl;
                    dato = val.validarEntero("Ingrese un Numero: ");
                    cout << endl;
                    hash.borrarItem(dato);
                    system("pause>nul");
                    break;

                case 3:
                    cout << endl;
                    dato = val.validarEntero("Ingrese un Numero: ");
                    cout << endl;
                    hash.buscarItem(dato);
                    system("pause>nul");
                    break;

                case 4:
                    cout << endl;
                    hash.imprimir();
                    system("pause>nul");
                    break;

                case 0:
                    repetir = false;
                    break;
                }
            } while (repetir);
            repetir = true;
        break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
}
