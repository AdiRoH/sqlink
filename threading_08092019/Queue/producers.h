#ifndef producers
#define producers

	typedef struct Producers Producers;
	typedef enum status_Producers{OK=1,nullE=2,allocationE=3} status_Producers;

	status_Producers createProducers(Producers** pPtr, size_t capacity);
	status_Producers startProducers(Producers* pPtr,Queue* QptrC2P,Queue* QptrP2C);
	void* threadProducer(void* Qptr);
	status_Producers producersDestroy(Producers* pPtr);

#endif

