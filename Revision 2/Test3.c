#include <stdio.h>

void swaps(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int minPos = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minPos]){
                minPos = j;
            }
        }
        if(minPos != i){
            swaps(&arr[i], &arr[minPos]);
        }
    }
}
/*
Base Case: 
+Neu tim thay: l <= r voi dieu kien arr[m] == value hoac l > r
Result of Base Case: 
+Neu tim thay: binarySearchRecur(arr, l, r, value) = m (voi m = (l + r) / 2) 
+Neu ko tim thay: binarySearchRecur(arr, l, r, value) = -1
*/
//Lay vi du mang
// Mang da sap xep: [-5 -3 -2 1 1 2 3 4 7 8]
//value = 2
//Before Base Case: binarySearchRecur(arr, 5, 9, 2) = [2, 3, 4, 7, 8]
//Before before: binarySearchRecur(arr, 0, 9, 2) = [-5 -3 -2 1 1 2 3 4 7 8] 
int binarySearchRecur(int arr[], int l, int r, int value){
    if(l <= r){
        int m = (l + r) / 2;
        if(arr[m] == value){
            return m;
        }
        else if(arr[m] < value){
            return binarySearchRecur(arr, m + 1, r, value);
        }
        else{
            return binarySearchRecur(arr, l, m - 1, value);
        }
    }
    else{
        return -1;
    }
}

int main(){
    int arr[] = {-2, 7, -5, 3, 1, 4, 8, 2, -3, 1};
    //mang sau khi sap xep
    //[-5 -3 -2 1 1 2 3 4 7 8]
    int size = sizeof(arr) / sizeof(int);
    selectionSort(arr, size);
    int value; scanf("%d", &value);
    int index = binarySearchRecur(arr, 0, size - 1, value);
    if( index == -1){
        printf("Not found!\n");
    }
    else{
        printf("index = %d\n", index);
    }
    return 0;
}