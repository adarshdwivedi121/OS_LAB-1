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
int n,i,j,k;
int S=0;

void table()
{
	printf("+-----------------------------------------------------------+\n");
	printf("|\tPID |\tAT |\tBT |\tCT |\tTAT |\tWT |\tPR |\n");
	printf("+-----------------------------------------------------------+\n");
	for(i=0; i<n; i++)
	{
		printf("|\t%2d  | \t%2d | \t%2d | \t%2d | \t%2d  | \t%2d | \t%2d | \n",A[i].PID,A[i].AT,A[i].BT,A[i].CT,A[i].TAT,A[i].WT,A[i].PR);
		printf("+-----------------------------------------------------------+\n");
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
		printf("\nProcess ID: ");			scanf("%d",&A[i].PID);
		printf("Arrival Time: ");			scanf("%d",&A[i].AT);
		printf("Burst Time  : ");			scanf("%d",&A[i].BT);
		printf("Priority    : ");			scanf("%d",&A[i].PR);
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
	for(i=0; i<n; i++)
	{	
		S+=A[i].BT;
		A[i].CT = S;
		
		for(j=i+1;j<n;j++)
			for(k=j;k<n-i-1;k++)
			{
				if(A[k].PR>A[k+1].PR && A[k].AT<A[i].CT)
				{
					temp = A[k];
					A[k] = A[k+1];
					A[k+1] = temp;					
				}
			}
		
	}
}

void calc()
{
	for(i=0; i<n; i++)
		{	
			A[i].TAT = A[i].CT - A[i].AT;
			A[i].WT = A[i].TAT - A[i].BT;
			if(A[i].WT<0)	A[i].WT=0;	
		}
}

void lol()
{
	float AV_TAT=0.0,AV_WT=0.0;
	for(i=0; i<n; i++)
	{	
		AV_TAT+=A[i].TAT;
		AV_WT +=A[i].WT ;
	}
	AV_TAT/=n;
	AV_WT /=n;
	printf("\nAverage Turnaround Time: ");		printf("%f",AV_TAT);
	printf("\nAverage Waiting Time   : ");		printf("%f",AV_WT);
	printf("\n");
}

int main()
{
	
	input();	
	sorter();
	calc();
	table();
	chart();
	lol();
	
	
	
	return 0;
}

