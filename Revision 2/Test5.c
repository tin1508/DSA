#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeArray(int arr[], int n, int min, int  max){
    for(int i = 0; i < n; i++){
        arr[i] = min + rand()%(max - min + 1);
    }
}
void f(int a[], int n, int *comps, int *assigns){
    int t;
    *comps = 0, *assigns = 0;
    for(int i = 0; i < n - 1; i++){
        if(a[i] % 2 != 0){
            (*comps)++;
            for(int j = i + 1; j < n; j++){
                (*comps) += 2;
                if(a[j] % 2 != 0 && a[i] > a[j]){
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                    (*assigns) += 3;
                }
            }
        }
    }
}

void main(){
    time_t t;
    srand((unsigned)time(&t));
    int a[10];
    int n = 10;
    int min = 1, max = 10;
    int k = 10000, comps, assigns;
    double average = 0;
    for(int i = 0; i < k; i++){
        initializeArray(a, n, min, max);
        f(a, n, &comps, &assigns);
        int sumSteps = comps + assigns;
        average += (double) sumSteps;
    }
    average /= k;
    printf("average: %lf", average);
}