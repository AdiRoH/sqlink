#include "wqueue.h"
#include "DirWalk.h"
#include <dirent.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>

#define FILE 8
#define DIRECTORY 4

typedef struct dirent dirent;

/*
DirWalkStatus getFiles(char* dirPath, onFileFoundedAction userFunc)
{
	DIR *d;
	dirent *dir;
	char nextPath[512];
	unsigned char* MD5;

	if(!dirPath)return Dir_ParamE;
	d = opendir(dirPath);

	if(!d) return dirE;

	while((dir = readdir(d)))
	{
		if(dir->d_name[0] != '.' && dir->d_type == FILE)
		{
			strcpy(nextPath, dirPath);
			strcat(nextPath, "/");
			strcat(nextPath, dir->d_name);
			userFunc(nextPath);
			printf();
		}

		else if(dir->d_name[0] != '.' && dir->d_type == DIRECTORY)
		{
			strcpy(nextPath, dirPath);
			strcat(nextPath, "/");
			strcat(nextPath, dir->d_name);
			getFiles(nextPath, userFunc);
		}
	}

	closedir(d);
	return Dir_OK;
}
*/

void* getFilesThread(void* Qptr)
{
	DIR *d;
	dirent *dir;
	Queue* tempQ;
	char nextPath[512];
	char *dirPathTemp;
	
	if(!Qptr) return NULL;

	tempQ=(Queue*)Qptr;
	dirPathTemp=(((Queue*)Qptr)->m_dirPath);


	d = opendir(dirPathTemp);

	if(!d) return NULL;

	while((dir = readdir(d)))
	{
		if(dir->d_name[0] != '.' && dir->d_type == FILE)
		{
			strcpy(nextPath, dirPathTemp);
			strcat(nextPath, "/");
			strcat(nextPath, dir->d_name);
			/*userFunc(nextPath);*/
			printf("%s\n",dir->d_name);
			write2Queue(tempQ);
		}

		else if(dir->d_name[0] != '.' && dir->d_type == DIRECTORY)
		{
			strcpy(nextPath, dirPathTemp);
			strcat(nextPath, "/");
			strcat(nextPath, dir->d_name);
			getFiles(tempQ);
		}
	}

	closedir(d);
}

void* getFiles(Queue* Qptr)
{
	pthread_t ptrThread;

	if(!Qptr) return NULL;
	
	pthread_create(&ptrThread,NULL,getFilesThread,(void*)Qptr);
	pthread_join(ptrThread,NULL);
}