#include <stdlib.h>
#include <pthread.h>
#include "wqueue.h"
#include "consumers.h"


struct Consumers
{
	pthread_t* m_thread_C2P;
	pthread_t* m_thread_P2C;
	size_t m_capacity;
	
};

status_Consumer createConsumer(Consumers** cPtr, size_t capacity)
{
	*cPtr=(Consumers*)malloc(capacity*sizeof(Consumers));
	if(!(*cPtr)) return allocationE_c;

	((*cPtr)->m_thread_C2P)=(pthread_t*)malloc(capacity*sizeof(pthread_t));
	if(!(*cPtr)->m_thread_C2P) return allocationE_c;

	((*cPtr)->m_thread_P2C)=(pthread_t*)malloc(capacity*sizeof(pthread_t));
	if(!(*cPtr)->m_thread_P2C) return allocationE_c;

	(*cPtr)->m_capacity=capacity;

	return OK_c;
}



status_Consumer startConsumers(Consumers* cPtr,Queue* QptrP2C,Queue* QptrC2P)
{
	int i=0,j=0,k=0;
	if(!cPtr) return nullE_c;

	
	while(i < (cPtr->m_capacity/5))
	{
		pthread_create(&cPtr->m_thread_P2C[i], NULL,threadConsumer,QptrC2P);
		i++;
	}

	while(j < (cPtr->m_capacity/5))
	{
		pthread_join(cPtr->m_thread_P2C[j], NULL);
		j++;
	}
	return OK_c;
}

void* threadConsumer(void* Qptr)
{
	Queue* tempQ;
	if(!Qptr) return NULL;
	tempQ=(Queue*)Qptr;
	/*write*/
	write2Queue(Qptr);
	/*read*/
	readFromQueue(Qptr);
}

status_Consumer consumersDestroy(Consumers* cPtr)
{
	int i=0,j=0;

	if(!cPtr) return nullE_c;
	if(!cPtr->m_thread_C2P) return nullE_c;
	if(!cPtr->m_thread_P2C) return nullE_c;



	free(cPtr->m_thread_C2P);	
	free(cPtr->m_thread_P2C);	
	free(cPtr);

	return OK_c;
}