#include <bits/stdc++.h> 

using namespace std;

int main() {
    int no,n;
    int arr[n];

	cin>>no;
	for(int k=0;k<no;k++){
	cin>>n;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }


        sort(arr, arr+n); 
        int max=n-1;
        int min=0;
        int max_ele=arr[n-1]+1;
        for(int i=0;i<n;i++){
            if(i%2==0){
                arr[i]+=(arr[max]%max_ele)*max_ele;
                 max--;
             }
            else{
                arr[i]+=(arr[min]%max_ele)*max_ele;
                 min++;
            }

        }
        for(int i=0;i<n;i++){
            arr[i]=arr[i]/max_ele;
        }
        for(int i=0;i<n;i++){
             cout<<arr[i]<<" ";
        	}
          cout<<endl;
    }


}
 
