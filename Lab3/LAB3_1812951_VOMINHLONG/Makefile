all: ex1 ex2

DEFS = -DUS_SOME_DEF

ex1:	ex1.o
	gcc ex1.o -o ex1 $(DEFS)
ex1.o: ex1.c
	gcc -c ex1.c $(DEFS)

ex2:	ex2.o
	gcc ex2.o -o ex2 $(DEFS)
ex2.o:
	gcc -c ex2.c $(DEFS)

clean:
	rm *.o ex1 ex2
