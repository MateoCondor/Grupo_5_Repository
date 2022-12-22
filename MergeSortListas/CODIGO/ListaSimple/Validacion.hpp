/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
		INGENIERA DE SOFTWARE
                
	AUTORES:
		Mateo Javier Condor Sosa 	 
		Luis Ariel Burbano Pacheco       
	FECHA DE CREACION:
		21/11/2022         	
	FECHA DE MODIFICACION:
		22/11/2022   
*/
#pragma once
#include <iostream>
#include <conio.h>
#include <cstring>
#include <stdlib.h>
using namespace std;

class Validacion{
    public:
        char *integerImput(char const *msj){
            char *dato=new char[0];
            char c;
            int i = 0;
            cout<<msj;
            while((c = getch()) != 13){
                if(c >= '0' && c <= '9'){
                    cout<<c;
                    dato[i++] = c;
                }else if(c == '\b'){
                        i--;
                        cout<<"\b \b";				
                }
            }
            dato[i] = '\0';
            return dato;
        }

        int charToInt(){
            char dato[10];
            int valor = 0;
            strcpy(dato, integerImput("\n> "));
            valor=atoi(dato);
            return valor;
        }
};