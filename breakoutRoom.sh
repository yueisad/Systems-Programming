#include "apue.h"
#include <sys/msg.h>

struct mymesg{
    long mtype;
    char mtext[4];
};

int main(){
    int i, msgqid;
    key_t key = 1;
    struct mymesg m;

    for(i=0;i<5;i++){
        if((msgqid = msgget(key, IPC_CREAT|IPC_EXCL|0600)<0)
        err_sys("error");
        printf("queue ID is %d\n", msgqid);

        if(msgctl(msgqid, IPC_RMID, NULL)<0)
        err_sys("error");
    }

    for (i=0; i<5; i++){
        if((msgqid = msgget(IPC_PRIVATE, 0600) <0)
        err_sys("error");
        m.mtype = 1;
        if(msgsnd(msgqid, &m, sizeof(m.mtext),0)<0)
        err_sys("error");
    }
    exit(0);
}