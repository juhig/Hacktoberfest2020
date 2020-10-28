/**
 * Lang: C++14
 */

#include <bits/stdc++.h>
using namespace std;

class dsu{
    vector<int>p;
public:
    dsu(int n){
        p.resize(n);
        iota(p.begin(),p.end(),0);
    }
    int find(int u){
        if(u==p[u])return u;
        return p[u]=find(p[u]);
    }
    void join(int a, int b){
        a = find(a);
        b = find(b);
        if(a!=b)p[b]=a;
    }
};

int main(){
    dsu d(10);
    d.join(1, 2);
    cout<<"Parent of 1:"<<d.find(1)<<", Parent of 2:"<<d.find(2)<<endl;
}
