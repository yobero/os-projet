#include "constante.h"

typedef struct donnee{
	int fichier;
	int nombre;
	int first;
	float valeur;
	pthread_mutex_t mutex;
}DONNEE;

void* Min(void* arg);
