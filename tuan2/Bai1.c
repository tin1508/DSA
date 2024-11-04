#include <stdio.h>

// bài tập trên lớp 1, 2, 3 với kiểu dữ liệu số thực
// bài 1

/*
void insertion(float arr[], int *n, int index, float value){
    if(index == *n - 1){
        arr[*n] = arr[*n - 1];
        arr[index] = value;
    }
    else{
        for(int i = *n; i > index; i--){
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
    }
    (*n)++;
}
void insertOrderedArray(float arr[], int *n, float value){
    for(int i = 0; i < *n; i++){
        if(arr[i] >= value){
            insertion(arr, n, i, value);
            break;
        }
    }
}
int main(){
    int n; scanf("%d", &n);
    float arr[100];
    for(int i = 0; i < n; i++){
        scanf("%f", &arr[i]);
    }
    float value; scanf("%f", &value);
    insertOrderedArray(arr, &n, value);
    for(int i = 0; i < n; i++){
        printf("%.2f ", arr[i]);
    }
    return 0;
}
*/

// bài 2
/*
int orderedLinearSearch(float arr[], int n, float value){
    for(int i = 0; i < n; i++){
        if(arr[i] == value){
            return i;
        }
        else if(arr[i] > value){
            return -1;
        }
    }
    return -1;
}
int main(){
    int n; scanf("%d", &n);
    float arr[100];
    for(int i = 0; i < n; i++){
        scanf("%f", &arr[i]);
    }
    float value; scanf("%f", &value);
    int index = orderedLinearSearch(arr, n, value);
    if(index == -1){
        printf("Not found!\n");
    }
    else printf("%d\n", index);
    return 0;
}
*/

// bài 3


int binarySearch(float arr[], int n, float value){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(arr[mid] < value){
            l = mid + 1;
        }
        else if(arr[mid] > value){
            r = mid - 1;
        }
        else 
            return mid;
    }
    return -1;
}
int main(){
int n; scanf("%d", &n);
    float arr[100];
    for(int i = 0; i < n; i++){
        scanf("%f", &arr[i]);
    }
    float value; scanf("%f", &value);
    int index = binarySearch(arr, n, value);
    if(index == -1){
        printf("Not found!\n");
    }
    else printf("%d\n", index);
    return 0;
}
