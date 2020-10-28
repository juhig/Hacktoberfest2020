#include<iostream>
using namespace std;

void comp(int, int, int u[], int a[]);

int main()
{
    int u[10], a[10], m,n;
    cout<<"Enter the number of elements in U: ";
    cin>>m;
    cout<<"Enter the elements of U: ";
    for(int i = 0; i < m; i++)
    {
        cin>>u[i];
    }
    cout<<endl;
    cout<<"Enter the no. of elements in A: ";
    cin>>n;
    cout<<"Enter the elements of A: ";
    for(int j = 0; j < n; j++)
    {
        cin>>a[j];
    }
    cout<<endl;
    cout<<"The elements of complementary set: ";
    comp(m,n,u,a);
    return 0;
}

void comp(int m, int n, int u[20], int a[10])
{
    int flag = 0;

    for(int i = 0; i < m; i++)
    {
        flag = 0;
        for(int j = 0; j < n; j++)
        {
            if(u[i] == a[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            cout<<u[i]<<" ";
        }
    }
}
