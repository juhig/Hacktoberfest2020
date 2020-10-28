// Program to find number of words in a camel case string.
#include <iostream>

using namespace std;

int camelcase(string s) {
	int i=0, count=1;
	for(i=0;i<s.length();i++){
		if(s[i]<=90){
			count++;
		}
	}
	return count;
}

int main()
{

    string s;
    getline(cin, s);

    int result = camelcase(s);

    cout << result << "\n";

    return 0;
}
