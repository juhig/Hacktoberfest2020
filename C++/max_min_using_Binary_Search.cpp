#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll findMin(ll a[],ll low,ll high){
    if(low==high){
        return a[low];
    }
    ll mid=(low+high)/2;
    ll x=findMin(a,low,mid);
    ll y=findMin(a,mid+1,high);
    return min(x,y);
}
ll findMax(ll a[],ll low,ll high){
    if(low==high){
        return a[low];
    }
    ll mid=(low+high)/2;
    ll x=findMax(a,low,mid);
    ll y=findMax(a,mid+1,high);
    return max(x,y);
}
void solver(){
    cout<<"Enter the size of the array : ";
    ll n;
    cin>>n;
    cout<<"Enter the elements of array : ";
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    
    ll m=findMax(a,0,n-1);
    ll M=findMax(a,0,n-1);
    cout<<"Maximum element in the array is : "<<m<<"\n";
    cout<<"Maximum element in the array is : "<<M<<"\n";
}
int main(){
    solver();
    return 0;
}
