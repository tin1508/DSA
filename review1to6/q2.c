#include <stdio.h>

void insertionSort(int arr[], int n, int *comps, int *shifts){
   printf("Initial array:[");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
    int sumComps = 0, sumShift = 0;
    for(int i = 1; i < n; i++){
        int pos = i - 1, temp_value = arr[i];
        *comps = 1, *shifts = 0;
        while(pos >= 0 && arr[pos] > temp_value){
            (*shifts)++;
            arr[pos + 1] = arr[pos];
            --pos;
            if(pos == 0 && arr[pos] > temp_value){
                arr[pos + 1] = arr[pos];
                (*shifts)++;
                --pos;
            }
            (*comps)++;
        }
        arr[pos + 1] = temp_value; 
        sumComps += *comps;
        sumShift += *shifts;
        printf("Pass-through %d: [", i);
        for(int k = 0; k < n; k++){
            printf("%d ", arr[k]);
        }
        printf("]\nComparison: %d, Shift: %d\n", *comps, *shifts);
    }
    int totalSteps = sumComps + sumShift;
    printf("\nTotal comps: %d, Total shift: %d", sumComps, sumShift);
    printf("\nTotal Steps: %d", totalSteps);
}

int main(){
    int arr[10] = {2, 9, 3, 1, 4, 5, 8, 7, 3, 0};
    int n = 10;
    int comps, shifts;
    insertionSort(arr, n, &comps, &shifts);
    return 0;
}