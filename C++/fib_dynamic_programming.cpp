#include <iostream>

using namespace std;

int fib(int n){
    if (n==0)
        return 0;
    else if (n==1)
        return 1;
    else
        return fib(n-1)+fib(n-2);
            
}

int fib_memo(int n,int memo[]){
    int result;
    if(memo[n]!=0)
        return memo[n];
    else if(n==1 || n==0)
        result=n;
    else
        result=fib(n-1)+fib(n-2);

    memo[n]=result;
    return result;      
}

int fib_bottom_up(int n){
    int r[10];

    r[0]=0;
    r[1]=1;

    for(int i=2;i<n+1;i++){
        r[i]=r[i-1]+r[i-2];
    }

    return r[n];
}

int main(){
    

    int memo[20];

    for(int i=0;i<20;i++){
        memo[i]=0;
    }

    cout <<"fib of 6 is "<<fib_bottom_up(6);
    cout<<"\n fib of 6 is"<<fib(6);
    cout<<"\n fib of 6 is"<<fib_memo(6,memo);
    return 0;
}