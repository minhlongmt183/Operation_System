all:	pi_multi-thread_mutex_lock

pi_multi-thread_mutex_lock:		pi_multi-thread_mutex_lock.o
	gcc pi_multi-thread_mutex_lock.o -pthread -o pi_multi-thread_mutex_lock
pi_multi-thread_mutex_lock.o:	pi_multi-thread_mutex_lock.c
	gcc -c pi_multi-thread_mutex_lock.c -w

clean:
	rm *.o pi_multi-thread_mutex_lock
