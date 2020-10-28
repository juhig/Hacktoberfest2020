#include<stdio.h>
#include<math.h>
void bubblesort(int a[], int n)
{
    int i, j, tmp;
    for(i=0;i<n-1;i++)
    {
        tmp=0;
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
            tmp=1;
        }
    }
}
void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main()
{
    int a[30];
    int k,n;
    printf("Enter total no of elements to be inserted:");
    scanf("%d",&n);
    printf("Enter elements:");
    for(k=0;k<n;k++)
    {
        scanf("%d",&a[k]);
    }
    bubblesort(a,n);
    printArray(a,n);
    return 0;
}
