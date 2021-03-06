#include<stdio.h>

typedef struct
{
	int PID;
	int AT;		//Arrival
	int BT;		//Burst
	int PR;		//Priority: Default = 0
	int CT;		//Completion
	int TAT;	//Turnaround
	int WT;		//Waiting
} PCB;

PCB A[10];
int n,i,j;
int S=0;

void table()
{
	printf("+--------------------------------------------------+\n");
	printf("|\tPID |\tAT |\tBT |\tCT |\tTAT |\tWT |\n");
	printf("+--------------------------------------------------+\n");
	for(i=0; i<n; i++)
	{
		printf("|\t%2d  | \t%2d | \t%2d | \t%2d | \t%2d  | \t%2d | \n",A[i].PID,A[i].AT,A[i].BT,A[i].CT,A[i].TAT,A[i].WT);
		printf("+--------------------------------------------------+\n");
	}
}
void chart()
{
	int z=0;
	for(i=0; i<S; i++)
	{	
		if(A[z].AT>i)
			for(j=i;j<A[z].AT;j++)
				printf("_");
		for(j=0;j<A[z].BT;j++)
			printf("+");
		printf(" %d ",A[z].CT);
		i=A[z].CT;
		z++;	
	}
	
}

void input()
{
	printf("\nEnter number of processes: ");	scanf("%d",&n);
	printf("\n------Enter Process Details------\n");
	for(i=0; i<n; i++)
	{	
		printf("\n---Process %d---",i);
		printf("\nProcess ID: ");		scanf("%d",&A[i].PID);
		printf("Arrival Time: ");		scanf("%d",&A[i].AT);
		printf("Burst Time: ");			scanf("%d",&A[i].BT);
	}
}

void sorter()
{
	PCB temp;
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(A[j].AT>A[j+1].AT)
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;					
			}
		}
}

void calc()
{
	for(i=0; i<n; i++)
		{	
			S+=A[i].BT;
			A[i].CT = S;
			A[i].TAT = A[i].CT - A[i].AT;
			A[i].WT = A[i].TAT - A[i].BT;
			if(A[i].WT<0)	A[i].WT=0;	
		}
}

int main()
{
	
	input();	
	sorter();
	calc();
	table();
	chart();
	
	
	
	return 0;
}











