#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int partition(int a[],int l,int h)
{
	int pivot=a[l],down=l,up=h,temp;
	while(down<up)
	{
		while(pivot>=a[down])
		{
		down++;
		}
		while(pivot<a[up])
		{
		up--;
		}
		if(down<up)
		{
			temp=a[down];
			a[down]=a[up];
			a[up]=temp;
		}
	}
	a[l]=a[up];
	a[up]=pivot;
	return up;
}
void quicksort(int a[],int low,int high)
{
	if(low<high)
	{
	int p = partition(a,low,high);
	quicksort(a,low,p-1);
	quicksort(a,p+1,high);
	}
}
void display(int a[],int size)
{
	printf("The Sorted Elements are:\n");
	for(int i=0;i<size;i++)
	{
	printf("%d\n",a[i]);
	}
}
void binsearch(int a[],int ele,int n)
{
	int mid,first,last;
	first=0;
	last=n;
	while(mid!=0)
	{
		mid=(first+last)/2;
		if(ele==a[mid])
		{
			printf("Element is present at %d",mid);
			break;
		}
		if(mid==0)
		{
		printf("Element is not present");
		}
		else if(ele>a[mid])
		{
			first=mid;
			continue;
		}
		else if(ele<a[mid])
		{
			last=mid;
			continue;
		}
	}
}
int main()
{
	int i,n,a[10],num;
	printf("Enter the size of the array?");
	scanf("%d",&n);
	printf("Enter the elements...: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	display(a,n);
	printf("Enter the element to be searched:");
	scanf("%d",&num);
	binsearch(a,num,n);
	return 0;
}

