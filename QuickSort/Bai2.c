#include <stdio.h>
void swaps(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int left, int right){
    int pivot_pos = right;
    right -= 1;
    while(1){
        while(arr[left] < arr[pivot_pos]){
            left++;
        }
        while(arr[right] >= arr[pivot_pos]){
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
//Base case: l >= r
//Result of base case: -4 -4 -2 1 2 3 5 6 9 10 11 
void quickSort(int a[], int left, int right){
    if(right - left <= 0) return;
    int p = partition(a, left, right);
    for(int i = left; i <= right; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    quickSort(a, left, p - 1);
    quickSort(a, p + 1, right);
}
int main(){

    return 0;
}