//Alden Park 
/*The purpose of this program is to provide create a multi-client server. 
In this program, I have used a fork to create child process on the server so that multiple clients can communicate
with the server. 
*/
//Reference https://www.geeksforgeeks.org/design-a-concurrent-server-for-handling-multiple-clients-using-fork/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//Port number
#define PORT 8080

int main(){

	//server socket id
	int sockfd, ret;
	//server socket address structure
	struct sockaddr_in serverAddr;

	//client socket id
	int newSocket;

	//client socket address structure
	struct sockaddr_in newAddr;

	//store server socket address
	socklen_t addr_size;

	//character array
	char buffer[1024];

	//child process id
	pid_t childpid;


	//create TCP socket 
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		printf("Error in connection.\n");
		exit(1);
	}
	printf("Server Socket is created.\n");

	//initialize address structure
	memset(&serverAddr, '\0', sizeof(serverAddr));
	//assign port number and ip address
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	//loopback address
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	//binding socket id
	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("Error in binding.\n");
		exit(1);
	}
	printf("Bind to port %d\n", 8080);

	//listen for connection
	if(listen(sockfd, 10) == 0){
		printf("Waiting for connections...\n");
	}else{
		printf("Error in binding.\n");
	}


	while(1){
		//accept clients
		newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
		if(newSocket < 0){
			exit(1);
		}
		printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));

		//fork() child process
		if((childpid = fork()) == 0){
			//close server socket id
			close(sockfd);

			while(1){
				recv(newSocket, buffer, 1024, 0);
				if(strcmp(buffer, "shutdown") == 0){
					printf("Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
					break;
				}else{
					printf("Client: %s\n", buffer);
					send(newSocket, buffer, strlen(buffer), 0);
					bzero(buffer, sizeof(buffer));
				}
			}
		}

	}

	close(newSocket);


	return 0;
}