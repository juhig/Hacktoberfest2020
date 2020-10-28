#include<stdio.h>
void main ()
{
int i,j,x;
char ch=49;
printf("Enter value to be printed...");
scanf("%d",&x);
for(i=1;i<=x;i++)
    {
      for(j=1;j<=i;j++){
		    printf("%c",ch);ch++;
		  }
      printf("\n");
    }
}
