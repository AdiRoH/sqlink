#include <pthread.h>
#include <stdio.h>

#define MAX 100




void *threadMoshe(void* arg)
{
	printf(">>>>>%d \n",*(int*)(arg));
	sleep(1);

}








int main()
{
	int statusCreate ,statusJoin,val[MAX],i=0,j=0;
	pthread_t pid[MAX];

	for(i=0;i<MAX;i++)
	{
		val[i]=i;
		statusCreate = pthread_create(&pid[i],NULL, threadMoshe,(void*)&val[i]);	
	}

	for(j=0;j<MAX;j++)
	{
		statusJoin = pthread_join(pid[j], NULL);
	}
	
}