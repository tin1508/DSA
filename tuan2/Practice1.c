#include <stdio.h>

#define MAX 1000

void insertArray(int arr[], int *n, int value, int index)
{
    for(int i = *n; i > index; i--){
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    (*n)++;
}
void insertOrderedArray(int arr[], int *n, int value)
{
    if(arr[*n - 1] < value){
        arr[*n] = value;
        (*n)++;
    }
    else{
        for(int i = 0; i < *n; i++){
            if(arr[i] >= value){
                insertArray(arr, n, value, i);
                break;
            }
        }
    }
}
int main(){
    int n; scanf("%d", &n);
    int arr[MAX];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int value; scanf("%d", &value);
    insertOrderedArray(arr, &n, value);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}