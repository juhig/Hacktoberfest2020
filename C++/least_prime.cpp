#include<bits/stdc++.h> 
using namespace std; 
  
void leastPrimeFactor(int n) 
{ 
    vector<int> least_prime(n+1, 0); 
  
    least_prime[1] = 1; 
  
    for (int i = 2; i <= n; i++) 
    { 
        if (least_prime[i] == 0) 
        { 
            least_prime[i] = i; 
            for (int j = i*i; j <= n; j += i) 
                if (least_prime[j] == 0) 
                   least_prime[j] = i; 
        } 
    } 
  
  cout<<least_prime[n]<<"\n"; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int n = 10; 
    leastPrimeFactor(n); 
    return 0; 
}
