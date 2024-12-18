#include <stdio.h>

int orderedLinearSearch(int arr[], int n, int value){
    if(arr[n - 1] < value){
        return -1;
    }
    for(int i = 0; i < n; i++){
        if(value == arr[i]){
            return i;
        }
        else if(arr[i] > value){
            return -1;
        }
    }
}
int main(){
    int n; scanf("%d", &n);
    int arr[1000];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int value; scanf("%d", &value);
    if(orderedLinearSearch(arr, n, value) == -1){
        printf("Not found!\n");
    }
    else{
        printf("%d\n", orderedLinearSearch(arr, n, value));
    }
    return 0;
}