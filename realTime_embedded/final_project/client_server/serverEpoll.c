#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/epoll.h>

const int portNum = 8080;
const int responseSize = 4096;
const int maxEvent = 3000;

int writeRespone(int serverFd,char* response,int* bytesRead);
char* readResponse(int serverFd,int* bytesRead);
void err(int val);
void errPtr(void* ptr);

int main(int argc,char** argv,char** argp)
{
	int server_socket,serverFd,ret,epoll_fd,i,event_count;
	char* response;
	struct sockaddr_in server_address,client_address;
	struct epoll_event event,events[maxEvent];
	socklen_t clientSize;
	int bytesRead = -1;

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

	epoll_fd = epoll_create(1);
	err(epoll_fd);

	event.events = EPOLLIN | EPOLLOUT;/*writing+reading*/
  	event.data.fd = server_socket;

	while(1)
	{
		/*accept a connection*/
		serverFd = accept(server_socket,(struct sockaddr*)&client_address,&clientSize);
		err(serverFd);
		ret = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, serverFd, &event);
  		err(-1);
		event_count = epoll_wait(epoll_fd, events, maxEvent, -1);/*Specifying a timeout of -1 causes epoll_wait() to block indefinitely,*/
		err(event_count);
		for(i = 0;i<event_count;i++)
		{
			response = readResponse(events[i].data.fd,&bytesRead);
			errPtr(response);
			printf("%s\n",response);
			ret = writeRespone(events[i].data.fd,response,&bytesRead);
			err(ret);
		}
	}

	/*free(response), close(serverfd) will never happens because of the infinite loop*/

	return 0;
}

int writeRespone(int serverFd,char* response,int* bytesRead)
{
	int ret;
	char* response_server=\
	"HTTP/1.1 200 OK\n" \
	"Date: Mon, 27 Jul 2009 12:28:53 GMT\n" \
	"Server: Apache/2.2.14 (Win32)\n" \
	"Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT\n" \
	"Content-Type: text/html\n" \
	"Connection: Closed\n" \
	"\n";
	errPtr(response);
	errPtr(bytesRead);
	ret = write(serverFd,response_server,strlen(response_server));
	ret = write(serverFd,response,*bytesRead);
	printf("%s\n",response);
	return ret;
}

char* readResponse(int serverFd,int* bytesRead)
{
	int ret,i=0,fdGET; 
	struct stat buffer;/*for detecting if the file is open or no*/ 
	char *fileName_html,*tempBuff,*response;
	errPtr(bytesRead);
	tempBuff = malloc(sizeof(char)*responseSize);
	errPtr(tempBuff);
	*bytesRead = read(serverFd,tempBuff,responseSize);
	ret = *bytesRead;
	err(ret);
	fileName_html = malloc(responseSize);
	errPtr(fileName_html);
	while(tempBuff[i + 5]!=' ')/*becuse of GET in the response*/
	{
		fileName_html[i]=tempBuff[i + 5];
		i++;
	}
	fileName_html[i++] = '\0';

	err(stat (fileName_html, &buffer) != 0);/*if file doesn't exist*/
	fdGET = open(fileName_html, O_RDONLY);
	err(fdGET);
	response = malloc(*bytesRead);
	ret = read(fdGET, response, *bytesRead);
	err(ret);
	free(fileName_html);
	free(tempBuff);
	return response;
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