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

int main(int argv, char** argc)
{
	if(argv<=1)
	{
		perror("ERREUR : Il faut au minimum un argument dans la fonction\n");
		exit(EXIT_FAILURE);
	}
	
	//Création de processus (1 pour chaque fichier)
	pid_t pid[argv];
	pid[0]=1;
	
	int i=1;
	
	while(i<argv)
	{
		if(pid[i-1]>0)
		{
			pid[i]=fork();
		}
		else
		{
			///Voir pour une utilisation d'un tube et d'une section critique
		}
		i++;
	}
	
	
	for(i=1 ; i<argv ; i++)
	{
		if(pid[i]>0)
			wait(&pid[i]);
		else exit(0); //valeur temporaire
	}
	
	
	return 1;
}
