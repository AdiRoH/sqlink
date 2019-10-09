#include "allocation.h"
#include <stddef.h>
#include <stdio.h>

static char* isDevideBy4_end(char* Arr,unsigned int size);
static void* isDevideBy4_start(char* buff);
static char* find(char* buff,char* startArr,unsigned int amountAllo, unsigned int sizeArr);
static void EmptyBit(char* adrress);
static void AlloBit(char* adrress);

void* memInit(char* buff, unsigned int size)
{
	char* end;
	void *startArr;

	if(!buff) return NULL;
	if(size<=0) return NULL;

	startArr=isDevideBy4_start(&buff[0]);
	end=isDevideBy4_end(buff,size);
	end = (0x00000000000000FCl)&(unsigned long)end; 
	(unsigned long)*startArr=(unsignedlong)size+1000000000000000l;
	return startArr;  
}

static char* isDevideBy4_end(char* Arr,unsigned int size)
{
	int i=size-1;

	if(!Arr) return NULL;
	if(size<=0) return NULL;

	while((((unsigned long)(Arr[i]) & 0x0000000000000003l))!=0l)
	{
		i--; 
	}
	
	return (void*)&Arr[i];	
}


static void* isDevideBy4_start(char* buff)
{
	int i=0;
	if(!buff) return NULL;

	while((((unsigned long)(buff[i]) &  0x0000000000000003l))!=0l)
	{
		i++;
	}
	
	return (void*)&buff[i];
}

/*
0x7ffff7fb1f60   140737353817952 divided by 4
0x7ffff7fb1f61   140737353817953
0x7ffff7fb1f62   140737353817954
*/


void* memAlloc(char* buff,unsigned int size, void* startArr,unsigned int amountAllo)
{
	char *place;

	if(!buff) return NULL;
	if(!startArr) return NULL;
	if(size<=0) return NULL;
	if(amountAllo<=0) return NULL;
	
	place = find(buff,(char*)startArr,amountAllo,size);
	if(place==NULL) return NULL;
	AlloBit(place);
	EmptyBit(place+amountAllo);
	return (void*)buff;
}


static char* find(char* buff,char* startArr,unsigned int amountAllo, unsigned int sizeArr)
{
	int i=0,j=0;
	int res=0,shift=0;
	/*char* alloPlace=&buff[0];*/

	if(!buff) return NULL;
	if(!startArr) return NULL;
	if(sizeArr<=0) return NULL;
	if(amountAllo<=0) return NULL;

	for(i=0;i<sizeArr;i++)
	{
		for(j=i;j<=amountAllo+4;j++)
		{
			if(((unsigned long)&buff[j] & 0X0000000000000100l)==1l) /*if free or not*/
			{
				res+=1;
			}
			else
			{
				shift=(unsigned long)buff[j]&0x0000000000000100l;
				buff[j]=buff[j]+shift;
				break;
			}
			if(res==amountAllo) return &buff[j];

		}

		i+=shift;
		/*&astatic void AlloBit(char* adrress)lloPlace=buff;*/	
	}
	return NULL;

}



static void EmptyBit(char* adrress)
{
	if(!adrress)return;
	adrress = 0X7FFFFFFF&(unsigned long)adrress;
}

static void AlloBit(char* adrress)
{
	if(!adrress)return;
	adrress = 0XFFFFFFFF&(unsigned long)adrress;
}





void* memFree(char* buff, unsigned int size,char* freeBlock)
{
	
}


