#include <stdio.h>

#define MAX 1000
int searchArray(int arr[], int n, int value) {
    int index = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == value){
            index = i;
            return index;
        }
    }
    return index;
}

int main() {
    int n; scanf("%d", &n);
    int arr[MAX];
    int value;

    //Input arr and value
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &value);

    int index = searchArray(arr, n, value);
    if (index == -1)
        printf("Not found!");
    else
        printf("Found %d at %d", value, index);
}
