
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
class Validaciones{
    public:
    int validarEnteros() {
		char* dato = new char[10];
		int i = 0;
		int numero;
		char c;
		while ((c = getch()) != 13) {

			if (c >= '0' && c <= '9') {

				dato[i++] = c;
				printf("%c", c);
				numero = atoi(dato);

			}
			else if (c == 8 && i != 0) {

				dato[i - 1] = 0;
				i--;

				putchar(8);
				putchar(32);
				putchar(8);
			}
		}
		dato[i] = '\0';
		return numero;
	}
};