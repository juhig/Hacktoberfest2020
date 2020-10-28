#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void insertionSort(int a[],int SIZE)
{
	int i,j,t;
	for(i=1;i<SIZE;i++)
	{
		t=a[i];
		for(j=i-1;j>=0 && t<a[j];j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=t;
	}
	for(i=0;i<SIZE;i++)
	{
	printf("%d\n",a[i]);
	}
}
void shellSort(int a[],int SIZE,int incr[],int n)
{
	int i,g,j,t,k;
	for(i=0;i<n;i++)
	{
		g = incr[i];
		for(j=g;j<SIZE;j++)
		{
			t=a[j];
			for(k=j-g;k>=0 && t<a[k];k-=g)
			{
				a[k+g]=a[k];
			}
			a[k+g] = t;
		}
	}
	for(i=0;i<SIZE;i++)
	{
	printf("%d\n",a[i]);
	}
}
void selectionSort(int a[],int SIZE)
{
	int i,j,t;
	for(i=0;i<=SIZE-1;i++)
	{
		for(j=i+1;j<SIZE;j++)
		{
			if(a[i]>a[j])
			{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
			}
		}
	}
	for(i=0;i<SIZE;i++)
	{
	printf("%d\n",a[i]);
	}	
}
void bubbleSort(int a[],int SIZE)
{
	int i,j,t;
	for(i=0;i<SIZE-1;i++)
	{
		for(j=0;j<SIZE-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
			}
		}
	}
	for(i=0;i<SIZE;i++)
	{
	printf("%d\n",a[i]);
	}
}
int main()
{
	int i,a[100],n,ch,incr[10];
	printf("Enter the size of the array?");
	scanf("%d",&n);
	printf("Enter the elements...: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
while(ch!=0)
	{
		printf("Enter 1 for Bubble Sort, 2 for Selection Sort, 3 for Insertion sort,4 for Shell Sort and 0 for exit: ");
		scanf("%d",&ch);
	if(ch==1)
	{
		printf("The Sorted Elements using Bubble Sort are: \n");
		selectionSort(a,n);
	}
	else if(ch==2)
	{
		printf("The Sorted Elements using Selection Sort are: \n");
		bubbleSort(a,n);
	}
	else if(ch==3)
	{
		printf("The Sorted Elements using Insertion Sort are: \n");
		insertionSort(a,n);
	}
	else if(ch==4)
	{
		printf("The Sorted Elements using Shell Sort are:\n");
		for(i=1;i<10;i++)
		{
			incr[i]=i;
		}
		shellSort(a,n,incr,10);
	}
	else
	{
		break;
	}
}
	return 0;
}
