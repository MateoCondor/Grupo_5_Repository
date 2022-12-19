/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS
         ~~ ESPE ~~
     INGENIERIA EN SOFTWARE
           GRUPO #5
MIEMBROS:
    - Luis Burbano
    - Mateo Condor
    - Camila Morales
    - Ricardo Rivadeneira
    - Steven Pozo
    - Jairo Quilumbaquin
    - Edwin Cantuña
Fecha de creacion:
    - 12 / 12 / 2022
Fecha de modificacion:
    - 18 / 12 / 2022
*/

#include <iostream>
#include <conio.h>
#include <string.h>
#include "ValidarDatos.h"

int ValidarDatos::validarEntero(char const* mensaje) {
    std::string dato;
    char c;
    int i = 0, valor = 0;
    std::cout << mensaje;
    while ((c = _getch()) != 13) {
        if ((c >= '0' && c <= '9') || c == 8) {
            if (c == 8) {
                dato.erase(i - 1);
                i--;
                std::cout << "\b";
                std::cout << " ";
                std::cout << "\b";
            }
            else {
                std::cout << c;
                dato += c;
                i++;
            }
        }
    }
    std::cout << std::endl;
    valor = stoi(dato);
    return valor;
}

float ValidarDatos::validarDoubles(char const* mensaje) {
    std::string dato;
    char c;
    int i = 0, it_punto = 0;
    float valor = 0;
    std::cout << mensaje;
    while ((c = _getch()) != 13) {
        if ((c >= '0' && c <= '9') || c == '.' || c == 8) {
            if (c == 8) {
                if (dato[i - 1] == '.') {
                    it_punto = 0;
                }
                dato.erase(i - 1);
                i--;
                std::cout << "\b";
                std::cout << " ";
                std::cout << "\b";
            }
            else if (c != '.') {
                std::cout << c;
                dato += c;
                i++;
            }
            else {
                if (it_punto < 1) {
                    std::cout << c;
                    dato += c;
                    i++;
                    it_punto += 1;
                }
            }
        }
    }
    std::cout << std::endl;
    valor = stof(dato);
    return valor;
}

std::string ValidarDatos::validarLetras(char const* mensaje) {
    std::string dato;
    char c;
    int i = 0;
    std::cout << mensaje;
    while ((c = _getch()) != 13) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ' || c == 8) {
            if (c == 8) {
                dato.erase(i - 1);
                i--;
                std::cout << "\b";
                std::cout << " ";
                std::cout << "\b";
            }
            else {
                std::cout << c;
                dato += c;
                i++;
            }
        }
    }
    std::cout << std::endl;
    return dato;
}

bool ValidarDatos::confirmar(std::string mensaje) {
    bool confirmado;

    do {
        char input;
        std::cout << mensaje << " (s/n): ";
        std::cin >> input;
        bool invalido = std::cin.fail();

        std::cin.clear();
        std::cin.ignore(9999, '\n');

        if (invalido || (tolower(input) != 's' && tolower(input) != 'n')) {
            continue;
        }

        confirmado = tolower(input) == 's';
        break;
    } while (true);

    return confirmado;
}
