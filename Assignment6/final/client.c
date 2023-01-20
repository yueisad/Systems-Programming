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

// PORT number
#define PORT 8080

int main(){

	//Socket id
	int clientSocket, ret;
	//Client socket structure
	struct sockaddr_in serverAddr;
	//Character array
	char buffer[1024];

	//Socket id
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket < 0) {
		printf("Connetion Error\n");
		exit(1);
	}
	printf("Client socket created\n");


	//Initialize socket structure 
	memset(&serverAddr, '\0', sizeof(serverAddr));
	//Assign port number and IP address
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	//IP address loopback
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	//Connect to server
	ret = connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
	if (ret < 0) {
		printf("Failed to connect\n");
		exit(1);
	} 
	printf("Connected to server\n");

	while(1) {
		//send message to server
		printf("Message to send: ");
		
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strcspn(buffer, "\n")] = '\0';

		send(clientSocket, buffer, strlen(buffer),0);

		if (strcmp(buffer, "shutdown") == 0) {
			 close(clientSocket);
			 printf("disconnected\n");
			 exit(1);
		}

		//server response
		if(recv(clientSocket, buffer, 1024, 0) < 0){
			printf("recv error\n");
		} else {
			printf("Server: \t%s\n", buffer);
		}
	}
	
	

	return 0;
}