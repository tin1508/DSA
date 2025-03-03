#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//selection sort

#define MAX 1000

// void initializeArray(int arr[], int n, int min, int max){
//     for(int i = 0; i < n; i++){
//         arr[i] = min + rand() % (max - min + 1);
//     }
// }
// void swap(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// void selectionSort(int arr[], int n, int *comps, int *swaps){
//     *comps = 0; *swaps = 0;
//     for(int i = 0; i < n; i++){
//         int min_pos = i; 
//         for(int j = i + 1; j < n; j++){
//             (*comps)++;
//             if(arr[j] < arr[min_pos]){
//                 min_pos = j;
//             }
//         }
//         if(i != min_pos){
//             swap(&arr[i], &arr[min_pos]);
//             (*swaps)++;
//         }
//     }
// }
// int main(){
//     int n = 10;
//     int arr[MAX];
//     time_t t;
//     srand((unsigned)time(&t));
//     int min = 1, max = 100;
//     int k[6] = {20, 30, 50, 100, 1000, 10000};
//     int comps, swaps, steps;
//     for(int i = 0; i < 6; i++){
//         int freq_swaps[10] = {0};
//         steps = 0;
//         int sumSwaps = 0, sumComps = 0;
//         for(int j = 0; j < k[i]; j++){
//             initializeArray(arr, n, min, max);
//             selectionSort(arr, n, &comps, &swaps);
//             sumComps += comps; sumSwaps += swaps;
//             steps += comps + swaps;
//             freq_swaps[swaps]++;
//         }
//         //tính số comps trung bình
//         float avg1 = (float) sumComps / k[i];
//         //tính số swaps trung bình
//         float avg2 = (float) sumSwaps / k[i];
//         //tính số step trung bình
//         float avgSteps = (float) steps / k[i];
//         printf("\nwith k = %d\n", k[i]);
//         printf("FreqSwaps: ");
//         for(int l = 0; l < 10; l++){
//             printf("%d:%d ", l, freq_swaps[l]);
//         }
//         printf("\naverage of comps is: %.2f\n", avg1);
//         printf("average of swaps is: %.2f\n", avg2);
//         printf("average of steps is: %.2f", avgSteps);
//     }
//     return 0;
// }
// void initializeArray(int arr[], int n, int min, int max){
//     for(int i = 0; i < n; i++){
//         arr[i] = min + rand() % (max - min + 1);
//     }
// }
void insertionSort(int arr[], int n, int *comps, int *shift){
    printf("Mang ban dau: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    int *sumComps = 0, *sumShift = 0;
    for(int i = 1; i < n; i++){
        int pos = i - 1, temp_value = arr[i];
        *comps = 2, *shift = 0;
        while(pos >= 0 && arr[pos] > temp_value){
            (*shift)++;
            arr[pos + 1] = arr[pos];
            --pos;
            (*comps) += 2;
        }
        arr[pos + 1] = temp_value; 
        printf("\nBuoc %d: ", i);
        for(int j = 0; j < n; j++){
            printf("%d ", arr[j]);
        }
        printf("\ncomps: %d, shift: %d", *comps, *shift);
        sumComps += *comps;
        sumShift += *shift;
    }
    printf("\nMang sau khi sap xep: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\ntotal comps: %d, total shift: %d", sumComps, sumShift);
}

int main(){
    int n = 5;
    int arr[10] = {12, 11, 13, 5, 6};
    int comps, shift;
    insertionSort(arr, n, &comps, &shift);
    return 0;
}
