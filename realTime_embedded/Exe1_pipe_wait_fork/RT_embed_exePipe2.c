/*Run the command "ls | wc -l" without a shell.
Fork twice, setup the pipe right, make sure to close the right file descriptors and exec after all is done.
Print a message when the entire process is done.*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int main()
{
	/*the 2 process has to split from shell*/

	int fd[2];/*declare an array of 2 elements*/
]]
	/*char args[]={"/usr/bin/ls",NULL};
	char args2[] = {"/usr/bin/wc",NULL};*/


	pipe(fd);/*put descriptor in each element of the array
	0-read
	1-write*/

	if(fork()==0)/*child*/
	{
		close(1);/*closing the standart output//need to close 1 before pipe*/
		execlp("/usr/bin/ls","/usr/bin/ls", NULL);

	}

	else/*father,the shell*/
	{
		if(fork()==0)/*child*/
		{
			close(0);/*closing the standart output//need to close 1 before pipe*/
			execlp("/usr/bin/wc", "/usr/bin/wc",NULL);
		}
		else
		{
			wait(NULL);
			return EXIT_SUCCESS;
		}
	}
}



