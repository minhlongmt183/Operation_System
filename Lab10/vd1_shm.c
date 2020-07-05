#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char* argv[])
{
    int *shm, shmid;

    shmid = shmget(IPC_PRIVATE, 128, IPC_CREAT|0666);
    
    printf("shmid: %d\n, shmid");

    // trả về địa chỉ share memory
    shm = (int*)shmat(shmid, NULL, 0);

    if (fork() == 0){
        //thằng con 
       shm[0] = 111;
       shm[1] = 999;

       printf("sleep: begin\n");
       sleep(3);
       printf("sleep: end\n");

       printf("Process %d reads: Sum = %d\n", getpid(), shm[2]);

       shmdt((void*)shm);

       // tùy chỉnh vùng shared memmory: tùy chỉnh hoặc xóa bỏ.
       // Ở đây là xóa bỏ vùng shared memmory: IPC_RMID  
       shmctl(shmid, IPC_RMID, (struct shmid_ds *)0);

    }else{
        sleep(1);

        printf("Process %d writes to shared memory\n", getpid());

        shm[2] = shm[0] + shm[1];
        shmdt((void*)shm);
    }
    return 0;

}

