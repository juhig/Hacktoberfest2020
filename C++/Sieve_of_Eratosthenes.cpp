#include<bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int n)
{
    int p=2;
    bool prime[n+1];
    memset(prime,true,sizeof(prime));

    for(p=2;p*p<=n;p++)
    {
        if(prime[p] == true)
        {
            for(int i = p*p ; i<=n;i+=p)
            {
                if(prime[i]==true)
                {
                    prime[i]=false;
                }
            }
        }

    }
    cout<<"Prime nos"<<"\n";
    for(int p=2;p<=n;p++)
    {
        if(prime[p] == true)
        {
            cout<<p<<" " ;
        }

    }

}

int main()
{
    int n;
	cin>>n;
    sieveOfEratosthenes(n);
    return 0;
}
