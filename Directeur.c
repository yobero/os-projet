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
	
	return 1;
}

