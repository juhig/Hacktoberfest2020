#include<bits/stdc++.h>
#define lli long long int
#define floop(a,b,c) for(lli a = b; a < c; a++)
using namespace std;
int main(){
  lli input[3];
  floop(i,0,3) cin >> input[i];
  sort(input,input+3);
  if((input[0]*input[0]) + (input[1]*input[1]) == (input[2]*input[2])) cout << "YES";
  else cout << "NO";
  return 0;
}
