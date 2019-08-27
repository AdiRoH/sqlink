#ifndef hashTable
#define hashTable

typedef enum STATUS{AddressERROR=0,OK=1,ExceedingIDX=2,AllocationERROR=3,notFound=4,IsAlreadyStored=5}STATUS;
typedef struct Hash Hash;

typedef unsigned long(*hashFunc)(void* key);
typedef void*(forEachAct)(void* key,void *val);
typedef int(*cmpKeys)(void* key1,void* key2);

STATUS create_HashTable(Hash **hashMap,size_t size,hashFunc Hash_Fanc,cmpKeys cmp);
STATUS insert(Hash* hashMap,void* key,void* value);
STATUS find(Hash* hashMap, void* key, void* value);

#endif