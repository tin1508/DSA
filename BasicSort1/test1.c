#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 1000

void initializeArray(int arr[], int n, int max, int min){
    for(int i = 0; i < n; i++){
        arr[i] = min + rand() % (max - min + 1);
    }
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void BubbleSort(int arr[], int n){
    int unsorted_until_index = n - 1;
    int sorted = 0;
    while(!sorted){
        sorted = 1;
        for(int i = 0; i < unsorted_until_index; i++){
            if(arr[i] > arr[i + 1]){
                sorted = 0;
                swap(&arr[i], &arr[i + 1]);
            }
        }
        unsorted_until_index -= 1;
    }
}
int main(){
    int n; scanf("%d", &n);
    int arr[MAX], arr1[MAX];
    //mảng nhập từ bàn phím
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    BubbleSort(arr, n);
    //xuất ra mảng nhập từ bàn phím đã được sắp xếp
    printf("mang nhap tu ban phim da duoc sap xep:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    time_t t;
    srand((unsigned)time(&t));
    int max = 100, min = 1;
    initializeArray(arr1, n, max, min);
    printf("\nmang ngau nhien:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr1[i]);
    }
    BubbleSort(arr1, n);
    //xuất ra mảng nhập từ bàn phím đã được sắp xếp
    printf("\nmang sinh ngau nhien da duoc sap xep:\n");
    //xuất ra mảng sinh ngẫu nhiên đã được sắp xếp
    for(int i = 0; i < n; i++){
        printf("%d ", arr1[i]);
    }
    return 0;
}