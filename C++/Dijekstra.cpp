#include <bits/stdc++.h> 
#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include <string>
int **a;           //global adjacency matrix
using namespace std;

//findig minimum distance for an unvisited vertex
int findmindist(int key[],int visited[],int n)  
{ 
	int min_index;
	int min_cost=INT_MAX;
	for(int x=0;x<n;x++)
    {
        //path must be with minimum distance and unvisited
		if(key[x]<min_cost&& !visited[x])  
        { 
			min_index=x;
			min_cost=key[x];
		}
	}
	return  min_index;          //vertex with minimum edge
}

// Function to print the required
void print(int dist[], int n, int s, string name[], string path[]) 
{ 
    cout<<"source \t Vertex  Distance from Source \t     Path \n"; 
    for (int i = 0; i < n; i++)
    {
        if(dist[i]==INT_MAX)
			cout<<name[s]<<"\t"<<name[i]<<"\t"<<"INFINITY"<<"\t\t"<<"path not defined\n";    //for no path, infinity distance
        else
            cout<<name[s]<<"\t"<<name[i]<<"\t"<<dist[i]<<"\t\t\t"<<path[i]<<"\n";
    }
}

void dijkstra(int src, int n, string name[])
{

    //string array to store the path
	string path[n];
	int dist[n];        //distance:- Finding minimum distance in every update
	int visited[n];     //checking whether a vertex is visited or not
	
    for(int i=0;i<n;i++)
    {
		dist[i]=INT_MAX;
		visited[i]=0;
		path[i]=(char)(src+48);     //initialising path as source
	}

	dist[src]=0;        //choosing source vertex
	
	int i=0;
	while(i<n-1)    // n vertex graph will have n-1 paths from any given node
    {   
		int cur = findmindist(dist,visited,n);    //vertex with minimum distance from source
		i++;
		visited[cur]=1;         //current vertex
		for(int j=0;j<n;j++)
		{
			if(a[cur][j]!=0 && visited[j]==0)       //vertex must not be visited and have weight>0
            {
				int c=a[cur][j];
				if(dist[j]>dist[cur]+c)         //updating all vertexes connected to the current vertex
                { 
					dist[j]=dist[cur]+c;
					path[j]=path[cur]+"->"+(char)(j+48);        //updating path 
				}
			}
		}
	}

    //Printing
	print(dist, n, src, name, path);

}

// Function to create and return edge number from edge name
int edge_no(string name[],int n, string a)
{
    int i;
    for(i=0;i<n;i++)
        if(name[i] == a)
            return i;
    return -1;
}

int main()
{
    int n;      //number of vertices
    cout<<"Copy and paste the code to run output for, \nexample given in the question.\n";
    cout<<"7 \nA B C D E F G \nB A 4 \ny \nA C 2 \ny \nF C 9 \ny \nD F 5 \ny \nF G 13 \ny \nD G 23 \ny \nD B 15 \ny \nE B 17 \ny \nE G 11 \nn \n";
    cout<<"Then Hit Enter in your terminal.\n";
    cout<<"Enter the number of vertices\n";
	cin>>n;
    string name[n];
    string m, p;
    char ch;
    int i;
    cout<<"Enter node names in numeric order.\n";
    for(i=0;i<n;i++)
        cin>>name[i];
    
	a=(int**)malloc(n*sizeof(int*));        //dynamically allocated matrix  
	for(i=0;i<n;i++){
		a[i]=(int*)malloc(n*sizeof(int));
	}
	int u,v,w;
	for(int x=0;x<n;x++)
    {                                       
		for(int y=0;y<n;y++) 
            a[x][y]=0;           //initiliazing all values as 0
	}
    cout<<"Enter in format: Edge_1\tEdge_2\tWeight\n";
    do
    {
        cout<<"Enter.\n";
        cin>>m>>p>>w;
        u = edge_no(name, n, m);
        v = edge_no(name, n, p);
        if( u == v )
            cout<<"No weight among same node.\n";
        else if(u != -1 && v != -1)
        {
            if(a[u][v] == 0)
                a[u][v] = w;
            else
                cout<<"Edge weight already entered.\n";
        }
        else
            cout<<"Wrong Edge name.\n";
        cout<<"Do you want to enter more details?(y/n).\n";
        cin>>ch;
    } while (ch == 'y' || ch == 'Y');
    for(i=0;i<n;i++)
        dijkstra(i, n, name);
    return 0;
}
