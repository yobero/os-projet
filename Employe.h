#include "constante.h"

typedef struct donnee{
	int fichier;
	int nombre;
	int first;
	float valeur;
	pthread_mutex_t mutex;
}DONNEE;

void* min(void* arg);
void* max(void* arg);
void* sum(void* arg);
void* odd(void* arg);
