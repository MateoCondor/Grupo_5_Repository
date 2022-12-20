#include <iostream>
#include "ListaSimple.h"


using namespace std;

int main() {

    int dato;

    
    ListaSimple<int> lista;

    for (int i = 0; i < 5; i++) {
		cin >> dato;
        lista.insertarPorFin(dato);
    }

    cout << "Lista Desordenada" << endl;
    lista.mostrar();
    cout << endl;

    lista.mergeSort(0, 4); // Se manda el 0 y el tamanio de la lista -1
    
    cout << "Lista Ordenada" << endl;
    lista.mostrar();
    cout << endl;
    
    cout << "Busqueda Binaria" << endl;
    lista.busquedaBinaria(8);  // Funciona solo con los datos ordenados
    cout << endl;

    cout << "Busqueda Secuencial" << endl;
    lista.busquedaSecuencial(8);

}

