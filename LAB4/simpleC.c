#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
void main()
{
	pid_t id;

	printf("This is a C program\n");
	id=fork();
	if ( id == 0 )
	{
	printf("Child process\n");
	printf("The value of pid==== %d\n",id);
	printf("Process id = %d, Parent id = %d\n",getpid(),getppid());
	}
	else
	{
	wait(0);
	printf("Parent process\n");
	printf("The value of pid==== %d\n",id);
	printf("Process id = %d, Parent id = %d\n",getpid(),getppid());
	}	
}
