#include <stdio.h>

int binarySearch(int arr[], int n, int value){
    int l = 0, r = n - 1;
    while(l <= r){
        int m = (l + r) / 2;
        if(arr[m] < value){
            l = m + 1;
        }
        else if(arr[m] > value){
            r = m - 1;
        }
        else return m;
    }
    return -1;
}
int main(){
    int n; scanf("%d", &n);
    int arr[1000];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int value; scanf("%d", &value);
    if(binarySearch(arr, n, value) == -1){
        printf("Not found!\n");
    }
    else{
        printf("%d\n", binarySearch(arr, n, value));
    }
    return 0;
}