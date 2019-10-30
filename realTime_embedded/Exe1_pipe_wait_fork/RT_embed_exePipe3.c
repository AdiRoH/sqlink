#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*Write a watchdog type double process.

The watchdog is the parent
The interesting process is the child

The parent will restrart the child whenever the child
dies of *absnormal circumstances*.

If the child dies of normal circumstances, the watchdog will
terminate as well.

Use:
	fork
	wait

*/

int main()
{
	int state;

	if(fork()==0)
	{
		execlp("/usr/bin/ls","/usr/bin/ls",NULL);

	}
	else
	{
		wait(&state);/*change parameters;*/
		if(WIFSIGNALED(state)/*||WCOREDUMP(state)*/)
		{
			/*goto??*/
		}
	}
}