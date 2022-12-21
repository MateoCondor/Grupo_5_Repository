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
        int contador=0;
        double promedioEspera=0;
        double promedioTiempoSinAtender=0;;
        double promedioTiempoServicio=0;
        double promedioTiempoEntreLlegada=0;

        size = cola.getSize();
        Nodo<Cliente> *aux = cola.getInicio();
        
        cout<<"====================================================================================================================================================="<<endl;
        std::cout << "Persona\tTiempo de llegada\tTiempo de espera\tTiempo sin atender\tTiempo de servicio\tTiempo de salida\tTiempo entre llegada\t" << endl;
        cout<<"====================================================================================================================================================="<<endl;
        while (aux != NULL)
        {

            std::cout<<contador+1<<"\t" << aux->getDato().getTiempoLlegada() << "\t\t\t" << aux->getDato().getTiempoEspera() << "\t\t\t" << aux->getDato().getTiempoSinAtender() << "\t\t\t" << aux->getDato().getTiempoServicio() << "\t\t\t" << aux->getDato().getTiempoSalida() << "\t\t\t" <<aux->getDato().getTiempoEntreLlegada() << "\t\t\t" << endl;
            std::cout << std::endl;
            promedioEspera+=aux->getDato().getTiempoEspera();
            promedioTiempoSinAtender+=aux->getDato().getTiempoSinAtender();
            promedioTiempoServicio+=aux->getDato().getTiempoServicio();
            promedioTiempoEntreLlegada+=aux->getDato().getTiempoEntreLlegada();
            aux = aux->getSiguiente();
            contador++;
        }
        promedioEspera=promedioEspera/size;
        promedioTiempoSinAtender=promedioTiempoSinAtender/size;
        promedioTiempoServicio=promedioTiempoServicio/size;
        promedioTiempoEntreLlegada=promedioTiempoEntreLlegada/size;
        cout<<"====================================================================================================================================================="<<endl;
        cout<<"Promedio -> Tiempo de espera: "<<promedioEspera<<endl;
        cout<<"Promedio -> tiempo sin atender: "<<promedioTiempoSinAtender<<endl;
        cout<<"Promedio -> tiempo de servicio: "<<promedioTiempoServicio<<endl;
        cout<<"Promedio -> tiempo entre llegada: "<<promedioTiempoEntreLlegada<<endl;
        cout<<"====================================================================================================================================================="<<endl;
    }
};
