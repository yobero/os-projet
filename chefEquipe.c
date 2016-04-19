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
	//A revoir
	do{
		read(fichier,tbuf,1);
		*buf = *buf + *tbuf;
	}
	while(*tbuf != '\n' || *tbuf != '\0');
	close(fichier);
	
	int* nombre = (int*) buf;
	//pour tester
	printf("le nombre est %d\n",*nombre);
	//Validation du nombre
	if(*nombre<=0) {
		perror("L'indicateur de nombre est négatif\n");
		exit(0);
	}
	
	int nbthread=2;
	
	while((*nombre/nbthread) >100)
		nbthread++; //voir pour mettre nbthread * 2 (pour aller plus)
		
	//creation de nbthread thread
	int i=0;
	pthread_t thread[nbthread];
	
	while(i<nbthread){
		//pthread_creat();
		i++;
	}
	
	exit(*nombre); //modifier cet valeur pour envoyer le max du fichier traite pour ce processus
}
