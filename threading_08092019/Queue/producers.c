#include <stdlib.h>
#include <pthread.h>
#include "wqueue.h"
#include "producers.h"

struct Producers
{
	pthread_t* m_thread_C2P;
	pthread_t* m_thread_P2C;
	size_t m_capacity;
};

status_Producers createProducer(Producers** pPtr, size_t capacity)
{
	*pPtr=(Producers*)malloc(capacity*sizeof(Producers));
	if(!(*pPtr)) return allocationE;

	(*pPtr)->m_thread_C2P=(pthread_t*)malloc(capacity*sizeof(pthread_t));
	if(!(*pPtr)->m_thread_C2P) return allocationE;

	(*pPtr)->m_thread_P2C=(pthread_t*)malloc(capacity*sizeof(pthread_t));
	if(!(*pPtr)->m_thread_P2C) return allocationE;

	(*pPtr)->m_capacity=capacity;

	return OK;

}

status_Producers startProducers(Producers* pPtr,Queue* QptrC2P,Queue* QptrP2C)
{
	int i=0,j=0,k=0;
	if(!pPtr) return nullE;

	/*P2C*/
	while(i < (pPtr->m_capacity/5))
	{
		pthread_create(&pPtr->m_thread_C2P[i], NULL,threadProducer,QptrP2C);
		i++;
	}

	while(j < (pPtr->m_capacity/5))
	{
		pthread_join(pPtr->m_thread_C2P[j], NULL);
		j++;
	}
	return OK;
}

void* threadProducer(void* Qptr)
{
	Queue* tempQ;

	if(!Qptr) return NULL;

	tempQ=(Queue*)Qptr;
	/*write*/
	write2Queue(Qptr);
	/*read*/
	readFromQueue(Qptr);
	return;
}

status_Producers producersDestroy(Producers* pPtr)
{
	int i=0,j=0;

	if(!pPtr) return nullE;
	if(!pPtr->m_thread_C2P) return nullE;
	if(!pPtr->m_thread_P2C) return nullE;



	free(pPtr->m_thread_C2P);	
	free(pPtr->m_thread_P2C);	
	free(pPtr);

	return OK;
}