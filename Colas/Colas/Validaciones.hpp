#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <random>
#include <cctype>
#include <regex>
#include <iomanip>
#include <sstream>
#include <cfloat>
#include <Windows.h>
#include <conio.h>

using namespace std;
class Validaciones
{
public:
	int validarEnteros()
	{
		char *dato = new char[10];
		int i = 0;
		int numero;
		char c;
		while ((c = getch()) != 13)
		{

			if (c >= '0' && c <= '9')
			{

				dato[i++] = c;
				printf("%c", c);
				numero = atoi(dato);
			}
			else if (c == 8 && i != 0)
			{

				dato[i - 1] = 0;
				i--;

				putchar(8);
				putchar(32);
				putchar(8);
			}
		}
		dato[i] = '\0';
		return numero;
		delete dato;
	}
	char *ingresoNombreApellido(char const *msj)
	{
		char *a = new char[0];
		char c;
		int i = 0;
		cout << msj;
		while ((c = getch()) != 13)
		{
			if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
			{
				cout << c;
				a[i++] = c;
			}
			else if (c == '\b')
			{
				i--;
				cout << "\b \b";
			}
			if (a[0] >= 'a' && a[0] <= 'z')
			{
				a[0] = a[0] - 32;
			}
		}
		a[i] = '\0';
		return a;
	}
	static std::string leer_cadena(const std::string etiqueta, bool permitir_vacio = false)
	{
		std::string leido;

		if (permitir_vacio)
		{
			std::getline(std::cin, leido);
		}
		else
		{
			while ((std::cout << etiqueta),
				   std::getline(std::cin, leido), leido.empty())
				;
		}

		return leido;
	}

	static std::string leerCadena1(const std::string etiqueta, std::string regex)
	{
		rewind(stdin);
		std::string leido;
		std::regex cadena_regex(regex);

		do
		{
			leido = leer_cadena(etiqueta);

			if (!std::regex_match(leido, cadena_regex))
			{
				std::cout << "Formato Incorrecto" << std::endl;
			}
		} while (!std::regex_match(leido, cadena_regex));
		rewind(stdin);
		return leido;
	}

	static bool cedula_valida(const std::string cedula)
	{
		if (cedula.length() != 10)
		{
			return false;
		}

		int sum_par = 0;
		int sum_impar = 0;
		int sum;
		int i = 1;

		std::string digitos = cedula.substr(0, cedula.size() - 1);

		for (char &c : digitos)
		{
			int digito = c - '0';
			if (i % 2 == 0)
			{
				sum_par += digito;
			}
			else
			{
				if ((digito * 2) > 9)
				{
					sum_impar += (digito * 2) - 9;
				}
				else
				{
					sum_impar += (digito * 2);
				}
			}
			i++;
		}

		sum = sum_par + sum_impar;

		int verificar = cedula.at(cedula.size() - 1) - '0';
		int bandera = (10 - (sum % 10)) + sum;

		if (sum % 10 == 0)
		{
			return verificar == 0;
		}

		return (bandera - sum) == verificar;
	}
};