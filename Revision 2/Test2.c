#include <stdio.h>
#include <math.h>

//ham tinh khoang cach tu diem den tam 0
double instance(int arr[2]){
    return sqrt((arr[0])*(arr[0]) + (arr[1]) * arr[1]);
}
//ham doi 2 so
void swapTwoNumber(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//ham doi vi tri 2 cap toa do trong mang
void swapsSubArray(int *a, int *b){
    swapTwoNumber(a, b);
    swapTwoNumber(a + 1, b + 1);
}
void sort(int arr[][2], int n){
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(instance(arr[j]) < instance(arr[minIndex])){
                minIndex = j;
            }
        }
        if(minIndex != i){
            swapsSubArray(arr[minIndex], arr[i]);
        }
    }
}
int main(){
    int arr[][2] = {{9, 1}, {-8, 12}, {4, 7}, {3, 2}};
    int n = 4;
    sort(arr, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}