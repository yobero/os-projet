#include "Employe.h"

//Fonction "main" pour les processus chefEquipe
///La variable mode n'est pas encore apliquer dans la fonction
void aFaire(char* argc,int code,int m,int tab[m][2],int position)
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
			pthread_create(&thread[i],NULL,min,f);
		if(code==2)
			pthread_create(&thread[i],NULL,max,f);
		if(code==3 || code==4)
			pthread_create(&thread[i],NULL,sum,f);
		if(code==5)
			pthread_create(&thread[i],NULL,odd,f);
		
		i++;
	}
	
	///recupération des valeurs
	i=0;
	while(i<nbthread)
	{
		pthread_join(thread[i],NULL);
		i++;
	}
	
	int valeur;
	
	if(position==0){//le premier processus créer
		char* buf = (char*)malloc(sizeof(char));
		if(code==3)
			f->valeur=f->valeur/nombre;
			
		gcvt(f->valeur,NB,buf);
		write(tab[position][1],buf,NB);
		close(tab[position][1]);
		free(buf);
	}
	else{
		char* buf = (char*)malloc(sizeof(char));
		read(tab[position-1][0],buf,NB);
		valeur=atof(buf);
		if(code==1)
			gcvt(minimal(f->valeur,valeur),NB,buf);
		if(code==2)
			gcvt(maximal(f->valeur,valeur),NB,buf);
		if(code==3)
			gcvt(moyenne((f->valeur/nombre),valeur),NB,buf);
		if(code==4 || code==5)
			gcvt(somme(f->valeur,valeur),NB,buf);
		
		write(tab[position][1],buf,NB);
		close(tab[position-1][0]);
		close(tab[position][1]);
		
		free(buf);
	}
	
	close(fichier);
	exit(EXIT_SUCCESS);
}
