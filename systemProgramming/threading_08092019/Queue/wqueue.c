#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <string.h>
#include <stdio.h>

#include "wqueue.h"

struct Queue
{
	void** m_queueArr;
	size_t m_capacity;
	unsigned int m_index;
	sem_t m_semRead;
	sem_t m_semWrite;
	pthread_mutex_t m_mutex; 
};

status_Queue createQueue(Queue** Qptr,size_t capacity,sem_t* semRead,sem_t* semWrite)
{

	*Qptr=(Queue*)malloc(sizeof(Queue));
	if(!Qptr) return AllocationEQ;
	(*Qptr)->m_queueArr=(void**)malloc(sizeof(void*)*capacity);
	if(!(*Qptr)->m_queueArr) return AllocationEQ;
	(*Qptr)->m_capacity=capacity;
	(*Qptr)->m_index=0;
	sem_init(&((*Qptr)->m_semRead),0,(*Qptr)->m_capacity);
	sem_init(&((*Qptr)->m_semWrite),0,(*Qptr)->m_capacity);
	return OKQ;	
}

status_Queue write2Queue(Queue* Qptr)
{
	char message[]="semaphore is awsoeme";
	int i=0;

	if(!Qptr) return nullEQ;

	while(i<5)
	{
		pthread_mutex_lock(&(Qptr->m_mutex));
		sem_wait(&(Qptr->m_semWrite));
		if(Qptr->m_queueArr[Qptr->m_index]!=message)
		{
			Qptr->m_queueArr[Qptr->m_index]=message;
			printf("write a message\n");
			Qptr->m_index++;
		}
		else printf("no space to write\n");
		
		
		sem_post(&(Qptr->m_semRead));
		i++;
		pthread_mutex_unlock(&(Qptr->m_mutex));
	}
	
	return OKQ;

}

status_Queue readFromQueue(Queue* Qptr)
{
	int i=0;

	if(!Qptr) return nullEQ;

	while(i<5)
	{
		pthread_mutex_lock(&(Qptr->m_mutex));
		sem_wait(&(Qptr->m_semRead));
		
		
		Qptr->m_queueArr[Qptr->m_index]="0";
		printf("Read a message\n");
		Qptr->m_index--;
	
		
		
		
		sem_post(&(Qptr->m_semWrite));
		i++;
		pthread_mutex_unlock(&(Qptr->m_mutex));

	}
	
	return OKQ;
}

status_Queue destroyQueue(Queue* Qptr/*,functDestroy* func*/)
{
	int i=0;
	if(!Qptr) return nullEQ;
	if(!Qptr->m_queueArr) return nullEQ;
	free(Qptr->m_queueArr);
	free(Qptr);	
	return OKQ;
}

/*
writing a thor with a pair of semaphore for writing and reading and mutex.
write
read
to check this- create a group of threads that read and write by thor. 

wqueve.h
wqueve.c->thor
producers.c+header
consumers.c+header
prodcons.c -> main
poison apple
*/