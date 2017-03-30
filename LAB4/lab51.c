#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
	int number, statval=0;
	printf("%d: I'm the parent !\n", getpid());
	if(fork() == 0)
	{
		number = 10;
		printf("PID %d: exiting with number %d\n", getpid(), number);
		exit(number);
	}
	else
	{
		printf("PID %d: waiting for child\n", getpid());
		wait(&statval);
		if(WIFEXITED(statval))
			printf("Child's exit code %d\n", WEXITSTATUS(statval));
		else
			printf("Child did not terminate with exit\n");
	}
return 0;
}
