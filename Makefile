fonction.o : fonction.c
	gcc -c fonction.c -o fonction.o

Employe.o : Employe.c Employe.h fonction.o
	gcc -c Employe.c -o Employe.o
	
chefEquipe.o : chefEquipe.c chefEquipe.h Employe.o
	gcc -c chefEquipe.c -o chefEquipe.o
	
Directeur.o : Directeur.c chefEquipe.o
	gcc -c Directeur.c -o Directeur.o
	
compile : Directeur.o
	gcc -o reduction constante.h fonction.o Employe.o chefEquipe.o Directeur.o -lpthread
	
run : compile
	./reduction

clear :
	rm -f *.o
	rm -f ./reduction
