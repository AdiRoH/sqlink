#include "progB.h"
#include <stdio.h>
#include "libN.h"

void funcA()
{
	printf("\nFruits\n\n");
	printLib1();
	printLib3();

}



int main()
{
	funcA();
	funcB();
	return 1;
}

