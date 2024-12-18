#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeArray(int arr[], int n, int max, int min){
    for(int i = 0; i < n; i++){
        arr[i] = min + rand() % (max - min + 1);
    }
}

void insert(int arr[], int *n, int value, int index, int *assignment){
    if(index < 0 || index > *n){
        return ;
    }
    (*n)++;
    *assignment = 0;
    for(int i = *n - 1; i > index; i--){
        arr[i] = arr[i - 1];
        (*assignment)++;
    }
    arr[index] = value;
    (*assignment)++;
}

float average(int freq[], int n, int k){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += freq[i] * i;
    }
    return (float) sum / k;
}

int main(){
    time_t t;
    srand((unsigned)time(&t));
    const int n = 20;
    int arr[n];
    int max = 100, min = -100;
    printf("\n");
    int k[5] = {10, 20, 100, 1000, 10000};
    int assignment, value;
    for(int i = 0; i < 5; i++){
        int freq[21] = {0}; // bảng tần số
        for(int j = 0; j < k[i]; j++){
            int temp_size = n;
            initializeArray(arr, temp_size, max, min);
            value = arr[rand() % temp_size];
            int index = rand() % temp_size;
            insert(arr, &temp_size, value, index, &assignment);
            freq[assignment]++;
        }
        printf("with k = %d\n", k[i]);
        for(int m = 1; m <= n; m++){
            printf("%d:%d ", m, freq[m]);
        }
        printf("\naverage is: %.2f\n", average(freq, n, k[i]));
    }
    return 0;
}