// Program to reverse digits of a number
 
#include<iostream>
using namespace std;
int main()
{
	int rem , n , reversed_number = 0;
	cin>>n;
	while(n > 0)
	{
		rem = n % 10;                                   // Extracting the last digit of the number 
		n = n / 10;                                     // Removing the last digit of the number
		reversed_number = reversed_number*10 + rem;     // Reversing digits of the number
	}
	
	cout<<"The number after reversing it's digits is: "<<reversed_number;
	
return 0;
}
