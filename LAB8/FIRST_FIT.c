#include<stdio.h>
#include<limits.h>
void main()
{
	int h[20],p[20],i,j,nh,np;
	printf("Number of Holes >> ");
	scanf("%d",&nh);
	for(i=0;i<nh;i++)
	{
		printf("Size (Hole %d) >> ",i);
		scanf("%d",&h[i]);
	}	
	printf("\n----------------\n");
	printf("\nNumber of Processes >> ");
	scanf("%d",&np);
	printf("\n----------------\n");
	for(i=0;i<np;i++)
	{
		printf("Size (Process %d) >> ",i);
		scanf("%d",&p[i]);
	}
	
	for(i=0;i<nh;i++)
	{
		for(j=0;j<np;j++)
		{
			if(p[j]<=h[i])
			{
			    printf("Process %d = Hole %d\n",j,i);
			    p[j]=INT_MAX;
			    h[i]=INT_MIN;
			    break;
			}
		}
	}
	
	for(j=0;j<np;j++)
		if(p[j]!=INT_MAX)		printf("Process %d unallocated.\n",j);
		
}

		
		
		
		
		
		
