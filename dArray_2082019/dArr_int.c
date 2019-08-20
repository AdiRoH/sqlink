#include<stdlib.h>
#include<stdio.h>
#include "header.h"

struct darray
{
	int* arr;
	unsigned int index;
	unsigned int capacity;
	unsigned int initial_capacity;
};

AdtStatus darrayCreate(darray** dArr, size_t initial_capacity)
{
	*dArr=(darray*)malloc(sizeof(darray));
	if(*dArr==NULL)
	{
		return AllocationError;
	}
	
	(*dArr)->arr=(int*)malloc(sizeof(int)*initial_capacity);
	if((*dArr)->arr==NULL)
	{
		return AllocationError;
	}

	if(initial_capacity<=0)
	{
		return WrongInput;
	}

	(*dArr)->capacity=initial_capacity;
	(*dArr)->initial_capacity=initial_capacity;
	(*dArr)->index=0;

	return OK;
}

AdtStatus darrayDestroy(darray* dArr)
{
	if(dArr==NULL)
	{
		return AllocationError;
	}
	if(dArr->arr==NULL)
	{
		return AllocationError;
	}

	free(dArr->arr);
	free(dArr);
	return OK;
}

AdtStatus darrayAdd(darray* dArr,  int  _item)
{
	int* temp;

	if(dArr==NULL)
		return AllocationError;
	if(dArr->arr==NULL)
		return AllocationError;
	
	if(dArr->index==0.75*(dArr->capacity))
	{
		temp=dArr->arr;	
		dArr->arr=(int*)realloc(dArr,(dArr->capacity)*2);
		if(dArr->arr==NULL)
		{
			dArr->arr=temp;
			return AllocationError;
		}
	
		(dArr->capacity)*=2;
	}
	
	dArr->arr[dArr->index]=_item;
	dArr->index+=1;
	return OK;
}

AdtStatus darrayDelete(darray *dArr,  int* _item)
{
	int* temp=dArr->arr;

	if(dArr==NULL)
		return AllocationError;
	if(dArr->arr==NULL)
		return AllocationError;
	if(_item==NULL)
		return AllocationError;
	if(dArr->index<0)
		return ExceedingIDX;
	*_item=dArr->arr[dArr->index];

	if(dArr->index==dArr->initial_capacity*0.75)
	{
		dArr->arr=(int*)realloc(dArr,dArr->capacity/2);
	}

	if(dArr->arr==NULL)
	{
		dArr->arr=temp;
		return AllocationError;
	}
	dArr->index-=1;
	return OK;
	
}

AdtStatus  darrayGet(darray* dArr, size_t _index, int* _item)
{
	if(dArr==NULL)
		return AllocationError;
	if(dArr->arr==NULL)
		return AllocationError;
	if(_item==NULL)
		return AllocationError;
	if(_item==NULL)
		return AllocationError;
	if(_index<0)
		return WrongInput;
	if(_index>=dArr->capacity)
		return ExceedingIDX;
	*_item = dArr->arr[_index];
	return OK;
}

AdtStatus  darraySet(darray *dArr, size_t _index, int  _item)
{
	if(dArr==NULL)
		return AllocationError;
	if(dArr->arr==NULL)
		return AllocationError;
	if(_index<0)
		return WrongInput;
	if(_index>=dArr->capacity)
		return ExceedingIDX;

	dArr->arr[_index]=_item;
	return OK;
}

AdtStatus darrayItemsNum(darray *dArr, int*  _numOfItems)
{
	if(dArr==NULL)
		return AllocationError;
	if(dArr->arr==NULL)
		return AllocationError;
	if(_numOfItems==NULL)
		return AllocationError;
	*_numOfItems = dArr->capacity;
	return OK;
}

static int swap(int* arr, int i, int j)
{
	int temp;

	if(arr==NULL)
		return 0;
	temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
	return 1;
}

AdtStatus darraySort(darray *dArr)
{
	int i=0,j=0;

	if(dArr==NULL)
		return AllocationError;
	if(dArr->arr==NULL)
		return AllocationError;

	for(i=0;i<dArr->capacity;i++)
	{
		for(j=i;j<dArr->capacity;j++)
		{
			if(dArr->arr[i]<dArr->arr[j])
			{
				swap(dArr->arr,i,j);
			}
		}
	}

	return OK;
}

void printError(int res)
{
		switch(res)
		{
			case 0:
				{
					printf("\nAllocationError\n\n");
					break;
				}

			case 1:
				{
					printf("\nOK\n\n");
					break;
				}
				
			case 2:
				{
					printf("\nWrongInput\n\n");
					break;
				}
			case 3:
				{
					printf("\nExceedingIDX\n\n");
					break;
				}
		}

}

int printArr(darray* dArr)
{
	int i=0;

	if(dArr==NULL)
		return AllocationError;
	if(dArr->arr==NULL)
		return AllocationError;
	for(i=0;i<dArr->capacity;i++)
	{
		printf("%d", dArr->arr[i]);
	}
	return OK;
}