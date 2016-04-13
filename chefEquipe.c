#include "Employe.h"

//Constante
#define LECTURE O_RDONLY

//Fonction "main" pour les processus chefEquipe
void aFaire(char* argc)
{
	int fichier = open(argc,LECTURE);
	char* buf;
	char* tbuf;
	do{
		read(fichier,tbuf,1);
		buf = buf + *tbuf;
	}
	while(*tbuf != '\n' || *tbuf != ' ');
	int* nombre = (int*) buf;
	//pour tester
		printf("le nombre est %d\n",*nombre);
	//Validation du nombre
	if(*nombre<=0) {
		perror("L'indicateur de nombre est négatif\n");
		exit(0);
	}
	
	
	
	
}
