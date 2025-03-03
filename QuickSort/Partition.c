#include <stdio.h>

void swaps(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int left, int right){
    int pivot_pos = right;
    int pivot = arr[right];
    right -= 1;
    while(1){
        while(arr[left] < pivot){
            left++;
        }
        while(arr[right] >= pivot){
            right--;
        }
        if(left >= right){
            break;
        }
        else{
            swaps(&arr[left], &arr[right]);
        }
    }
    swaps(&arr[left], &arr[pivot_pos]);
    return left;
}
int checkSameArray(int arr1[], int arr2[], int n1, int n2){
    if(n1 != n2){
        return 0;
    }
    for(int i = 0; i < n1; i++){
        if(arr1[i] != arr2[i]){
            return 0;
        }
    }
    return 1;
}
int main(){
    //a
    printf("a) ");
    int arr1[] = {1, 3, 7, 8 , 5};
    int n1 = sizeof(arr1) / sizeof(int);
    int left1 = partition(arr1, 0, n1 - 1);
    for(int i = 0; i < n1; i++){
        printf("%d ", arr1[i]);
    }
    printf("pivot: %d\n", left1);
    //b
    printf("b) ");
    int arr2[] = {0, 2, 3, 9, 5, 6, 8, 4};
    int n2 = sizeof(arr2) / sizeof(int);
    int left2 = partition(arr2, 0, n2 - 1);
    for(int i = 0; i < n2; i++){
        printf("%d ", arr2[i]);
    }
    printf("pivot: %d\n", left2);
    //c
    printf("c)\n");
    int arr3[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int n3 = sizeof(arr3) / sizeof(int);
    int arr4[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n4 = sizeof(arr4) /sizeof(int);
    int count = 0;
    while(checkSameArray(arr3, arr4, n3, n4) == 0){
        count++;
        printf("%d: ",count);
        int p = partition(arr3,0,n3-count);
        for(int j = 0; j < n3; j++){
            printf("%d ", arr3[j]);
        }
        printf("=> Pivot: %d\n",arr3[p]);
    }
    printf("%d", count);
    return 0;
}