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
	void* m_index;
	void* m_key;
	struct Node* m_lst;
};
typedef struct Node Node;


STATUS create_HashTable(Hash **hashMap,long size,hashFunc Hash_Fanc,cmpKeys cmp)
{
	size_t sizeOfElem=sizeof(Node*);
	size_t numOfElem=size*1.3;
	*hashMap=(Hash*)malloc(sizeof(Hash));

	hashMap->m_bucket=(void**)calloc(numOfElem,sizeOfElem);
	if(hashMap==NULL) return OK;

	hashMap->m_size=size;
	hashMap->m_hshMap=Hash_Fanc;
	hashMap->m_cmprKeys=cmp;

	return OK;
}

static void searchInsert(Node* specificBucket)
{
	while(specificBucket!=NULL)
	{
		specificBucket=specificBucket->m_lst;
	}
}

STATUS insert(Hash* hashMap,void* key,void* value)
{
	void* lastList;
	unsigned long hash, index;

	hash=hashMap->m_hshMap(key);
	index=hash%hashMap->m_size;

	lastList=hashMap->m_buckets[index];
	searchInsert(lastList);
	lastList=(Node*)malloc(sizeof(Node));
	lastList->m_lst=NULL;
	lastList->m_key=key*;
	lastList->m_index=index;
	return OK;
}


static void searchFind(Hash* hashMap,Node** nd,void *value)
{
	unsigned long hash;
	unsigned long index;
	/*start of the list*/

	hash=hashMap->m_hshMap(key);
	index=hash%(hashMap->m_size);

	if(Hash->m_buckets[index]==NULL)/*return*/

	Node* list=Hash->m_buckets[index]
	while(list!=NULL])
	{
		if(!hashMap->m_cmprKeys(list->m_key,value)) 
		{
			*nd = list;
			return OK;
		}
	}
	return notFound;
	
}

STATUS find(Hash* hashMap, void* key, void* value)
{
	Node* nd;
	searchFind(hashMap,&nd,value);	
	

	lastList=hashMap;
	searchFind(lastList);
}


