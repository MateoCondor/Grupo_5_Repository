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
    - Edwin Cantu?a

Fecha de creacion:
    - 12 / 12 / 2022

Fecha de modificacion:
    - 18 / 12 / 2022

*/


#pragma once
#include <cctype>
#include <algorithm>
#include <iostream>
#include <string>
#include <regex>

namespace val {
    float leerNumero(std::string mensaje) {
        std::regex patron("^(?=.)([+-]?([0-9]*)(\\.([0-9]+))?)$");
        std::string entrada;
        float salida;

        while (true) {
            std::cout << mensaje;
            std::getline(std::cin, entrada);
            entrada = (entrada);

            if (!std::regex_match(entrada, patron)) {
                continue;
            }

            salida = std::stof(entrada);

            break;
        }

        return salida;
    }

    bool confirmar(std::string mensaje) {
        bool confirmado;

        do {
            char input;
            std::cout << mensaje << " (S/N): ";
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

}