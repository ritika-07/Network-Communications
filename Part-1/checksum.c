#include <stdio.h>
#include <string.h>
int main()
{
 int sinput[4], rinput[4], s_check, r_check, s_sum=0, r_sum=0,i;
 printf("\nAt sender:");
 printf("\nEnter the hexadecimal data words: ");
 
 for(i=0;i<4;i++)
 {
  scanf("%x", &sinput[i]);
 }
 s_check=0000;
 
 for(i=0; i<4; i++)
 {
  s_sum=s_sum+sinput[i];
 }
 
 s_sum=s_sum+s_check;
 printf("\nSum: %x", s_sum);
 s_sum=s_sum+1;
 s_sum=~s_sum;
 printf("\nChecksum: %x", s_sum);

 printf("\n\n\nAt receiver:");
 char ch[4];
 strcpy(ch,"yes");do
 {
	 printf("\nEnter the values in hex: ");
	 
	 for(i=0;i<4;i++)
	 {
	  scanf("%x", &rinput[i]);
	 }
	 r_check=s_sum;
	 
	 for(i=0; i<4; i++)
	 {
	  r_sum=r_sum+rinput[i];
	 }
	 
	 r_sum=r_sum+r_check;
	 printf("\nSum: %x", r_sum);
	 r_sum=r_sum+1;
	 r_sum=~r_sum;
	 printf("\nChecksum: %x", r_sum);

	 if(r_sum==0000)
	  printf("\nNo Error");
	 else
	  printf("\nError");
	  printf("\n\nCheck for error again? ");
	  scanf("%s",ch);
 }while(strcmp(ch,"yes")==0);
 return 0;
}
