#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include <pthread.h>
#include <semaphore.h>

#include <time.h>

/** n processus  ==> n fichier en entrée
 *  m threads
 * */
 
 //Création de plusieurs processus fils ayant comme père Directeur
 void creationChefEquipe(int n,pid_t pid[n])
 {
	 int i=0;
	 do
	 {
		 pid[i] = fork();
		 i++;
	 }
	 while(i<n && pid[i-1] > 0);
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
	
	//création de processus chefEquipe (1 processus <==> 1 fichier)
	pid_t pid[argv -2];
	creationChefEquipe(argv-2,pid);
	
	//Attribution des fichiers pour les processus
	
	//Attente des resultats des processus fils
	int max[argv-2]; //variable pour stocker les max de chaque fichier
	
	
	return 1;
}
