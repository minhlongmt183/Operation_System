all: main

DEFS = -DUS_SOME_DEF

main:	main.o ex1.o
		gcc main.o ex1.o -o main -lm  $(DEFS)

main.o: main.c ex1.h
		gcc -c main.c $(DEFS)

ex1.o: ex1.c ex1.h
		gcc -c ex1.c $(DEFS)

clean:
		rm *.o main
