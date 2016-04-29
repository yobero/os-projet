#include <stdlib.h>
#include <stdio.h>




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
