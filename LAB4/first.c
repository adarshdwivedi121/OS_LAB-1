#include<stdio.h>
#include<unistd.h>

void main()
{
	pid_t id;
	printf("This is the main process.\n");
	id=fork();
	printf("New process.\n");
	printf("ID : %d \n", id);
}
