#include<stdio.h>
#include<unistd.h>

void main()
{
	execlp("ls","ls","-l",NULL);
	printf("DONE!\n");
	
}
