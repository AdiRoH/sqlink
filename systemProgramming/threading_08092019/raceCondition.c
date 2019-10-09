#include <pthread.h>
#include <stdio.h>

#define MAX 100




void *threadA(void* arg)
{
	for (i=0; i<10; i++)
	{
		printf("Thread A !!!\n");
		sleep(1);
	}

}
void *threadB(void* arg)
{
	for (i=0; i<10; i++)
	{
		printf("Thread B !!!\n");
		sleep(1);
	}

}








int main()
{
	statusCreate = pthread_create(&pid[i],NULL, threadA,NULL);	
	statusCreate = pthread_create(&pid[i],NULL, threadB,NULL);	
	sleep(12)	;
}