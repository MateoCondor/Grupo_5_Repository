#include <iostream>

class Funciones{
    int tam = 0;
    public:
        virtual int calcularMCM(int a, int b) = 0;
        virtual int calcularMCD(int a, int b) = 0;

};