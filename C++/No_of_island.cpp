/*You are given a 2-dimensional array/list having N rows and M columns,
which is filled with ones(1) and zeroes(0). 1 signifies land, and 0 
signifies water.
A cell is said to be connected to another cell, if one cell lies 
immediately next to the other cell, in any of the eight directions 
(two vertical, two horizontal, and four diagonals).
A group of connected cells having value 1 is called an island. 
Your task is to find the number of such islands present in the matrix.*/

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int N,int M,int i,int j)
{
	if(i < 0 || i >= N)
		return false;
	if(j < 0 || j >= M)
		return false;
	return true;
}

//this function does the DFS for every new one 1 found and assign every connected one to zero.
void help(int** arr,int n,int m,int i,int j)
{
	if(isSafe(n,n,i,j) && arr[i][j] == 1)
		{
			arr[i][j] = 0;
			help(arr, n, m , i-1, j-1);
			help(arr, n, m, i-1, j);
			help(arr, n, m, i-1, j+1);
			help(arr, n, m, i, j-1);
			help(arr, n, m, i, j+1);
			help(arr, n, m, i+1, j-1);
			help(arr, n, m, i+1, j);
			help(arr, n, m, i+1, j+1);
		}
}
int getTotalIslands(int** arr, int n, int m)
{
    int count = 0 ;
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				if(arr[i][j] == 1)
					{
						count++;
						help(arr,n,m,i,j);
					}
		}
	if(count == 0)
		return 0;
	return count;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int **arr = new int *[n];
    for(int i=0; i<n; i++) arr[i] = new int[m];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << getTotalIslands(arr, n, m) << endl;

    for(int i=0; i<n; i++) delete[] arr[i];
    delete[] arr;

    return 0;
}
