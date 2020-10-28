#include<stdio.h>

void main()
{
	int yr ;
     int t;
     scanf("%d",&t);
     while(t>0){
        printf("Enter the year...");
        scanf("%d",&yr);
        if(yr%4==0)
            printf("It's a leap yr....");
        else
            printf("It's not a leap year...");
        t--;
     }
}
