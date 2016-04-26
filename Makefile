Employe.o : Employe.c Employe.h
	gcc -c Employe.c -o Employe.o
	
chefEquipe.o : chefEquipe.c chefEquipe.h Employe.o
	gcc -c chefEquipe.c -o chefEquipe.o
	
Directeur.o : Directeur.c Directeur.h chefEquipe.o
	gcc -c Directeur.c -o Directeur.o
	
compile : Directeur.o
	gcc -o reduction constante.h Employe.o chefEquipe.o Directeur.o -lpthread
	
run : compile
	./reduction

clear :
	rm -f *.o
	rm -f ./reduction
