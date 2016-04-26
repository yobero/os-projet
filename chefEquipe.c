#include "Employe.h"

//Constante
#define LECTURE O_RDONLY

//Fonction "main" pour les processus chefEquipe
///La variable mode n'est pas encore apliquer dans la fonction
void aFaire(char* argc,int code)
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
	if(nombre<0)
		exit(NEGATIF);
	if(nombre==0)
		exit(NEUTRE);
	
	int nbthread=1;
	while(nombre/nbthread >100)
		nbthread++;
	
	//Création des threads
	
	int i=0;
	DONNEE* f;
	f->fichier = fichier;
	f->nombre = nombre/nbthread; // nombre de nombre à lire
	pthread_t thread[nbthread];
	
	///création des threads
	while(i<nbthread) {
		if(code==1)
			pthread_create(&thread[i],NULL,Min,f);
			if(code==2);
		
		i++;
	}
	
	///recupération des valeurs
	i=0;
	while(i<nbthread)
	{
		pthread_join(thread[i],NULL);
		i++;
	}
	
	close(fichier);
	exit(EXIT_SUCCESS);
}
