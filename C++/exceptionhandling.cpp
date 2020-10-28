#include<iostream>
using namespace std;
int main()
{	int a,b;
	cout<<"Enter the values of a and b: \n";
	cin>>a>>b;
	try
	{	if(b!=0)
		{	cout<<"result(a/b):"<<a/b<<"\n";
		}
		else
		{	throw(b);
		}
	}
	catch(int i)
	{	cout<<"Exception caught:DIVIDED BY ZERO \n";
	}
	return 0;
}


