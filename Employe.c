#include "constante.h"

//Utiliser atof(chaine) pour convertir une chaine de caractère (char* chaine) en flottant

typedef struct donnee{
	int fichier;
	int nombre;
}DONNEE;

void* min(void* arg){
	DONNEE* f = (DONNEE*)arg;
	char* tbuf = malloc(sizeof(char));
	char* buf = (char*)malloc(sizeof(char));
	read(f->fichier,tbuf,1);
	
}
