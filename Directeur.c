#include "chefEquipe.h"

/** n processus  ==> n fichier en entrée
 *  m threads
 * */
 
 //Création de plusieurs processus fils ayant comme père Directeur
pid_t creationChefEquipe(int n,int* f)
{
	 int i=0;
	 pid_t pid=1;
	 *f=2;
	 while(i<n && pid>0)
	 {
		 pid = fork();
		 i++;
	 }
	 *f=i-1;
	 return pid;
 }
 
 void affichageValeur(float max)
 {
	 printf("%f\n",max);
 }
 
void attendreChefEquipe(int n,float max[n]) ///Seul le père appel cette fonction
{
	int i=0;
	
	void* status;
	
	while (i<n)
	{
		wait(status);///Stocke le max de chaque fichier
		if(!WIFEXITED(status))
			printf("un processus ne s'est pas terminer correctement\n");
			else printf("%d\n",WEXITSTATUS(status) );
		
		i++;
	}
}

int main(int argv, char** argc)
{	
	//condition requis pour continuer
	if(argv<2)
	{
		perror("ERREUR : pas d'argument en entrée\n");
		exit(EXIT_FAILURE);
	}
	if(argv<3)
	{
		perror("ERREUR : pas de fichier en entrée\n");
		exit(EXIT_FAILURE);
	}
	///Rentre même avec argc[1] == "min";
	///Faire une fonction de comparaison de deux caractères.
	/*if(!strcmp(argc[1],"min") && !strcmp(argc[1],"max") && !strcmp(argc[1],"avg") && !strcmp(argc[1],"sum") && !strcmp(argc[1],"odd"))
	{
		perror("ERREUR : le code opération n'est pas valide\n");
		exit(EXIT_FAILURE);
	}*/
	int c=2;
	int* f=malloc(sizeof(int));
	
	//création de processus chefEquipe (1 processus <==> 1 fichier)
	pid_t pid;
	pid = creationChefEquipe(argv-2,f);
	
	//Attribution des fichiers pour les processus (seul les processus fils font cette étape)
	///Utilisation du exit pour arrêter les processus fils
	if(pid==0)///Si VRAI alors on est dans un processus fils
		aFaire(argc[*f],argc[1]);
	free(f);
	
	//Attente des resultats des processus fils
	if(pid) {
		float max[argv-2]; ///variable pour stocker les max de chaque fichier
		attendreChefEquipe(argv-2,max);
	}
	
	return EXIT_SUCCESS;
}
