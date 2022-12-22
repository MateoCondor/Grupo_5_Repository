#include <iostream>

using namespace std;

class Persona{
    private:
        string cedula;
        string nombre;
        string apellido;

    public:
        
        Persona(string cedula, string nombre, string apellido){
            this -> cedula = cedula;
            this -> nombre = nombre;
            this -> apellido = apellido;
        }

        Persona(){

        }

        string getCedula(){
            return cedula;
        }

        string getNombre(){
            return nombre;
        }

        string getApellido(){
            return apellido;
        }

        void setCedula(string cedula){
            this -> cedula = cedula;
        }

        void setNombre(string nombre){
            this -> nombre = nombre;
        }

        void setApellido(string apellido){
            this -> apellido = apellido;
        }

        
            

        
};