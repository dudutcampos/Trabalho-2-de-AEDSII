# _*_ MakeFile_*_

main: main.o arvore_binaria_busca.o hash.o
	gcc main.o arvore_binaria_busca.o hash.o -o tp2

main.o: main.c hash.h
	gcc -g -c main.c

hash.o: hash.c hash.h arvore_binaria_busca.h
	gcc -g -c hash.c

arvore_binaria_busca.o: arvore_binaria_busca.c arvore_binaria_busca.h
	gcc -g -c arvore_binaria_busca.c

clean:
	rm -f *.o tp2