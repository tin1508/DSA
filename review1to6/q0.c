#include <stdio.h>

/*
Đếm số bước so sánh của binarySearch Algorithm
và cho biết trạng thái của mảng từng vòng
*/
void binarySearch(int arr[], int n, int k, int *comps){
    int left = 0, right = n - 1;
    int sumComps = 0;
    int count = 0;
    printf("Initial array: \n");
    printf("Left: %d - right: %d\n", left, right);
    for(int i = left; i <= right; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    while(left < right){
        *comps = 0;
        int middle = (left + right) / 2;
        if(arr[middle] == k){
            (*comps)++;
            break;
        }
        else if(arr[middle] > k){
            (*comps)++;
            right = middle - 1;
        }
        else{
            (*comps)++;
            left = middle + 1;
        }
        sumComps += *comps;
        printf("Pass-through %d:\n", count + 1);
        printf("Left: %d - right: %d\n", left, right);
        for(int i = left; i <= right; i++){
            printf("%d ", arr[i]);
        }
        count++;
        printf("\nComparison: %d\n", *comps);
    }
    printf("Total's comps: %d", sumComps);
    return;
}
int main(){
    int arr[] = {1, 2, 7, 19, 23, 24, 28, 37, 49, 55, 122, 124};
    int k = 2;
    int n = sizeof(arr) / sizeof(int);
    int comps;
    binarySearch(arr, n, k, &comps);
    return 0;
}