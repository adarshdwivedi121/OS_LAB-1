#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
void main()
{
	pid_t id;

	printf("This is a C program\n");
	id=fork();
	printf("After fork()\n");
	printf("id= %d\n",id);	
}
