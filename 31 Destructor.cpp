#include<iostream>
using namespace std;
int count =0;
class alpha
{
public:

alpha()
{
  count++;

  cout<<"\n No of object created"<<count;
}

~alpha()
{
 cout<<"\n No of object Destroyed"<<count;
  count--;
}

};





int main()

{

 	cout<< "\n Enter in main Function \n";

 	alpha A1,A2,A3,A4;
	 {
            cout<<"\N Enter in Block1 \n";
		
		alpha A5;
	 }

	 {

	  cout<<"\n Enter Block2 \n";
		
	        alpha A6;
	 }

    cout<<"\n Re-Enter in Main block \n";
    
}

