#include<bits/stdc++.h>
#define lli long long int
#define floop(a,b,c) for(lli a = b; a < c; a++)
using namespace std;
int main(){
  lli n;
  cin >> n;
  lli input[n];
  floop(i,0,n) cin >> input[i];
  lli maxm = 0;
  floop(i,0,n) maxm = max(maxm,input[i]);
  lli arr[maxm+1] = {0};
  floop(i,0,n) arr[input[i]]++;
  floop(i,0,n){
    if(arr[i] > 0 && arr[i] < 3){
      cout << i << endl;
      break;
    }
  }
  return 0;
}
