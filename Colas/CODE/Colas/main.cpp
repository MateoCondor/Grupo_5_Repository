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

void mostrarMenu();

int main(int argc, char const *argv[])
{
    int cantidad = 0;
    int opc;
    Validaciones validacion;
    Cola<Persona> *colaPersonas = new Cola<Persona>();
    do
    {

        Cola<Cliente> *cola = new Cola<Cliente>();
        
        Generador *generador = new Generador();
        system("CLS");
        cout << "1. Ingresar Datos" << endl;
        cout << "2. Generar tabla por persona ingresada" << endl;
        cout << "3. Generar tabla aleatoreamente" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese la opcion que desea realizar:" << endl;
        opc = validacion.validarEnteros();
        cout << endl;
        switch (opc)
        {
        case 1:
            system("CLS");
            generador->generarPersona(*colaPersonas);
            generador->imprimirEdad(*colaPersonas);
            system("PAUSE");
            break;
        case 2:
            system("CLS");
            for (int i = 0; i < colaPersonas->getSize(); i++)
            {
                if (i == 0)
                {
                    generador->generarPrimerCliente(*cola);
                }
                else
                {
                    generador->generarCliente(*cola);
                }
            }

            generador->imprimirCola(*cola);
            delete cola;
            system("PAUSE");
            break;
        case 3:
            system("CLS");
            std::cout << "Ingrese la cantiadd de personas que desea generar:" << endl;
            cantidad = 0;
            cantidad = validacion.validarEnteros();
            cout << endl;

            for (int i = 0; i < cantidad; i++)
            {
                if (i == 0)
                {
                    generador->generarPrimerCliente(*cola);
                }
                else
                {
                    generador->generarCliente(*cola);
                }
            }
            generador->imprimirCola(*cola);
            delete cola;
            system("PAUSE");
            break;
        case 4:
            exit(0);

            break;
        default:
            system("CLS");
            cout << "Opc Error" << endl;
            system("PAUSE");
            break;
        }
    } while (opc > 0 || opc < 4);

    return 0;
}

void mostrarMenu()
{
}
