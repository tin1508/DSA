#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

// Hàm sinh mảng ngẫu nhiên
void initializeArray(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}
// Hàm hoán đổi 2 số nguyên
void swaps(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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
        else swaps(&arr[left], &arr[right]);
    }
    //sau khi chạy xong vòng lặp, hoán đổi biến arr[left] và arr[pivot]
    swaps(&arr[left], &arr[pivot_pos]);
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
//hàm tính giá trị trung bình
double average(int freq[], int k, int n){
    int sum = 0;
    for(int i = 0; i <= n*n; i++){
        sum += freq[i]*i;
    }
    return (double) sum / k;
}
int main() {
    time_t t;
    srand((unsigned)time(&t));
    int n = 10, min = 1, max = 100;
    int k[] = {10, 100, 1000, 10000};
    int arr[MAX];
    for (int t = 0; t < 4; t++) {
        int totalShiftLeft = 0, totalShiftRight = 0;
        int freqShiftLeft[MAX] = {0};
        int freqShiftRight[MAX] = {0};
        for (int i = 0; i < k[t]; i++) {
            initializeArray(arr, n, min, max);
            int shiftLeft = 0, shiftRight = 0; 
            quickSort(arr, 0, n - 1, &shiftLeft, &shiftRight);
            // Tính tổng của shiftLeft và shiftRight với k lần sinh mảng
            totalShiftLeft += shiftLeft;
            totalShiftRight += shiftRight;
            // Đếm tần suất
            freqShiftLeft[shiftLeft]++;
            freqShiftRight[shiftRight]++;
        }
        //Lập bảng tần số ứng với mỗi trường hợp k
        printf("With K = %d:\n", k[t]);
        printf("%2sSteps %4s FreqShiftLeft %5s FreqShiftRight\n", " ", " ", " ");
        for (int i = 0; i < MAX; i++) {
            if (freqShiftLeft[i] > 0 || freqShiftRight[i] > 0) {
                printf("%5d \t\t %d \t\t\t %d\n", i, freqShiftLeft[i], freqShiftRight[i]);
            }
        }
        printf("------------------------\n");
        double avgShiftLeft = average(freqShiftLeft, k[t], n);
        double avgShiftRight = average(freqShiftRight, k[t], n);
        printf("average shiftLeft: %.2f\n", avgShiftLeft);
        printf("average shiftRight: %.2f\n", avgShiftRight);
        printf("\n");
    }
    return 0;
}
