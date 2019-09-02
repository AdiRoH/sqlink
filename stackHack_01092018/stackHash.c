#include <stdio.h>
#include <stdlib.h>

void b(int param);

void a(void* ptr)
{
	void** ptr2=&ptr;
	ptr2--;
	*ptr2=b;
}

void b(int param)
{
	printf("Function b\n");
}

int main()
{
	void* ptr=b;
	a(ptr);
}


