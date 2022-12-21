#include "Cliente.cpp"
#include "Funciones.cpp"
#include "Utils.hpp"
#include "Cola.hpp"
#include "Validaciones.hpp"
#include "Persona.cpp"

using namespace std;

Funciones fun;
Validaciones vali;

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

    void generarPersona(Cola<Persona> &cola)
    {
        Persona persona;
        Fecha fecha;
        std::string nombre;
        std::string cedula;
        std::string apellido;
        time_t hoy = time(0);
        tm *fechaActual = localtime(&hoy);
        int yearActual = 1900 + fechaActual->tm_year;
        int dia = 0;
        int mes = 0;
        int year = 0;

        while (true)
        {
            cedula = vali.leerCadena1("Ingrese la cedula: ", "^[0-9]{10}$");
            if (!vali.cedula_valida(cedula))
            {
                cout << "Cedula Invalida" << endl;
                continue;
            }
            else
            {
                break;
            }
        }
        nombre = vali.ingresoNombreApellido("Ingrese el nombre de la persona: ");
        std::cout << endl;
        apellido = vali.ingresoNombreApellido("Ingrese el apellido de la persona: ");
        std::cout << endl;
        persona.setCedula(cedula);
        persona.setNombre(nombre);
        persona.setApellido(apellido);
        cout << "Ingrese la fecha de nacimiento de la persona" << endl;
        while (true)
        {
            cout << endl
                 << "Dia: ";
            dia = vali.validarEnteros();
            if (dia <= 31 && dia >= 1)
            {
                break;
            }
        }

        while (true)
        {

            cout << endl
                 << "Mes: ";
            mes = vali.validarEnteros();
            if (mes <= 12 && mes >= 1)
            {
                break;
            }
        }

        while (true)
        {
            cout << endl
                 << "Year: ";
            year = vali.validarEnteros();
            if (year < yearActual && year >= 1900)
            {
                break;
            }
        }

        fecha.setDia(dia);
        fecha.setMes(mes);
        fecha.setYear(year);
        persona.setFecha(fecha);
        cout << endl
             << "Persona generada" << endl;
        cola.insertar(persona);
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
        int contador = 0;
        double promedioEspera = 0;
        double promedioTiempoSinAtender = 0;
        ;
        double promedioTiempoServicio = 0;
        double promedioTiempoEntreLlegada = 0;

        size = cola.getSize();
        Nodo<Cliente> *aux = cola.getInicio();

        cout << "=====================================================================================================================================================" << endl;
        std::cout << "Persona\tTiempo de llegada\tTiempo de espera\tTiempo sin atender\tTiempo de servicio\tTiempo de salida\tTiempo entre llegada\t" << endl;
        cout << "=====================================================================================================================================================" << endl;
        while (aux != NULL)
        {

            std::cout << contador + 1 << "\t" << aux->getDato().getTiempoLlegada() << "\t\t\t" << aux->getDato().getTiempoEspera() << "\t\t\t" << aux->getDato().getTiempoSinAtender() << "\t\t\t" << aux->getDato().getTiempoServicio() << "\t\t\t" << aux->getDato().getTiempoSalida() << "\t\t\t" << aux->getDato().getTiempoEntreLlegada() << "\t\t\t" << endl;
            std::cout << std::endl;
            promedioEspera += aux->getDato().getTiempoEspera();
            promedioTiempoSinAtender += aux->getDato().getTiempoSinAtender();
            promedioTiempoServicio += aux->getDato().getTiempoServicio();
            promedioTiempoEntreLlegada += aux->getDato().getTiempoEntreLlegada();
            aux = aux->getSiguiente();
            contador++;
        }
        promedioEspera = promedioEspera / size;
        promedioTiempoSinAtender = promedioTiempoSinAtender / size;
        promedioTiempoServicio = promedioTiempoServicio / size;
        promedioTiempoEntreLlegada = promedioTiempoEntreLlegada / size;
        cout << "=====================================================================================================================================================" << endl;
        cout << "Promedio -> Tiempo de espera: " << promedioEspera << endl;
        cout << "Promedio -> tiempo sin atender: " << promedioTiempoSinAtender << endl;
        cout << "Promedio -> tiempo de servicio: " << promedioTiempoServicio << endl;
        cout << "Promedio -> tiempo entre llegada: " << promedioTiempoEntreLlegada << endl;
        cout << "=====================================================================================================================================================" << endl;
    }

    void imprimirColaPersonas(Cola<Persona> &colaPersona)
    {
        Nodo<Persona> *aux = colaPersona.getInicio();
        while (aux != NULL)
        {
            std::cout << aux->getDato().getCedula() << "\t" << aux->getDato().getNombre() << "\t" << aux->getDato().getApellido() << endl;
            std::cout << std::endl;
            aux = aux->getSiguiente();
        }
    }
    int calcularEdad(int diaNacimiento, int mesNacimiento, int yearNacimiento)
    {
        time_t hoy = time(0);
        int anioActual;

        tm *fechaActual = localtime(&hoy);

        // OBTENER LA FECHA ACTUAL
        int anio = 1900 + fechaActual->tm_year;
        int mes = 1 + fechaActual->tm_mon;
        int dia = fechaActual->tm_mday;

        // CALCULAR LA EDAD
        if (mesNacimiento < mes)
        {
            anioActual = anio - yearNacimiento;
        }
        else if (mesNacimiento == mes)
        {
            if (diaNacimiento < dia)
            {
                anioActual = anio - yearNacimiento;
            }
            else
            {
                anioActual = anio - yearNacimiento - 1;
            }
        }
        else
            anioActual = anio - yearNacimiento - 1;

        return anioActual;
    }

    void imprimirEdad(Cola<Persona> &colaPersona)
    {
        int contador = 0;
        Nodo<Persona> *aux = colaPersona.getInicio();
        while (aux != NULL)
        {
            std::cout << contador + 1 << "--->"
                      << "La edad de " << aux->getDato().getNombre() + " " + aux->getDato().getApellido() << " con cedula: " << aux->getDato().getCedula() << " es: " << calcularEdad(aux->getDato().getFecha().getDia(), aux->getDato().getFecha().getMes(), aux->getDato().getFecha().getYear()) << endl;
            std::cout << std::endl;
            contador++;
            aux = aux->getSiguiente();
        }
    }
};
