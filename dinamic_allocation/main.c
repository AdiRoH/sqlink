#include<stdio.h>
#include "dinamicAlocation.h"

int main()
{
	int capacity,num,res;
	Array_t* array;
	printf("Insert a capcity\n");
	scanf("%d",&capacity);
	array=creatArray(capacity);

	printf("Insert a number\n");
	scanf("%d",&num);
	res=insert(array,num);
	print(array);
	destroyDA(array);


	return 0;
}
