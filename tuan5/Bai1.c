#include <stdio.h>

#define MAX 1000
//ham hoan vi 2 so nguyen a va b
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
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
void insertionSort(int arr[], int n, int *comps, int *shifts){
    *comps = 0, *shifts = 0;
    for(int i = 1; i < n; i++){
        int tempValue = arr[i], pos = i - 1;
        int compsTemp = 1;
        while(pos >= 0 && arr[pos] > tempValue){
            arr[pos + 1] = arr[pos];
            (*shifts)++;
            --pos;
            if(pos == 0 && arr[pos] > tempValue){
                arr[pos + 1] = arr[pos];
                (*shifts)++;
                compsTemp++;
                break;
            }
            compsTemp++;
        }
        arr[pos + 1] = tempValue;
        *comps += compsTemp;
    }
}
int main(){
    int arr[] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0};
    int arr1[MAX], arr2[MAX];
    int n = sizeof(arr) / sizeof(int);
    for(int i = 0; i < n; i++){
        arr1[i] = arr[i];
        arr2[i] = arr[i];
    }
    int compsSelect, compsInsert, compsBubble, swapsBubble, shifts;
    int swapsSelect;
    bubbleSort(arr, n, &compsBubble, &swapsBubble);
    selectionSort(arr1, n, &compsSelect, &swapsSelect);
    printf("swaps select: %d\n", swapsSelect);
    insertionSort(arr2, n, &compsInsert, &shifts);
    int sumStepsOfBubble = compsBubble + swapsBubble;
    int sumStepsOfSelect = compsSelect + swapsSelect;
    int sumStepsOfInsert = compsInsert + shifts;
    printf("steps of bubbleSort is: %d\n", sumStepsOfBubble);
    printf("steps of selectionSort is: %d\n", sumStepsOfSelect);
    printf("steps of insertionSort is: %d\n", sumStepsOfInsert);
    return 0;
}