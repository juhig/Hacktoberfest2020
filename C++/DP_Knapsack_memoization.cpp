#include<bits/stdc++.h>
using namespace std;

//using recursion for Knapsack problem

int knapsack(int W, int wt[], int val[], int n)
{
	int t[n+1][W+1];
	memset(t,-1,sizeof(t));
	if(W==0 || n == 0)
	{
		return 0;
	}
	if(t[n][W]!=-1)
	{
		return t[n][W];
	}
	else
	{
	if(W<wt[n-1])
	{
		return t[n][W]=knapsack(W,wt,val,n-1);
	}
	else if (W>=wt[n-1])
	{
		return t[n][W] = max(val[n-1]+knapsack(W-wt[n-1],wt,val,n-1),knapsack(W,wt,val,n-1));
	}
	
}
}
int main()
{
	int val[] = { 20, 5, 10, 40, 15, 25 }; 
    int wt[] =  {  1, 2,  3,  8,  7, 4 }; 
    int W = 10; 
    //this input should give 60 as the answer
    int n = sizeof(val) / sizeof(val[0]); 
	cout<<knapsack(W,wt,val,n);	
}
