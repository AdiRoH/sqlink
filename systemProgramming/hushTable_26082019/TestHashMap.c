#include <stdio.h>
#include <string.h>
#include "hashTable.h"

unsigned long hash1(void* key);
int cmpKeys5(void* key1,void* key2);

int main()
{
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