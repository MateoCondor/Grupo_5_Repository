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


#include "Animacion.h"
#include <Windows.h>
#include <windows.h>
#include <iostream>

void Animacion::gotoxi(int x, int y) {
	HANDLE HCon;
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	HCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(HCon, dwPos);
}

std::string Animacion::generarFilas(int dato) {
	int limite = 0;
	char a = 223;
	std::string fil = "";

	if (dato >= 100) {
		limite = 100;
	}
	else {
		limite = dato;
	}

	for (int i = 0; i < limite; i++) {
		fil += a;
	}

	return fil;
}



