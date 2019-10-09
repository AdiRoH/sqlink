#include "allocation.h"
#include <stdio.h>

char Buffer[10000000];

int main()
{
	void* startArr;
	printf("the original first adress is:%p\nthe original end adress is:%p\n",&Buffer[0],&Buffer[10000000]);
	startArr = memInit(Buffer,10000000);
	printf("\n\nthe first adress is:%p\nthe end adress is:%p\n",startArr,&Buffer[10000000]);

	printf("%p %p %p\n\n",&Buffer[99],&Buffer[100],&Buffer[101]);
	memAlloc(Buffer,100000000, startArr,100);
	printf("%p %p %p",&Buffer[99],&Buffer[100],&Buffer[101]);
	return 1;
}

