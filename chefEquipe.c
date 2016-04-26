#include "Employe.h"

//Constante
#define LECTURE O_RDONLY

//Fonction "main" pour les processus chefEquipe
///La variable mode n'est pas encore apliquer dans la fonction

float minimal(){
	
}

float maximal(){
	
}

float moyenne(){
	
}

float somme(){
	
}
float impair(){
	
}

float operation(float resultat[]){
	if(1) return minimal();
	if(1) return maximal();
	if(1) return moyenne();
	if(1) return somme();
	return impair();
}

void aFaire(char* argc,char* mode)
{
	int fichier = open(argc,LECTURE);
	char* tbuf=malloc(sizeof(char));
	
	int t=read(fichier,tbuf,1);
	if(t==0)
	{
		free(tbuf);
		close(fichier);
		exit(VIDE);
	}
	
	char* buf=(char*)malloc(sizeof(char));
	
	while(*tbuf != '\n')
	{
		buf=strcat(buf,tbuf);
		read(fichier,tbuf,1);
	}
	int nombre=atoi(buf);
	
	int nbthread=1;
	while(nombre/nbthread >100)
		nbthread++;
	
	//Création des threads
	
	int i=0;
	float resultat[nbthread];//stocker les resulstat pour chaques threads
	while(i<nbthread) {
		
		i++;
	}
	
	close(fichier);
	exit(EXIT_SUCCESS);
}
