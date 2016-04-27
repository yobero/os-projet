#include "Employe.h"

#define NB 10 //pour la convertion float en chaine de caractère

//Fonction "main" pour les processus chefEquipe
///La variable mode n'est pas encore apliquer dans la fonction
void aFaire(char* argc,int code)
{
	int fichier = open(argc,LECTURE);
	char* tbuf=malloc(sizeof(char));
	
	int t=read(fichier,tbuf,1);
	if(t==0)//le fichier est vide
	{
		free(tbuf);
		close(fichier);
		exit(VIDE);
	}
	
	char* buf=(char*)malloc(sizeof(char));
	
	///Recupération du premier nombre du fichier
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
	f->first=1;
	pthread_mutex_init(&f->mutex,NULL);
	
	
	pthread_t thread[nbthread];
	
	///création des threads
	while(i<nbthread) {
		if(code==1)
			pthread_create(&thread[i],NULL,Min,f);
		
		i++;
	}
	
	///recupération des valeurs
	i=0;
	while(i<nbthread)
	{
		pthread_join(thread[i],NULL);
		i++;
	}
	
	/*int tube = open("tube",ECRITURE);
	char* s = (char*)malloc(sizeof(char));
	write(tube,gcvt(f->valeur,'F',s),NB);
	free(s);
	close(tube);*/
	
	close(fichier);
	exit(EXIT_SUCCESS);
}
