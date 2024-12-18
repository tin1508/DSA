#include <stdio.h>

#define MAX 100

void insertArray(int arr[], int *n, int value, int index)
{
    for(int i = *n; i > index; i--){
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    (*n)++;
}

int main() {
    int n; scanf("%d", &n);
    int arr[MAX];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int value; scanf("%d", &value);
    int index; scanf("%d", &index);
    insertArray(arr, &n, value, index);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}
