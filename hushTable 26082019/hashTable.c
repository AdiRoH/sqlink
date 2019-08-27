#include<stdlib.h>
#include "hashTable.h"

struct Hash
{
	void** m_buckets;
	unsigned long m_size;
	hashFunc m_hshMap;
	cmpKeys m_cmprKeys;
};

struct Node
{
	size_t m_index;
	void* m_key;
	void* m_value;
	struct Node* m_lst;
};
typedef struct Node Node;


STATUS create_HashTable(Hash **hashMap,size_t size,hashFunc Hash_Func,cmpKeys cmp)
{
	size_t sizeOfElem=sizeof(Node);
	size_t numOfElem=size*1.3;

	/*check address of argument*/
	if(hashMap==NULL) return AddressERROR;
	if(size==0) return ExceedingIDX;
	if(Hash_Func==NULL) return AddressERROR;
	if(cmp==NULL) return AddressERROR;

	/*allocation memory to the Hash struct*/
	*hashMap=(Hash*)malloc(sizeof(Hash));
	if(*hashMap==NULL) return AllocationERROR;

	/*allocation zero values to array of buckets*/
	(*hashMap)->m_buckets=(Node**)calloc(numOfElem,sizeOfElem);
	if((*hashMap)->m_buckets==NULL) 
	{
		free(*hashMap);
		return AllocationERROR;	
	}

	/*put values in the Hash struct*/
	(*hashMap)->m_size=size;
	(*hashMap)->m_hshMap=Hash_Func;
	(*hashMap)->m_cmprKeys=cmp;

	return OK;
}

static STATUS search(Hash* hashMap,Node** nd,void *value, void* key, unsigned long* index)
{
    unsigned long hash;
    Node* list;
    
   
    /*Calculating index by hash function and mod it*/
    hash=hashMap->m_hshMap(key);
    *index=hash%(hashMap->m_size);

    /*If hash table is empty in the index...*/
    if(hashMap->m_buckets[*index]==NULL) return ExceedingIDX;

    /*Put the first chain of the list into a Node struct*/
    list=hashMap->m_buckets[*index];

    /*Search value in the node, by comparing the value with every node's value*/
    while(list!=NULL)
    {
        if(!hashMap->m_cmprKeys(list->m_key,value)) 
        {
            *nd = list;
            return OK;
        }
    }

    return notFound;   
}

STATUS insert(Hash* hashMap,void* key,void* value)
{
	int isFound;
	unsigned long index;
	Node* nd,temp,list;
	list=hashMap->m_buckets[index];
	/*First, check if this value is exciting in the table hush*/
	isFound=search(hashMap,&nd,value,key,&index);

	if(isFound==1) return IsAlreadyStored;

	if(isFound==2) /*The tablehash at this index is null*/
	{
		list=(Node*)malloc(sizeof(Node));
		if(==NULL) return AllocationERROR;
		list->m_index=index;
		list->m_key=key;
		list->m_val=value;
		list->m_lst=NULL;
	} 

	if(isFound==4) /*The tablehash at this index contains a context.*/
	/*Adding a Node to the start of the bucket*/
	{
		temp=hashMap->m_buckets[index]->m_lst;
		list=(Node*)malloc(sizeof(Node));

		if(list==NULL) return AllocationERROR;
		list->m_index=index;
		list->m_key=key;
		list->m_value=value;

		list->m_lst=temp;
	}


	return OK;
}

STATUS find(Hash* hashMap, void* key, void* value)
{
	Node* nd;
	int res;

	res=search(hashMap,&nd,value);	
	
	return res;
}

STATUS delete(Hash* hashMap,void* key,void* value)
{
	int res;
	Node* nd;
	unsigned long index;

	/*check addresses of arguments*/
	if(hashMap==NULL) return AddressERROR;
	if(key==NULL) return AddressERROR;
	if(value==NULL) return AddressERROR;

	/*first- check if there is what to delete,wheather it null or not */
	/*if(isFound==1)->delete->loop on all the list. if this is in the end-> put null. if this is the head, initialize it with tthe next chain. if this is in the middle
	/*if (value not found)-> error message;*/
	res=(hashMap,&nd, value, key, &index);
	if(res==2)//null in the index
		return res;
	if(res==4)//not found
		return res;
	if(res==1)//delete element

}