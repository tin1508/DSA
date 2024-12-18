#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 1000

//hàm sinh mảng ngẫu nhiên
void initializeArray(int arr[], int n, int max, int min){
    for(int i = 0; i < n; i++){
        arr[i] = min + rand()%(max - min + 1);
    }
}

//ham hoan vi 2 so nguyen a va b
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//bubble sort
void bubbleSort(int arr[], int n, int *comps, int *swaps){
    *comps = 0, *swaps = 0;
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
//selection sort
void selectionSort(int arr[], int n, int *comps, int *swaps){
    *comps = 0, *swaps = 0;
    for(int i = 0; i < n; i++){
        int minPos = i;
        for(int j = i + 1; j < n; j++){
            (*comps)++;
            if(arr[j] < arr[minPos]){
                minPos = j;
            }
        }
        if(i != minPos){
            swap(&arr[i], &arr[minPos]);
            (*swaps)++;
        }
    }
}
//insertion sort
void insertionSort(int arr[], int n, int *comps, int *shifts){
    *comps = 0, *shifts = 0;
    for(int i = 1; i < n; i++){
        int tempValue = arr[i], pos = i - 1;
        (*comps)++;
        while(pos >= 0 && arr[pos] > tempValue){
            arr[pos + 1] = arr[pos];
            (*shifts)++;
            if(pos != 0){
                (*comps)++;
            }
            --pos;
        }
        arr[pos + 1] = tempValue;
    }
}
int main(){
    time_t t;
    srand((unsigned)time(&t));
    int n[4] = {10, 20, 50, 100};
    int max = 100, min = -100;
    int arr1[MAX], arr2[MAX], arr3[MAX];
    int compsBubble, swapsBubble, compsSelect, swapsSelect, compsInsert, shiftInsert;
    for(int i = 0; i < 4; i++){
        int stepsBubble, stepsSelect, stepsInsert;
        initializeArray(arr1, n[i], max, min);
        printf("Unsorted array: \n");
        for(int j = 0; j < n[i]; j++){
            printf("%d ", arr1[j]);
            arr2[j] = arr1[j];
            arr3[j] = arr1[j];
        }
        bubbleSort(arr1, n[i], &compsBubble, &swapsBubble);
        selectionSort(arr2, n[i], &compsSelect, &swapsSelect);
        insertionSort(arr3, n[i], &compsInsert, &shiftInsert);
        stepsBubble = compsBubble + swapsBubble;
        stepsSelect = compsSelect + swapsSelect;
        stepsInsert = compsInsert + shiftInsert;
        printf("\nn \t bubbleSort's steps \t\t selectionSort's steps \t\t insertionSort's steps\n");
        printf("%d \t Comps: %d \t\t\t Comps: %d \t\t\t\t Comps: %d\n", n[i], compsBubble, compsSelect, compsInsert);
        printf("\t Swaps: %d \t\t\t Swaps: %d \t\t\t\t shifts: %d\n", swapsBubble, swapsSelect, shiftInsert);
        printf("\t Steps: %d \t\t\t Steps: %d \t\t\t\t Steps: %d\n", stepsBubble, stepsSelect, stepsInsert);
        printf("\n");
    }
    return 0;
}
/*
Giống nhau: BubbleSort và SelectionSort giống nhau về comps, cả 3 thuật toán đều giống nhau worstCase là O(n^2)
Khác nhau: Mỗi trường hợp thì cả 3 thuật toán đều cho số steps khác nhau.
*/