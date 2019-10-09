#include <sys/types.h>
#include <unistd.h>


int main()
{
	pid_t pid;
	char path[]={"/home/adi/Desktop/OOP/writingShell_29082019/exe"};
	char exe[]={"exe"};

	pid=fork();
	
	if(pid==0)
	{
		execl(path, exe,(char*)NULL);
	}

	waitpid();

	return 0;
}