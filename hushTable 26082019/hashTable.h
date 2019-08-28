#ifndef hashMap
#define hashMap

typedef enum STATUS{OK=1}STATUS;
typedef struct Hash Hash;

typedef unsigned long(*hashFunc)(void* key);
typedef void*(forEachAct)(void* key,void *val);
typedef int(*cmpKeys)(void* key1,void* key2);

STATUS create_HashTable(Hash **hashMap,long size,hashFunc Hash_Fanc,cmpKeys cmp);
STATUS insert(Hash* hashMap,void* key,void* value);
STATUS find(Hash* hashMap, void* key, void* value);
/*STATUS compare(void* key);
STATUS forEach(forEachAct*,void* key,void* value;)*/


#endif



/*
user:
provide to hush table the hush function


hashFunc(void*)

hsah create(hash function)
hash table Destroy
hashtable insert
hashtable find(void* key, void* value,*u
key->for example, pointer to string. 
val5,ue=hashFunc(key);
table(value)

compare(void* key, void* key)


transfer key to hash function, get the value. 
hashtable FOR EACH

hushtable store pairs of key+its value;

struct hush table
{
	void** arr;

}

create(sizt_t size)
malloc (1.3*size)

insert(void* key,void* value)
{
	key%2
}

forEach-checl all the element of hush table


*/