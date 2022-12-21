#include <iostream>
#include "ListaSimple.h"
#include "ValidarDatos.h"

using namespace std;

int main() {

    ValidarDatos val;
    ListaSimple<int> lista;

    int dato;
    int opcion;
    bool repetir = true;

    do {
        system("cls");
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. Ingresar un Elemento a la Lista" << endl;
        cout << "\t  2. Mostrar Lista" << endl;
        cout << "\t  3. Ordenar Lista" << endl;
        cout << "\t  4. Busqueda Binaria" << endl;
        cout << "\t  5. Busqueda Secuencial" << endl;
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

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);

    /*
    cout << "Lista Desordenada" << endl;
    lista.mostrar();
    cout << endl;

    lista.mergeSort(0, lista.obtenerTamanio() - 1); // Se manda el 0 y el tamanio de la lista -1
    
    cout << "Lista Ordenada" << endl;
    lista.mostrar();
    cout << endl;
    
    cout << "Busqueda Binaria" << endl;
    lista.busquedaBinaria(8);  // Funciona solo con los datos ordenados
    cout << endl;

    cout << "Busqueda Secuencial" << endl;
    lista.busquedaSecuencial(8);
    cout << endl;
    */

}

