#include <stdio.h>

#define MAX 1000
//hàm hoán vị 2 số nguyên
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//cách 1
//hàm xóa phần tử trong mảng bằng chỉ số index
void deleteElements(int arr[], int *n, int index, int *assign){
    *assign = 0;
    for(int i = index; i < (*n) - 1; i++){
        arr[i] = arr[i + 1];
        (*assign)++;
    }
    (*n)--;
}
//hàm xóa phần tử trùng nhau bằng phương án 1
void deleteDuplicateElements1(int arr[], int *n, int *steps){
    int comps, assign;
    *steps = 0;
    for(int i = 0; i < *n - 1; i++){
        comps = 0;
        for(int j = i + 1; j < *n; j++){
            comps++;
            if(arr[j] == arr[i]){
                deleteElements(arr, n, j, &assign);
                *steps += assign;
                j--;
            }
        }
        *steps += comps;
    }
}
//cách 2
//thuật toán bubblesort
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
//hàm xóa phần tử trùng nhau bằng phương án 2
void deleteDuplicateElements2(int arr[], int *n, int *steps){
    //đếm số comps và swaps của bubble sort
    int comps1, swaps1;
    bubbleSort(arr, *n, &comps1, &swaps1);
    //tính trước số steps của thuật toán bubble sort
    *steps = comps1 + swaps1;
    //tính số comps và assign của thuật toán ở dưới
    int j = 0, comps2 = 0, assign = 0;
    for(int i = 1; i < *n; i++){
        comps2++;
        if(arr[i] != arr[i - 1]){
            arr[j] = arr[i - 1];
            assign++;
            j++;
        }
    }
    *steps +=  comps2 + assign;
    arr[j] = arr[*n - 1];
    *n = j + 1;
}
int main(){
    int n; scanf("%d", &n);
    //khởi tạo kích thước 2 mảng giống nhau
    int n1 = n, n2 = n;
    //khởi tạo 2 mảng giống nhau
    int arr1[MAX], arr2[MAX];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];
    }
    //khởi tạo steps1, steps2 để tính số bước của 2 phương án
    int steps1, steps2;
    deleteDuplicateElements1(arr1, &n1, &steps1);
    deleteDuplicateElements2(arr2, &n2, &steps2);
    printf("Steps of first method is: %d\n", steps1);
    printf("Steps of second method is: %d\n", steps2);
    return 0;
}
/*
TestCase1:
10
1 2 3 1 4 5 3 6 7 2
Steps of first method is: 35
Steps of second method is: 70
TestCase2:
10
5 5 6 7 8 8 9 5 10 7
Steps of first method is: 36
Steps of second method is: 68
TestCase3: 
15
10 11 10 12 13 13 14 15 16 16 20 9 6 6 7
Steps of first method is: 104
Steps of second method is: 177
Ta có thể thấy số bước của phương án 2 nhiều hơn số bước của phương án 1.
Cho nên phương án 1 là tốt hơn.
*/