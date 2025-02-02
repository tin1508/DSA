#include <stdio.h>

#define MAX 1000

//ham hoan doi 2 so nguyen a va b
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
// Hàm phân hoạch của quicksort
int partition(int arr[], int left, int right, int *shiftLeft, int *shiftRight) {
    //Khởi tạo 1 biến làm pivot
    int pivot_pos = right;
    int pivot = arr[pivot_pos];
    right -= 1;
    while (1) {
        //Duyệt từ trái qua phải đến khi gặp phần tử >= pivot
        while (arr[left] < pivot) {
            (*shiftLeft)++;
            left++;
        }
        //Duyệt từ phải qua trái đến khi gặp phần tử < pivot (thêm điều kiện left < right để khi biến right gặp biến left thì dừng ko đi về sau nữa)
        while (arr[right] >= pivot && left < right) {
            (*shiftRight)++;
            right--;
        }
        //Nếu biến left lớn hơn biến right thì dừng
        if (left >= right) break;
        else swap(&arr[left], &arr[right]);
    }
    //sau khi chạy xong vòng lặp, hoán đổi biến arr[left] và arr[pivot]
    swap(&arr[left], &arr[pivot_pos]);
    return left; 
}

// Hàm QuickSort
void quickSort(int arr[], int left, int right, int *shiftLeft, int *shiftRight) {
    if(left >= right) return;
    else{
        //tìm vị trí phần tử pivot
        int pivot = partition(arr, left, right, shiftLeft, shiftRight);
        //thực hiện quicksort
        quickSort(arr, left, pivot - 1, shiftLeft, shiftRight);
        quickSort(arr, pivot + 1, right, shiftLeft, shiftRight);
    }
}
//hàm copy mảng chính vào 3 mảng còn lại để so sánh hiệu năng
void arrCpy(int arr[], int n, int arrCpy1[], int arrCpy2[], int arrCpy3[], int arrCpy4[]){
    for(int i = 0; i < n; i++){
        arrCpy1[i] = arr[i];
        arrCpy2[i] = arr[i];
        arrCpy3[i] = arr[i];
        arrCpy4[i] = arr[i];
    }
}
//hàm in mảng
void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    //Khởi tạo các mảng cần để so sánh
    int arrA[MAX] = {3, 2, 9, 7, 5};
    int arrB[MAX] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arrC[MAX] = {4, 3, 2, 6, 5, -3, 5, 7, -3, 1, -3, 5, 7, 9, 7, -5, 3, 2, 1, 2};
    int arrD[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 11, 17, 14, 15, 16, 13, 18, 19, 20};
    //kích thước của mảng theo từng trường hợp a, b, c, d
    int n[4] = {5, 10, 20, 20};
    int arr1[MAX], arr2[MAX], arr3[MAX], arr4[MAX];
    //Khai báo các biến dùng để đếm số steps của 1 thuật toán sort
    int compsBubble, swapsBubble, compsSelect, swapsSelect, compsInsert, shiftInsert;
    int shiftLeft, shiftRight;
    int stepsBubble, stepsSelect, stepsInsert, stepsQuick;
    for(int i = 0; i < 4; i++){
        int stepsBubble, stepsSelect, stepsInsert, stepsQuick;
        printf("Unsorted array: \n");
        if(n[i] == 5){
            printArr(arrA, n[i]);
            arrCpy(arrA, n[i], arr1, arr2, arr3, arr4);
        }
        else if(n[i] == 10){
            printArr(arrB, n[i]);
            arrCpy(arrB, n[i], arr1, arr2, arr3, arr4);
        }
        //Điều kiện này dùng để tránh nhầm lẫn giữa 2 mảng có kích thước 20
        else if(n[i] == 20 && i != 3){
            printArr(arrC, n[i]);
            arrCpy(arrC, n[i], arr1, arr2, arr3, arr4);
        }
        else{
            printArr(arrD, n[i]);
            arrCpy(arrD, n[i], arr1, arr2, arr3, arr4);
        }
        bubbleSort(arr1, n[i], &compsBubble, &swapsBubble);
        selectionSort(arr2, n[i], &compsSelect, &swapsSelect);
        insertionSort(arr3, n[i], &compsInsert, &shiftInsert);
        quickSort(arr4, 0, n[i] - 1, &shiftLeft, &shiftRight);
        //Tính tổng số steps của mỗi thuật toán sort
        stepsBubble = compsBubble + swapsBubble;
        stepsSelect = compsSelect + swapsSelect;
        stepsInsert = compsInsert + shiftInsert;
        stepsQuick = shiftLeft + shiftRight;
        printf("\nn \t bubbleSort's steps \t\t selectionSort's steps \t\t insertionSort's steps \t\t\t\t quickSort's steps\n");
        printf("%d \t Comps: %d \t\t\t Comps: %d \t\t\t\t Comps: %d \t\t\t\t shiftLeft: %d\n", n[i], compsBubble, compsSelect, compsInsert, shiftLeft);
        printf("\t Swaps: %d \t\t\t Swaps: %d \t\t\t\t shifts: %d \t\t\t\t shiftRight: %d\n", swapsBubble, swapsSelect, shiftInsert, shiftRight);
        printf("\t Steps: %d \t\t\t Steps: %d \t\t\t\t Steps: %d \t\t\t\t Steps: %d\n", stepsBubble, stepsSelect, stepsInsert, stepsQuick);
        printf("\n");
    }
    return 0;
}
/*
Ta có thể thấy tùy vào từng trường hợp mảng như thế nào sau đó ta lựa chọn thuật toán sort cho phù hợp!!!
-Đối với trường hợp mảng tăng dần thì ta nên lựa chọn Insertion Sort là thuật toán tốt nhất cho trường hợp này.
-Còn đối với các trường hợp còn lại thì QUickSort là lựa chọn tốt nhất.
*/
