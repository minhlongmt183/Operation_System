all: main

DEFS = -DUSE_SOME_DEF

main: readline.o main.o findsubstr.o
	gcc main.o readline.o findsubstr.o -o mygrep $(DEFS)

main.o: main.c  readline.h findsubstr.h
	gcc -c main.c $(DEFS)

readline.o: readline.c readline.h
	gcc -c readline.c $(DEFS)
findsubstr.o: findsubstr.c findsubstr.h 
	gcc -c findsubstr.c  $(DEFS)

clean:
	rm *.o mygrep
