/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
		INGENIERA DE SOFTWARE
                
	AUTORES:
		-Luis Burbano
        -Mateo Condor
        -Camila Morales
        -Ricardo Rivadeneira
        -Steven Pozo
        -Jairo Quilumbaquin
        -Edwin Cantuña

	FECHA DE CREACION:
		19/12/2022         	
	FECHA DE MODIFICACION:
		20/11/2022   
*/

#if !defined(__ObjectOrientedModel_1_Utils_h)
#define __ObjectOrientedModel_1_Utils_h

#include <stdlib.h>
#include <time.h>
#include<iostream>

class Utils
{
public:
   

   Utils(){

   };
   ~Utils(){

   };

   int numeroRandom(int min, int max){
       return rand() % (max - min + 1) + min;
   }

    int maximo(int a, int b){
        if(a>b){
            return a;
        }else{
            return b;
        }
    }


protected:
private:
   
};

#endif