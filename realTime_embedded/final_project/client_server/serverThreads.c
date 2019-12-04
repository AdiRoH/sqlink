#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

const int portNum = 8080;
const int responseSize = 4096;

void err(int val);
void errPtr(void* ptr);
void errP_thread(int val);
void* threadFunc(void* arg);

int main(int argc,char** argv,char** argp)
{
	int server_socket,serverFd,ret;
	struct sockaddr_in server_address,client_address;
	pthread_t thread;
	socklen_t clientSize;
	/*create a socket*/
	server_socket = socket(AF_INET,SOCK_STREAM,0);
	err(server_socket);
	/*define the server addrress-define the socket that listens to response)*/
	/*zeroing the struct of address*/
	bzero((char*)&server_address,sizeof(server_address));
	/*specify type of adress for the socket*/
	server_address.sin_family = AF_INET;

	/*specify port for the socket*/
	server_address.sin_port = htons(portNum);/*htons converts real port number*/

	server_address.sin_addr.s_addr = INADDR_ANY;
	/*bind the socket to my specified ip and port(the struct)*/
	ret = bind(server_socket,(struct sockaddr*)&server_address,sizeof(server_address));
	err(ret);
	clientSize = sizeof(client_address);

	/*port where the socket can listen for connections*/
	ret = listen(server_socket,5);
	err(ret);

	while(1)
	{
		/*make you sleep until a servert connects you-then you get a file descriptor*/
		serverFd = accept(server_socket,(struct sockaddr*)&client_address,&clientSize);
		ret = pthread_create(&thread,NULL,threadFunc,(void*)&serverFd);/*check wether is fail*/	
		errP_thread(ret);
		/*no need in join?*/

	}

	return 0;
	/*free(response), close(serverfd) will never happens because of the infinite loop*/
}

void* threadFunc(void* serverfd)
{
	int ret,i=0,fdGET,bytesRead;
	int serverFd = *(int*)serverfd;
	char *fileName_html,*tempBuff,*response;
	char* response_server=\
	"HTTP/1.1 200 OK\n" \
	"Date: Mon, 27 Jul 2009 12:28:53 GMT\n" \
	"Server: Apache/2.2.14 (Win32)\n" \
	"Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT\n" \
	"Content-Type: text/html\n" \
	"Connection: Closed\n" \
	"\n";
	
	tempBuff = malloc(sizeof(char)*responseSize);
	errPtr(tempBuff);

	bytesRead = read(serverFd,tempBuff,responseSize);
	err(bytesRead);
	fileName_html = malloc(responseSize);
	
	while(tempBuff[i + 5]!=' ')
	{
		fileName_html[i]=tempBuff[i + 5];
		i++;
	}
	fileName_html[i++] = '\0';
	fdGET = open(fileName_html, O_RDONLY);
	err(fdGET);
	response = malloc(bytesRead);
	errPtr(response);
	ret = read(fdGET, response, bytesRead);
	err(ret);
	free(fileName_html);
	free(tempBuff);


	ret = write(serverFd,response_server,responseSize);
	err(ret);
	ret = write(serverFd,response,responseSize);
	err(ret);

	printf("%s\n",response);


	return NULL;
}

void err(int val)
{
	if(val==-1)
	{
		perror("ERROR:");
		exit(1);
	}
}

void errPtr(void* ptr)
{
	if(ptr==NULL)
	{
		perror("ERROR:");
		exit(1);
	}
}

void errP_thread(int val)
{
	if(val!=0)
	{
		fprintf(stderr,"ERROR in creating a thread\n");
		exit(1);
	}
}