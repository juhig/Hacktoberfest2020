program to move all negative elements in an array to one side without using sorting algorithm.
order does notmatter here.

#include<bits/stdc++.h>
using namespace std;
int main() {

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int l = 0, r = n - 1;
  
  //can use any one of the approches below
  
	//two-pointer approach
	while (l <= r) {
		if (arr[l] < 0 && arr[r] < 0) {
			l++;
		} else if (arr[l] > 0 && arr[r] < 0) {
			int temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
			l++;
			r--;
		} else if (arr[l] > 0 && arr[r] > 0) {
			r--;
		} else {
			l++;
			r--;
		}
	}

	//quick-sort approach
	int j = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			if (i != j) {
				swap(arr[i], arr[j]);
			}
			j++;
		}
	}

	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
