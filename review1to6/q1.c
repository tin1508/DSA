#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int n, int *comps, int *swaps){
    printf("Initial Array: [");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
    int sumComps = 0, sumSwaps = 0;
    for(int i = 0; i < n; i++){
        *comps = 0, *swaps = 0;
        for(int j = 0; j < n - i - 1; j++){
            (*comps)++;
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                (*swaps)++;
            }
        }
        sumComps += *comps;
        sumSwaps += *swaps;
        printf("Pass-through %d: [", i + 1);
        for(int k = 0; k < n; k++){
            printf("%d ", arr[k]);
        }
        printf("]\n Comparison: %d, Swaps: %d\n", *comps, *swaps);
    }
    int totalSteps = sumComps + sumSwaps;
    printf("Total comps: %d, Total swaps: %d\n", sumComps, sumSwaps);
    printf("Total steps: %d\n", totalSteps);
}
int main(){
    int arr[10] = {2, 9, 3, 1, 4, 5, 8, 7, 3, 0};
    int n = 10;
    int comps, swaps;
    bubbleSort(arr, n, &comps, &swaps);
    return 0;
}