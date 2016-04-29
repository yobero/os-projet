#include "constante.h"




int modulof(float nombre)
{
	if(nombre >= 2)
	{
		while(nombre >= 2)
		{
			nombre = nombre - 2;
		}
	}
	
	if(nombre <= -2)
	{
		while(nombre <= 0)
		{
			nombre = nombre + 2;
		}
	}
	
	if(nombre >= 0.5 && nombre < 1.5)
		return 1;
	else
		return 0;
}

float minimal(float a,float b){
	if(a>b)
		return b;
	else
		return a;
}

float maximal(float a,float b){
	if(a>b)
		return a;
		else return b;
}

float moyenne(float a,float b){
	return (a+b)/2;
}

float somme(float a,float b){
	return a+b;
}
