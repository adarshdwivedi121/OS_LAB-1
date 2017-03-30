#include<stdio.h>
#include<unistd.h>

void main()
{
	int id;
	id=fork();
	if(id==0)
	{
		printf("--Child Process--\n");
		printf("PID: %d\n", getpid());
		printf("PPID: %d\n", getppid());
	}
	else
	{
		printf("--Parent Process--\n");
		printf("PID: %d\n", getpid());
		printf("PPID: %d\n", getppid());
	}
}
