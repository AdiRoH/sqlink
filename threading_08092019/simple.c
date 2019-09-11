#include <pthread.h>
#include <stdio.h>

#define MAX 100




void *threadA(void* arg)
{
	int i=0;
	for (i=0; i<5; i++)
	{
		printf("    ===> Thread A !!!\n");
		sleep(2);
	}

}
void *threadB(void* arg)
{
	int i=0;
	for (i=0; i<10; i++)
	{
		printf("Thread B !!!\n");
		sleep(1);
	}

}








int main()
{
	pthread_t tA, tB;
	int i;
	
	for(i=0; i<5; i++)
	{		
		pthread_create(&tA,NULL, threadA,NULL);	
	}

	pthread_create(&tB,NULL, threadB,NULL);	
	sleep(12)	;
}