#ifndef consumers
#define consumers

	typedef struct Consumers Consumers;	
	typedef enum status_Consumer{OK_c=1,nullE_c=2,allocationE_c=3} status_Consumer;
	

	status_Consumer createConsumer(Consumers** cPtr, size_t capacity);
	status_Consumer startConsumers(Consumers* cPtr,Queue* QptrP2C,Queue* QptrC2P);
	void* threadConsumer(void* Qptr);
	status_Consumer consumersDestroy(Consumers* cPtr);


#endif