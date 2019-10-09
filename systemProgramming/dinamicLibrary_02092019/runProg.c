#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
/*#define _GNU_SOURCE*/
	
void (*printLib)();
void (*printLib2)();
void (*printLib3)();

int main()
{
	void *handle, *handle2, *handle3;


	handle = dlopen("./libN.so", RTLD_LAZY);
    if (!handle) 
    {
        exit(-1);

    }

    *(void **)(&printLib) = dlsym(handle, "printLib1");
    printLib();
    printf("\n");

    handle2 = dlopen("./libN.so", RTLD_LAZY);
    if (!handle2) 
    {
        exit(-1);

    }
    *(void **)(&printLib2) = dlsym(handle2, "printLib2");
    printLib2();
    printf("\n");

    handle3 = dlopen("./libN.so", RTLD_LAZY);
    if (!handle3) 
    {
        exit(-1);

    }
	*(void **)(&printLib3) = dlsym(handle3, "printLib3");
    printLib3();
    printf("\n");  

    return 0;
	
}
