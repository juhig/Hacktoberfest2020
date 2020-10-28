#include <stdio.h>
#include <string.h>

int main() {
	char stringToReverse[100];

	printf("Enter a string to reverse\n");
	gets(stringToReverse);

	strrev(stringToReverse);
	

	printf("Reverse of the string: %s\n", stringToReverse);

	return 0;
}
