#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include "wqueue.h"
#include "producers.h"
#include "consumers.h"

int main()
{
	Queue *QptrP2C,*QptrC2P;
	status_Producers res;
	status_Consumer resC;
	size_t capacity=15;
	Producers* pPtr;
	Consumers* cPtr;
	sem_t semReadP2C,semReadC2P,semWriteP2C,semWriteC2P;
	createQueue(&QptrP2C,capacity,&semReadP2C,&semWriteP2C);
	createQueue(&QptrC2P,capacity,&semReadC2P,&semWriteC2P);

	createProducer(&pPtr,capacity);
	res = startProducers(pPtr,QptrC2P,QptrP2C);
	
	createConsumer(&cPtr,capacity);
	resC = startConsumers(cPtr,QptrP2C,QptrC2P);
	/*
	create consumers;
	joinProducers;
	kill consumer;
	join consumer;
	destroy consumers;
	destroy producers;
	destroy Queues;
*/
}


