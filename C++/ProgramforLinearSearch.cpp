#include <stdio.h>

int linearSearch(int* arr, int length, int value){
    for(int i=0; i<length; i++){
        if(arr[i]==value)
            return i;
    }
    return -1;
}

int main()
{
    int length;
    scanf("%d", &length);
    int arr[length];
    for(int j=0; j<length; j++)
        scanf("%d", &arr[j]);
    int reqdNum=0;
    scanf("%d", &reqdNum);
    printf("%d", linearSearch(arr, length, reqdNum));

    return 0;
}
