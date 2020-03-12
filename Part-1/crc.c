#include<stdio.h>

int main()

{
     int a[20],c[20],d[20],aux[20],r,i,j,l,in,flag;
		
     printf("\nAt sender");
     printf("\n\nEnter length of dataword : ");
     scanf("%d",&l);

     printf("Enter dataword :\n");
     for(i=0; i<l; i++)
           scanf("%d",&a[i]);

     printf("\nEnter number of redundant bits : ");
     scanf("%d",&r);

     printf("\nEnter divisor :\n");
     for(i=0; i<(r+1); i++)
           scanf("%d",&d[i]);

     for(i=0; i<(l+r); i++){
           if(i<l) 
			c[i]=a[i];
           else 
			c[i]=0;
     }


     for(i=0; i<(l+r); i++)
           aux[i]=c[i];

     for(i=0; i<l; i++){
           in=1;
           if(c[i]==1){
                for(j=i+1; j<(i+l); j++){
                     c[j]=c[j]^d[in];
                     in++;
                }
           }
           else{
                for(j=i+1; j<(i+l); j++)
                     c[j]=c[j]^0;
           }
     }

     printf("\nRemainder : ");
     for(i=l; i<(l+r); i++)
		{
           printf("%d ",c[i]);
		}
     printf("\nSender code word : ");

     for(i=0; i<(l+r); i++){
           if(i<l) 
			c[i]=aux[i];
		printf("%d ",c[i]);
     }

     printf("\n\n\nSince no error inserted");
     printf("\nAt receiver ");
     printf("\nReceived code word :");
     for(i=0; i<(l+r); i++){
		printf("%d ",c[i]);
     }
     for(i=0; i<l; i++){
           in=1;
           if(c[i]==1){
                for(j=i+1; j<(i+l); j++){
                     c[j]=c[j]^d[in];
                     in++;
                }
           }

           else{
                for(j=i+1; j<(i+l); j++)
                     c[j]=c[j]^0;
           }
     }

     printf("\nThe syndrome word : ");
     for(i=l; i<(l+r); i++)
           printf("%d ",c[i]);
     flag=0;
     for(i=l; i<(l+r); i++){
           if(c[i]!=0){
                flag=1;
                break;
           }
     }

     if(flag==1) printf("\nError");
     else printf("\nNo Error");

     return 0;
}
