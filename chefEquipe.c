#include "Employe.h"

float minimal(float a,float b){
	if(a>b)
		return b;
	else
		return a;
}

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
	
	/*if(position==m)
	{
		
		int a=0;
		float valeur=f->valeur; //initialisation de la valeur
		char* c=(char*)malloc(sizeof(char));
		
		close(tab[position][1]);//A SUPPRIMER
		close(tab[position][0]);
		
		while(a<m-1){
			char* z =(char*)malloc(sizeof(char));
			read(tab[a][0],z,NB);
			if(code==1)
				valeur=minimal(valeur,atof(z));
			//Mettre les autres fonction
			close(tab[a][0]);
			free(z);
			a++;
		}
		gcvt(valeur,'F',c);
		write(tab[0][1],c,NB);
		close(tab[0][1]);
		free(c);
	}
	else{
		char* s=(char*)malloc(sizeof(char));
		gcvt(f->valeur,'F',s);
		write(tab[position][1],s,NB);
		close(tab[position][1]);
		free(s);
	}
	*/
	close(fichier);
	exit(f->valeur);
}
