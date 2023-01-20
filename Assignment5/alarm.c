#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>


void signalAlarm(int signal) {
    if (signal == SIGALRM) {
        printf("Ding!\n"); 

        wait(NULL);
    }
}

int main(int argc, char*argv[]) {
    signal(SIGALRM, signalAlarm);

//check for correct arguements
    if (argc !=2) {
        printf("Please add seconds arguement");
        return 0;
    }

    int waitTime;

    sscanf(argv[1], "%d", &waitTime);

//forking process
    if (fork() == 0) {
        printf("Please wait for the alarm to finish counting down...\n");
        sleep(waitTime);
        kill(getppid(), SIGALRM);

        exit(0);
    }

    wait(NULL);
    printf("finished\n");

}