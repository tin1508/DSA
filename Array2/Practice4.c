#include <stdio.h>

int orderedLinearSearch(int arr[], int n, int value, int *compsLinear){
    *compsLinear = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] < value){
            (*compsLinear)++;
            continue;
        }
        else{
            if(arr[i] == value){
                (*compsLinear)++;
                return i;
            }
            else return -1;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int value, int *compsBinary){
    int l = 0, r = n - 1;
    *compsBinary = 0;
    while(l <= r){
        int m = (l + r) / 2;
        (*compsBinary)++;
        if(arr[m] < value){
            l = m + 1;
        }
        else if(arr[m] > value){
            r = m - 1;
        }
        else{
            return m;
        }
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
    int compsLinear, compsBinary;
    int res = orderedLinearSearch(arr, n, value, &compsLinear);
    binarySearch(arr, n, value, &compsBinary);
    printf("stepLinear = %d\n", compsLinear);
    printf("stepBinary = %d", compsBinary);
    return 0;
}