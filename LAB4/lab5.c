#include <stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#define BUFLEN 10
int main()
{
	char buffer[BUFLEN+1];
	int i;
	pid_t pid;
	for(i=0;i<10;i++)
	pid=fork();
	if(pid==0)
	{
		strncpy(buffer, "CHILD\n", BUFLEN);
	}
	else if(pid > 0)
	{
		strncpy(buffer, "PARENT\n", BUFLEN); //BUFLEN can be replaced with 7
		//buffer[BUFLEN] = '\0';
	}
	else if(pid == -1)
	{
		printf("ERROR\n");
		switch(errno)
		{
			case EAGAIN : printf("Can't fork: Process limit reached");
			break; 
			case ENOMEM : printf("Can't fork : Out of memory");
		}
	return 1;
	}
	for(i=0;i<10;i++)
	{
		sleep(1);
		write(1,buffer, strlen(buffer));
	}
	return 0;
} 
