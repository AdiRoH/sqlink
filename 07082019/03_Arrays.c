#include<stdio.h>

void printArray(int* arr,int size);
void swap(int* a,int* b);
void bubbleSort(int *arr,int size);
void ascending(int* arr,int size);

/*
void sort(int* arr,int size)
{
	int middle=1+(size-1)/2,i,j;
	for(i=0,j=size-1;i<=middle;i++,j--)
	{
		(arr[i]>arr[j])?swap(&arr[i],&arr[j])
	}
}
*/

int main()
{
	int arr[]={1,1,0,0,1,0,1,1},size=9,i;
	printArray(arr,size);
	bubbleSort(arr,size);
	printf("\n\n");
	printArray(arr,size);
	printf("\n");
	return 0;
}

void printArray(int* arr,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d\t",arr[i]);
	}
}

void swap(int* a,int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void bubbleSort(int *arr,int size)
{
	int i,j;
	for(i=0;i<size-1;i++)
		for(j=1;j<size-1;j++)
		{
			if(arr[j-1]>arr[j])
			{
				swap(&arr[j-1],&arr[j]);
			}	
		}
}

void ascending(int* arr,int size)
{
	int i;
	for(i=1;i<size-1;i++)
	{
		(arr[i-1]>arr[i])?swap(&arr[i-1],&arr[i]);
	}
}
