#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
	int pipe_[2];
	pid_t pid;
	char *message="hi",*react="bi";
	char buff[50];

	pipe(pipe_);
	/*pipe[0]-read,pipe[1]-write*/
	
	pid=fork();
	if(pid<0) return;

	if(pid>0)/*father*/
	{
		write(pipe_[1],message,sizeof(message));
	}

	if(pid==0)/*child*/
	{
		read(pipe_[0],buff,sizeof(message));
		write(pipe_[1],react,sizeof(react));
		printf("%s\n",buff);
	}

	return 1;
}
