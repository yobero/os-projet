#include "chefEquipe.h"

/** n processus  ==> n fichier en entrée
 *  m threads
 * */
 
 //Création de plusieurs processus fils ayant comme père Directeur
pid_t creationChefEquipe(int n)
{
	 int i=0;
	 pid_t pid=1;
	 while(i<n && pid>0)
	 {
		 pid = fork();
		 i++;
	 }
	 return pid;
 }
 
void attributionFichier() ///Revoir la fonction
{
	//Voir pour faire des tubes pour chaque processus fils pour assigner un fichier
	aFaire();
}
 
void attendreChefEquipe(int n,int max[n]) ///Seul le père appel cette fonction
{
	int i=0;
	
	void* status;
	
	while (i<n)
	{
		wait(status);///Stocke le max de chaque fichier
		if(WIFEXITED(status))
			max[i]=WEXITSTATUS(status);
		else print("un processus ne s'est pas terminer correctement\n");
		
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
	
	//création de processus chefEquipe (1 processus <==> 1 fichier)
	pid_t pid;
	pid = creationChefEquipe(argv-2);
	
	//Attribution des fichiers pour les processus (seul les processus fils font cette étape)
	///Utilisation du exit pour arrêter les processus fils
	if(pid==0)///Si VRAI alors on est dans un processus fils
	{
		attributionFichier();
	}
	
	
	//Attente des resultats des processus fils
	int max[argv-2]; ///variable pour stocker les max de chaque fichier
	attendreChefEquipe(argv-2,max);
	
	return 1;
}
