#ifndef wqueue
#define wqueue
#include <semaphore.h>

	typedef enum status_Queue{OKQ=1,nullEQ=2,AllocationEQ=3}status_Queue;

	typedef struct Queue Queue;
	

	status_Queue createQueue(Queue** Qptr,size_t capacity,sem_t* semRead,sem_t* semWrite);
	status_Queue write2Queue(Queue* Qptr);
	status_Queue readFromQueue(Queue* Qptr);
	status_Queue destroyQueue(Queue* Qptr/*,functDestroy* func*/);

#endif
