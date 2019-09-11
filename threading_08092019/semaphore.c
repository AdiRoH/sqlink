#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>


#define MAX 100


sem_t sem;

void *thread(void* arg)
{
	sem_wait(&sem);
	printf(">>>>>%d \n",*(int*)(arg));
	sem_post(&sem);

}








int main()
{
	int statusCreate ,statusJoin,val[MAX],i=0,j=0;
	pthread_t pid[MAX];
	

	sem_init(&sem, 0, 1);

	for(i=0;i<MAX;i++)
	{
		val[i]=i;
		statusCreate = pthread_create(&pid[i],NULL, thread,(void*)&val[i]);	
	}

	for(j=0;j<MAX;j++)
	{
		statusJoin = pthread_join(pid[j], NULL);
	}
	
}







	