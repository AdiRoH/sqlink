#include <stdio.h>
#include <string.h>
#include "hashTable.h"

typedef enum menu{createTable=1,InsertKey=2,Find=3}menu;

unsigned long hash1(void* key);
int cmpKeys5(void* key1,void* key2);

int printMenu();
void printError(int res);

Hash* createHashTable();

int main()
{
    int opt=1;
    Hash* hashPtr;
    
    while(opt>0)
    {
        opt=printMenu();
        switch(opt)
        {
            case createTable:
            {
                hashPtr=createHashTable();
                break;     
            }

            case InsertKey:
            {
                char key[50],value[50];

                printf("Insert a key, up to 50 characters\n\n");
                scanf("%s",key);

                printf("Insert a key,, up to 50 characters\n\n");
                scanf("%s",value);

                printError(insert(hashPtr,(void*)&key,(void*)&value));
            }

            case Find:
            {
                break;
            }
        }    
    }
    
	unsigned long l=hash1("Yoseff");
    printf("%lud\n",l);
    return 0;
}




unsigned long hash1(void* key)
{
    unsigned long hash = 5381;
    int c;
    char *str=(char*)key;
    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}


int cmpKeys5(void* key1,void* key2)
{
    char* Key1;
    char* Key2;
    key1=(char*)key1;
    Key2=(char*)key2;

    return(strcmp(Key1,Key2));
}

int printMenu()
{
    int opt=0;
    printf("Choose option\n\n");
    printf("1:\t Create a table hash\n\n");
    printf("2:\t Insert a key");
    printf("3:\t Find a key-value in the hash table\n\n");

    scanf("%d",&opt);
    return opt;
}

void printError(int res)
{
    switch(res)
    {
        case 0:
        {
            printf("AddressERROR\n\n");
            break;
        }

        case 1:
        {
            printf("OK\n\n");
            break;
        }

        case 2:
        {
            printf("ExceedingIDX\n\n");
            break;
        }

        case 3:
        {
            printf("AllocationERROR\n\n");
            break;
        }
    }
}



Hash* createHashTable()
{
    size_t size;
    Hash* hashPtr;
    
    printf("Insert a size of hash table\n\n");
    scanf("%lud",&size);

    printError(create_HashTable(&hashPtr,size,hash1,cmpKeys5));
    return hashPtr;
}