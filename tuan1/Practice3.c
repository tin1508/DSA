
#include<stdio.h>

#define MAX 1000

void deleteArray(int arr[], int* n, int index){
    for(int i = index; i < *n - 1; i++){
        arr[i] = arr[i + 1];
    }
    (*n)--;
}
int main(){
    int n; scanf("%d", &n);
    int arr[MAX];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int index; scanf("%d", &index);
    deleteArray(arr, &n, index);
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}
