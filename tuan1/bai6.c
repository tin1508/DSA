#include <stdio.h>
#define MAX 1000

float res[MAX], valueArr[MAX];
int IndexArr[MAX];

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sortArr(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] > arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }
}
void insertArr(float a[], int *n, int m, int indexArr[], float valueArr[]){
    *n += m;
    int j = 0, k = 0;
    for(int i = 0; i < *n; i++){
        if(a[j] == a[indexArr[k]]){
            res[i] = valueArr[indexArr[k]];
            k++;
        }
        else{
            res[i] = a[j];
            j++;
        }
    }
}
int main(){
    int n; scanf("%d", &n);
    float a[MAX];
    for(int i = 0; i < n; i++){
        scanf("%f", &a[i]);
    }
    int m; scanf("%d", &m);
    float number;
    int index;
    int size = 0; // kích thước của mảng index
    for(int i = 0; i < m; i++){
        scanf("%f %d", &number, &index);
        IndexArr[i] = index;
        size++;
        valueArr[index] = number;
    }
    sortArr(IndexArr, size);
    insertArr(a, &n, m, IndexArr, valueArr);
    for(int i = 0; i < n; i++){
        printf("%.2f ", res[i]);
    }
    return 0;
}