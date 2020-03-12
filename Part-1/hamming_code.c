#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int dw[20];
int cw[20];

int main()
{
	int n, i,j,k, pnum = 0,total;
	printf("Enter the length of the Data Word: ");
	scanf("%d",&n);
	printf("Enter the Data Word:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&dw[i]);
	}

	while(n>(int)pow(2,pnum)-pnum-1)
	{
		pnum++;
	}
	total = pnum + n;

	j=k=0;
	for(i=0;i<total;i++)
	{
		
		if(i==((int)pow(2,k)-1))
		{
			cw[i]=0;
			k++;
		}
		else
		{
			cw[i]=dw[j];
			j++;
		}
	}
	for(i=0;i<pnum;i++)
	{
		int p = (int)pow(2,i);
		int count=0,i,j, val;
		i=p-1;
		while(i<total)
		{
			for(j=i;j<i+p;j++)
			{
				if(cw[j] == 1)
					count++;
			}
			i=i+2*p;
		}
		if(count%2 == 0)
			val=0;
		else
			val=1;
		cw[p-1]=val;
	}
	printf("\nCode Word: ");
	for(i=0;i<total;i++)
		printf("%d",cw[i]);
}

	

