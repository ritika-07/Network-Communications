#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
	char a[3]="yes";
	while (strcmp(a,"yes")==0)
	{
		int i, n,rem, sum=0;
		printf("\nEnter dataword: ");
		scanf("%d",&n);
		i=n;
		while(i>0)
		{
			rem=i%10;
			sum=sum+rem;
			i=i/10;
		}
		if (sum%2==0)
		{
			printf("Parity bit: %d \nCodeword: %d%d",0,n,0);
		}
		else
		{
			printf("Parity bit: %d \nCodeword: %d%d",1,n,1);
		}
		printf("\nDo you want to continue? ");
		scanf("%s",a);
	}
	return 0;
}
