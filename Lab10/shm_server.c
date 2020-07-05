/* *Source code shm_server.c */
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char* argv){
    int shmid;
    char c;
    char *shm, *s;

    /*Use ftok to generate a key associated with a file*/
    key_t key = ftok("/tmp/shm", 'a');
    
    /* Create/Locate the memory segment
     * 0666: usual access permision in linux: rwx */
    shmid = shmget(key, 128, IPC_CREAT|0666);

    /*Attach the memory segment to our address space */
    shm = (int*)shmat(shmid, NULL, 0);

    /*Now we put some thing into the memory for the
     * other process to read */
    s = shm;
    for (c = 'a'; c <= 'z'; c++)
        *s++ = c;
    *s = NULL;

    /* We wait until the process acknowledge by 
     * changing the first character of the memory */
    while (*shm != '*')
        sleep(1);

    //TODO: Implement codeto remover memory segment using shmctl()
    shmctl(shmid, IPC_RMID, (struct shmid_ds*)0);
}
