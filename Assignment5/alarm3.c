#include <signal.h>

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sys/wait.h>

// this is signal handler for

void signalHandler(int signal)

{

if (signal == SIGALRM)

{

printf("Ding!\n");

wait(NULL);

}

}

int main(int argc, char *argv[])

{

signal(SIGALRM, signalHandler);

if (argc != 2)

{

printf("Invalid arguments\n");

return 0;

}

printf("Alarm application starting\n");

int delay;

// compute delay

sscanf(argv[1], "%d", &delay);

// start child process

if (fork() == 0)

{

printf("Waiting for alarm to go off\n");

sleep(delay);

kill(getppid(), SIGALRM);

exit(0);

}

wait(NULL);

printf("done\n");

}