#include<stdio.h>
#include<stdlib.h>
#include "dinamicAlocation.h"

Array_t* creatArray(int capacity)
{
	Array_t* array;
	array=malloc(sizeof(Array_t));
	if(array==NULL)
		return NULL;
	array->arr=malloc(capacity*sizeof(int));
	array->capacity=capacity;
	array->index=0;
	return array;
}


int insert(Array_t* ptr,int Num)
{	
	int* address=ptr->arr;
	if((ptr->index)<(ptr->capacity))
	{	
		ptr->arr[ptr->index]=Num;
		ptr->index+=1;
	}
	else 
	{
		ptr->arr=(int*)realloc(ptr->arr,(ptr->capacity*2)*sizeof(int));
		if(ptr->arr==NULL)
		{
			ptr->arr=address;
			return -1;
		}
		else
		{
			ptr->arr[ptr->index]=Num;
				
		}
	}	
	return 1;
}

void print(Array_t *ptr)
{
	int i;	
	for(i=0;i<ptr->capacity;i++)	
		printf("%d",ptr->arr[i]);
}

void destroyDA(Array_t *ptr)
{
	free(ptr->arr);
	free(ptr);
}
