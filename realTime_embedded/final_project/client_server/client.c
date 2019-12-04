#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void err(int val);

int portNum = 8080;
int main(int argc,char** argv,char** argp)
{
	
	int network_socket,ret;
	struct sockaddr_in server_address;
	char server_response[256];
	
	/*create a socket*/
	network_socket = socket(AF_INET,SOCK_STREAM,0);
	
	/*specify type of adress for the socket*/
	server_address.sin_family = AF_INET;

	/*specify port for the socket*/
	server_address.sin_port = htons(portNum);/*htons convert real port number*/

	server_address.sin_addr.s_addr = INADDR_ANY;

	ret = connect(network_socket,(struct sockaddr*)&server_address,sizeof(server_address));/*connected to remote function*/
	err(ret);

	recv(network_socket,&server_response,sizeof(server_response),0);/*retrieve data*/

	/*print out the server's response*/
	printf("The server sent the data %s\n",server_response);

	/*close the socket*/
	close(network_socket); 

	return 0;
}

void err(int val)
{
	if(val==-1)
	{
		fprintf(stderr,"can't connect\n");
		exit(1);
	}
}
