all: 				pi_multi-thread pi_serial code

DEFS = -DUS_SOME_DEF

pi_multi-thread:	pi_multi-thread.o
		gcc pi_multi-thread.o -pthread -o pi_multi-thread $(DEFS)
pi_serial:			pi_serial.o
		gcc pi_serial.o -pthread -o pi_serial $(DEFS)
code:				code.o
		gcc code.o -pthread	-o code $(DEFS)

pi_multi-thread.o:	pi_multi-thread.c
		gcc  -c pi_multi-thread.c -w $(DEFS)
pi_serial.o:		pi_serial.c
		gcc  -c pi_serial.c -w $(DEFS)
code.o:				code.c
		gcc  -c code.c -w $(DEFS)

clean:
		rm *.o pi_multi-thread pi_serial code
