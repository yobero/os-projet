constante.o : constante.c
	gcc -c constante.c -o constante.o
	
Employe.o : Employe.c Employe.h constante.o
	gcc -c Employe.c -o Employe.o
	
chefEquipe.o : chefEquipe.c chefEquipe.h Employe.o
	gcc -c chefEquipe.c -o chefEquipe.o
	
Directeur.o : Directeur.c Directeur.h chefEquipe.o
	gcc -c Directeur.c -o Directeur.o
	
compile : Directeur.o
	gcc -o reduction constante.o Employe.o chefEquipe.o Directeur.o
	
run : compile
	./reduction
