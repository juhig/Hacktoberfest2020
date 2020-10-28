#include<iostream>
using namespace std;

int max_size = 20;
int top =-1;
void Push(int A[],int x)
{
    if(top >= max_size-1)
    {
        cout<<"Error: Stack overflow\n";
        return;
    }
    A[++top] = x;
}

void Pop(int A[])
{
    if(top == -1)
    {
        cout<<"Error: No element to pop\n";
        return;
    }
    top--;
}

void Display(int A[])
{
    int i;
    cout<<"Stack: ";
    for(i=top;i>=0;i--)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int A[max_size];

    Push(A,3);
    Display(A);
    Push(A,5);
    Display(A);
    Push(A,12);
    Display(A);
    Pop(A);
    Display(A);
    Push(A,23);
    Display(A);
    Push(A,45);
    Display(A);
    Pop(A);
    Display(A);
    Push(A,9);
    Display(A);
}
