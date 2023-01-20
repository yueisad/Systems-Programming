//This program will act like a server for a single client.
//It will receive messages from a client and respond with
//"Message received" every time a message is received.
//When the server or client exits, cleanup will execute.
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<errno.h>

#define MAXLEN 128      //maximum length of message

void cleanup(int);


const char sockname[] = "/tmp/socket1";
int connfd;
int datafd;

int main(void) {
   int ret;
   struct sockaddr_un addr;     //contains the socket type and file path
   char buffer[MAXLEN];
   struct sigaction action;
   pid_t childpid;
   int newSocket;

   //prepare for sigaction
   action.sa_handler = cleanup;
   sigfillset(&action.sa_mask);
   action.sa_flags = SA_RESTART;

   //register all signals to handle
   sigaction(SIGTERM, &action, NULL);
   sigaction(SIGINT, &action, NULL);
   sigaction(SIGQUIT, &action, NULL);
   sigaction(SIGABRT, &action, NULL);
   sigaction(SIGPIPE, &action, NULL);

   //create socket file descriptor
   connfd = socket(AF_UNIX, SOCK_SEQPACKET, 0);

   if(connfd == -1) {
      perror("Create socket failed");
      return 1;
   }

   //set address family and socket path
   addr.sun_family = AF_UNIX;
   strcpy(addr.sun_path, sockname);

   //bind the socket
   //cast sockaddr_un to sockaddr
   if((bind(connfd, (const struct sockaddr*) &addr,
      sizeof(struct sockaddr_un))) == -1) {
         perror("Binding socket failed");
         return 1;
   }

   //prepare for accepting connections
   //Arguments: 1) socket file descriptor
   //2) buffer size for backlog
   if((listen(connfd, 20)) == -1) {
      perror("Listen error");
      return 1;
   }

   //Print successful connection
   printf("Client connected\n");

   //main loop
   while (1) {          //for each message received
      
      datafd = accept(connfd, (struct sockaddr*)&addr, sizeof(addr));
      if (datafd == -1) {
         perror("Accept error");
      return 1;
      }

      //Print successful connection
      printf("Client connected\n");

      if((childpid = fork()) == 0) {
         close(connfd);
      }




      while (1) {       //read data from socket fd,
                        //save to buffer
                        //print on the terminal
         ret = read(datafd, buffer, MAXLEN);

         if (ret == -1) {  //bad read
            perror("Error reading line");
            cleanup(1);
         }
         else if (ret == 0) {
            printf("Client disconnected\n");
            cleanup(1);
         } 
         else {
            printf("Message: %s\n", buffer);
            break;
         }
      }//end inner while

      //write confirmation message
      write(datafd, "Message received\n", 18);
   } //end outer while
   return 0;
}

//cleanup function
void cleanup(int signum) {
   printf("Quitting and cleaning up\n");
   close(connfd);
   close(datafd);
   unlink(sockname);
   exit(0);
}

