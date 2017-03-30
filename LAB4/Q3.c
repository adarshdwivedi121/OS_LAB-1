#include<stdio.h>
#include<unistd.h>
#include<string.h>

void main(int argc, char *argv[])
{
	int id,id2,i,j;
	char t[10];
	for (i = 0; i < argc; i++)
      		printf("String %d: %s\n", (i+1),argv[i]);
	
	
	id=fork();
	id2=fork();
	if(id==0)
	{
		printf("\n--Child Process--\n");
		printf("PID: %d\n", getpid());
		printf("PPID: %d\n", getppid());

		for (i = 1; i < argc; i++) 
		{
		    for (j = 1; j < argc; j++) 
			{
			 	if (strcmp(argv[j - 1], argv[j]) > 0) 
				{
			    	strcpy(t, argv[j - 1]);
			    	strcpy(argv[j - 1], argv[j]);
			    	strcpy(argv[j], t);
			 	}
			}
		}

		for (i = 0; i < argc; i++)
      		printf("String %d: %s\n", (i+1),argv[i]);
	}


	else
	{
		wait();
		printf("--Parent Process--\n");
		
		printf("PID: %d\n", getpid());
		printf("PPID: %d\n", getppid());
	}
}
