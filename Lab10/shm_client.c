/* Source code shm_client.c */
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char* argv){
    int shmid;
    char c;
    char *shm, *s;

    /* Use ftok to generate a key associated with a file*/
    key_t key = ftok("/tmp/shm", 'a');

    /* Create/Locate the memory segment */
    shmid = shmget(key, 128, IPC_CREAT|0666);

    /* Attach the memory segment to our address space */
    shm = (int*)shmat(shmid, NULL, 0);

    /* Read whatever data put in the memory */
    for (s = shm; *s != NULL; s++)
        printf("%c\n", *s);
    /* Acknowledge the read is completed */
    *shm = '*';
    return 0;
}
