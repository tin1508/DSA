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
void bubbleSort(int arr[], int n, int *comps, int *swaps){
    *comps = 0;
    *swaps = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            (*comps)++;
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                (*swaps)++;
            }
        }
    }
}
float average(int freq[], int n, int k){
    int sum = 0;
    for(int i = 1; i <= n * (n - 1); i++){
        sum += freq[i] * i;
    }
    return (float) sum / k;
}
int main(){
    time_t t;
    srand((unsigned)time(&t));
    const int n = 10;
    int arr[n], max = 100, min = 1, comps, swaps;
    int k[6] = {10, 25, 50, 100, 1000, 10000};
    for(int i = 0; i < 6; i++){
        int freq_comps[91] = {0}, freq_swaps[91] = {0};
        for(int j = 0; j < k[i]; j++){
            initializeArray(arr, n, max, min);
            bubbleSort(arr, n, &comps, &swaps);
            freq_comps[comps]++;
            freq_swaps[swaps]++;
        }
        printf("with k = %d\n", k[i]);
        for(int m = 1; m <= n*(n - 1); m++){
            printf("%d:%d:%d ", m, freq_comps[m], freq_swaps[m]);
        }
        printf("\naverage of comps: %.2f\n", average(freq_comps, n, k[i]));
        printf("average of swaps: %.2f\n", average(freq_swaps, n, k[i]));
        printf("\n");
    }
    return 0;
}