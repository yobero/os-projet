#include "Employe.h"

//Constante
#define LECTURE O_RDONLY

//Fonction "main" pour les processus chefEquipe
///La variable mode n'est pas encore apliquer dans la fonction
void aFaire(char* argc,char* mode)
{
	int fichier = open(argc,LECTURE);
	char* buf;
	char* tbuf;
	
	do{
		read(fichier,tbuf,1);
		*buf=*buf+tbuf[0];
	}
	while(*tbuf!='\0' || *tbuf!='\n');	
	
	int* nombre=malloc(sizeof(int));
	nombre=(int*)buf;
	
	///
	
	int nbthread=1;
	while(*nombre/nbthread >100)
		thread++;
		
	int i=0;
	
	//Création des threads
	while(i<nbthread) {
		
		i++;
	}
	
	close(fichier);
	exit(1);
}
