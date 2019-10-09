#include<stdio.h>
#include<stddef.h>
#include "header.h"

int main()
{
	int opt=10,itemAdd,itemDel,getItem,itemSet,numOfItems=0;
	int res_create=0,res_destroy=0,res_addNum=0,res_DelNum=0,res_get=0,res_set=0,res_returnSize=0,res_sortArr=0,res;
	size_t size, idxGet,idxSet;
	darray* darr;

	typedef enum menu{createArr=1,destroyArr=2,addNumber=3,deleteNumber=4,get=5,set=6,returnSize=7,sortArr=8}menu;
	while(opt>0)
	{
		printf("1:\tcreate array\n\n");
		printf("2:\tdestroy array\n\n");
		printf("3:\tadd a number to the end\n\n");
		printf("4:\tdelete a number from array\n\n");
		printf("5:\tget a number\n\n");
		printf("6:\tset a number\n\n");
		printf("7:\treturn size of arr\n\n");
		printf("8:\tsort the array\n\n");
		scanf("%d",&opt);
		
		switch(opt)
		{
			case createArr:
			{
				printf("Insert size of array\n\n");
				scanf("%zu",&size);
				res_create=darrayCreate(&darr,size);
				/*darr->initial_capacity=size;*/
				printError(res_create);
				break;
			}
			case destroyArr:
			{
				res_destroy = darrayDestroy(darr);
				printError(res_destroy);
				break;
			}
			case addNumber:
			{
				printf("Type the item that you want to add\n\n");
				scanf("%d",&itemAdd);
				res_addNum=darrayAdd(darr, itemAdd);
				printError(res_addNum);
				printArr(darr);
				break;
			}
			case deleteNumber:
			{
				res_DelNum=darrayDelete(darr, &itemDel);
				printError(res_DelNum);
				printArr(darr);
				break;
			}
			case get:
			{
				printf("Insert index of item that you want to get\n\n");
				scanf("%zu",&idxGet);
				res_get=darrayGet(darr,idxGet, &getItem);
				printError(res_get);
				printf("the item in index %zu is: %d\n\n",idxGet,getItem);
				break;
			}
			case set:
			{
				printf("Insert a value of item\n\n");
				scanf("%d",&itemSet);
				res_set=darraySet(darr, idxSet, itemSet);
				printError(res_set);
				printArr(darr);
				break;
			}
			case returnSize:
			{
				res_returnSize=darrayItemsNum(darr, &numOfItems);
				printError(res_returnSize);
				printf("number of elements:  %d\n\n",numOfItems);
				break;
			}
			case sortArr:
			{
				res_sortArr=darraySort(darr);
				printError(res_sortArr);
				printArr(darr);
				break;
			}
		}
	}
	return 1;
}