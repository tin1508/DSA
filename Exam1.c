#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 1001

void initializeArray(int arr[], int n, int min, int max){
    for(int i = 0; i < n; i++){
        arr[i] = min + rand() % (max - min + 1);
    }
}
int sum(int arr[], int n, int *assign){
    int sum = 0;
    *assign = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            sum += arr[i];
            (*assign)++;
        }
    }
    return sum;
}
double Average(int n, int freq[], int k){
    int sum = 0;
    for(int i = 0; i <= n; i++){
        sum += freq[i] * i;
    }
    return (double) sum / k;
}
int main(){
    time_t t;
    srand((unsigned)time(&t));
    int n = 10, max = 100, min = -100;
    int arr[MAX];
    int k = 1000;
    int freqAssign[MAX] = {0};
    int assign;
    for(int i = 1; i <= k; i++){
        initializeArray(arr, n, min, max);
        sum(arr, n, &assign);
        freqAssign[assign]++;
    }
    printf("Assign \t FreqAssign\n");
    for(int i = 0; i <= k; i++){
        if(freqAssign[i] != 0){
            printf("%d \t %d\n", i, freqAssign[i]);
        }
    }
    double AverageAssign = Average(n, freqAssign, k);
    printf("Average of Assign is: %.3f\n", AverageAssign);
    return 0;
}