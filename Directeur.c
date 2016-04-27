#include "chefEquipe.h"

/** n processus  ==> n fichier en entrée
 *  m threads
 * */
 
 int comparaison(char*operateur){
	 if(strlen(operateur)!=3)
		return 0;
		
	char* min="min";
	char* max="max";
	char* avg="avg";
	char* sum="sum";
	char* odd="odd";
	
	int i=0;
	while(i<3){//comparaison pour min
		if(operateur[i] != min[i])
			break;
		i++;
	}
	if(i==3)
		return MIN;
		
	i=0;
	while(i<3){//max
		if(operateur[i]!=max[i])
			break;
		i++;
	}
	if(i==3)
		return MAX;
		
	 i=0;
	 while(i<3){//avg
		 if(operateur[i]!=avg[i])
			break;
		 i++;
	 }
	 if(i==3)
		return AVG;
		
	while(i<3){//sum
		if(operateur[i]!=sum[i])
			break;
		i++;
	}
	if(i==3)
		return SUM;
		
	while(i<3){//sum
		if(operateur[i]!=odd[i])
			break;
		i++;
	}
	if(i==3)
		return ODD;
	
	return 0;
 }
 
 //Création de plusieurs processus fils ayant comme père Directeur
pid_t creationChefEquipe(int n,int* f)
{
	 int i=2;
	 pid_t pid=1;
	 while(i<n+2 && pid>0)
	 {
		 pid = fork();
		 i++;
	 }
	 *f=i-1;
	 return pid;
 }
 
 void test(int status)
 {
	 if(status==VIDE)
	 {
		 perror("un des fichier est vide\n");
		 exit(EXIT_FAILURE);
	 }
	 if(status==NEGATIF)
	 {
		 perror("L'indice d'un des fichier est négatif\n");
		 exit(EXIT_FAILURE);
	 }
	 if(status==NEUTRE)
	 {
		 perror("L'indice d'un des fichier est null\n");
		 exit(EXIT_FAILURE);
	 }
 }
 
void attendreChefEquipe(int n,float resultat[n]) ///Seul le père appel cette fonction
{
	int i=0;
	
	int status;
	
	while (i<n)
	{
		wait(&status);///Stocke le max de chaque fichier
		if(!WIFEXITED(status))
			printf("un processus ne s'est pas terminer correctement\n");
			else{
				test(WEXITSTATUS(status));
				/*int tube=open("tube",LECTURE);
				char* buf=(char*)malloc(sizeof(char));
				read(tube,buf,10);
				resultat[i]=atof(buf);
				close(tube);
				free(buf);*/
			}
		
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
	int code=comparaison(argc[1]);
	
	if(!code)
	{
		perror("ERREUR : le code opérateur n'est pas valide\n");
		exit(EXIT_FAILURE);
	}
	
	mkfifo("tube",0640);//communication entre processus
	
	int* f=malloc(sizeof(int)); //Permet l'attribution des fichiers
	
	//création de processus chefEquipe (1 processus <==> 1 fichier)
	pid_t pid;
	pid = creationChefEquipe(argv-2,f);
	
	//Attribution des fichiers pour les processus (seul les processus fils font cette étape)
	///Utilisation du exit pour arrêter les processus fils
	if(pid==0)///Si VRAI alors on est dans un processus fils
		aFaire(argc[*f],code);
	free(f);
	
	//Attente des resultats des processus fils
	if(pid) {
		float resultat[argv-2]; ///variable pour stocker les max de chaque fichier
		attendreChefEquipe(argv-2,resultat);
	}
	
	return EXIT_SUCCESS;
}
