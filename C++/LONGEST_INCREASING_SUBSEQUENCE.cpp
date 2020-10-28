#include<iostream>
#include<climits>
using namespace std;
int lis(int A[],int n){
int output[n];
for(int i=0;i<n;i++){
	output[i]=1;
	for(int j=i-1;j>=0;j--){
		if(A[j]>=A[i]){
		    continue;
		}
		int temp=output[j]+1;
		if(temp>output[i]){
			output[i]=temp;
		}
	}
  }
int Result=INT_MIN;
for(int i=0;i<n;i++){
 if(output[i]>Result){
	Result=output[i];
	}
  }
return Result;
}
int main(){
int n;
cin>>n;
int A[n];
for(int i=0;i<n;i++){
 cin>>A[i];
 }
int result=lis(A,n);
cout<<result;
}