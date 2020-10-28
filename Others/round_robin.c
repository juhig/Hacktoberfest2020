
#include <stdio.h>
struct process{  
    /* data */
     int p,at,bt,wt,ct,tt,rt,f;
}p[20];

void main()
{
    
    int n,i,qt,time,count,w1,t1;
    float awt,atat;
    
    count=0;
    printf("Enter the number of processes present");
    scanf("%d",&n);
    printf("Enter the arrival time and then burst time of the processes \n");
    for (i=0;i<n;i++)
    {   
        printf("Arrival time \t");
        scanf("%d",&p[i].at);
        printf("Burst time \t");
        scanf("%d",&p[i].bt);
        p[i].rt=p[i].bt;
        p[i].p=i;
    }
    printf("Enter  the time quantum");
    scanf("%d",&qt);
    for (i=0;i<n;i++)
    {
        p[i].ct=0;
        p[i].tt=0;
        p[i].wt=0;
    }


    i=0;
    time=0;
    while(i<n)
    {  
        if (p[i].rt>qt)
        {
            time+=qt;
            p[i].rt-=qt;

        }
        else if (p[i].rt>0 && p[i].rt<=qt)
        {
            time+=p[i].rt;
            p[i].rt=0;
            p[i].f=1;
            p[i].ct=time;
        }
        else
        {
            
        }
        if(i+1==n)
        {
            i=0;
        }
        else
        {
            i+=1;
        }
        count=0;
        for(int j=0;j<n;j++)
        {
            if(p[j].rt==0)
            {  
                count+=1;
                
            }
        }
        if (count==n)
        {   
            
            break;
        }
        
      
    }
     
    t1=0;
    w1=0;
    for(i=0;i<n;i++)
    {
        p[i].tt=p[i].ct-p[i].at;
        t1+=p[i].tt;
        p[i].wt=p[i].tt-p[i].bt;
        w1+=p[i].wt;
    }
    atat=(float)t1/n;
    awt=(float)w1/n;
    printf("Results \n" );
    printf("Process\tBurst time\tCompletetion time\tTurn Around Time\t Waiting time \n" );
    for(i=0;i<n;i++)
    {
      printf("%d \t\t %d \t\t %d\t \t\t\t %d \t\t \t%d \n",i,p[i].bt,p[i].ct,p[i].tt,p[i].wt);

    }
    printf("\n");
    printf("Average turn around time : %f \n Average waiting time : %f",atat,awt);
    
}
