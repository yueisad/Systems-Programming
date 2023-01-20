#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// This is a signal handler called when parent process receives a SIGALRM signal
// It will print the messages as requested and exit the program
void sigalrm()
{
printf("Ding!\n");
printf("done\n");
exit(0);
}

int main( int argc, char *argv[])
{
// Check if sleep time is passed as argument or not. First argument is always
// the program name. Second argument will be the sleep time. So checking for
// two arguments
if (argc != 2) {
printf("please pass me argument in seconds for sleep\n");
exit(1);
}

// Argument is stored is argv[1].argv[0] contains program name. It is a
// character string format so converting it into integer using atoi method
int sleeptime = atoi(argv[1]);

printf("alarm application starting\n");

// Forking a new process. For returns 0 when it is a child process and it
// return child process id incase of parent.
if (fork() == 0) {
printf("waiting for alarm to go off\n");
printf("<%d second pause>\n", sleeptime);
// Sleeping for requested time
sleep(sleeptime);
// getppid() method will get the parent process id. kill is used to send
// a signal to the parent process in this case. The signal here is SIGALRM
kill(getppid(), SIGALRM);
} else {
// This is parent process.
// Register the signal SIGALRM with the handler function(sigalrm) defined above. So
// whenever the signal comes, the above function is called.
signal(SIGALRM, sigalrm);
// Do an infinite wait here to wait for the signal
while (1) {}
}
}