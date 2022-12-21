#include "Cliente.cpp"
#include "Funciones.cpp"
#include "Utils.hpp"
#include "Cola.hpp"

using namespace std;

Funciones fun;

class Generador
{
private:
public:
    Generador(/* args */)
    {
    }

    ~Generador()
    {
    }

    void generarCliente(Cola<Cliente> &cola)
    {
        Cliente cliente;
        int tiempoEntreLlegada = 0;
        int tiempoLlegada = 0;
        int tiempoEspera = 0;
        int tiempoSinAtender = 0;
        int tiempoServicio = 0;
        int tiempoSalida = 0;

        tiempoLlegada = fun.tiempoDeLlegada(cola.getFin()->getDato().getTiempoLlegada());
        tiempoEntreLlegada = fun.tiempoEntreLLegada(tiempoLlegada, cola.getFin()->getDato().getTiempoLlegada(), 2);
        tiempoEspera = fun.tiempoEspera(tiempoLlegada, cola.getFin()->getDato().getTiempoSalida());
        tiempoSinAtender = fun.tiempoNoTrabajaCajero(tiempoLlegada, cola.getFin()->getDato().getTiempoSalida(), 2);
        tiempoServicio = fun.tiempoServicio();
        tiempoSalida = fun.tiempoSalida(tiempoLlegada, tiempoEspera, tiempoServicio);

        cliente.setTiempoEntreLlegada(tiempoEntreLlegada);
        cliente.setTiempoLlegada(tiempoLlegada);
        cliente.setTiempoEspera(tiempoEspera);
        cliente.setTiempoSinAtender(tiempoSinAtender);
        cliente.setTiempoServicio(tiempoServicio);
        cliente.setTiempoSalida(tiempoSalida);

        cola.insertar(cliente);
    }

    void generarPrimerCliente(Cola<Cliente> &cola)
    {

        Cliente cliente;
        int tiempoEntreLlegada = 0;
        int tiempoLlegada = 0;
        int tiempoEspera = 0;
        int tiempoSinAtender = 0;
        int tiempoServicio = 0;
        int tiempoSalida = 0;

        
        tiempoLlegada = fun.tiempoDeLlegada(0);
        tiempoEntreLlegada = fun.tiempoEntreLLegada(tiempoLlegada, 0, 1);
        tiempoEspera = fun.tiempoEspera(0, 0);
        tiempoSinAtender = fun.tiempoNoTrabajaCajero(0, 0, 1);
        tiempoServicio = fun.tiempoServicio();
        tiempoSalida = fun.tiempoSalida(tiempoLlegada, 0, tiempoServicio);

        cliente.setTiempoEntreLlegada(tiempoEntreLlegada);
        cliente.setTiempoLlegada(tiempoLlegada);
        cliente.setTiempoEspera(tiempoEspera);
        cliente.setTiempoSinAtender(tiempoSinAtender);
        cliente.setTiempoServicio(tiempoServicio);
        cliente.setTiempoSalida(tiempoSalida);

        cola.insertar(cliente);
    }

    void imprimirCola(Cola<Cliente> &cola)
    {
        int size = 0;

        Nodo<Cliente> *aux = cola.getInicio();
        

        std::cout << "Persona\tTiempo de llegada\tTiempo de espera\tTiempo sin atender\tTiempo de servicio\tTiempo de salida\tTiempo entre llegada\t" << endl;
        while (aux != NULL)
        {

            std::cout<<size+1<<"\t" << aux->getDato().getTiempoLlegada() << "\t\t\t" << aux->getDato().getTiempoEspera() << "\t\t\t" << aux->getDato().getTiempoSinAtender() << "\t\t\t" << aux->getDato().getTiempoServicio() << "\t\t\t" << aux->getDato().getTiempoSalida() << "\t\t\t" <<aux->getDato().getTiempoEntreLlegada() << "\t\t\t" << endl;
            std::cout << std::endl;
            aux = aux->getSiguiente();
            size++;
        }

    }
};
