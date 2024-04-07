all:meuPrograma

meuPrograma: meuPrograma.o minhaLista.o
	gcc meuPrograma.o minhaLista.o -lm -o meuPrograma

meuPrograma.o: meuPrograma.c minhaLista.h
	gcc -Wall -Werror -c meuPrograma.c

minhaLista.o: minhaLista.c minhaLista.h
	gcc -Wall -Werror -c minhaLista.c

clean:
	rm -f *.o meuPrograma
