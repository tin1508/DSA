#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define MAX_SHIFTS 1000 // Giới hạn tối đa cho số lần dịch chuyển

// Hàm hoán đổi
void swaps(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm phân hoạch (sử dụng hai con trỏ và vòng lặp while)
int partition(int arr[], int left, int right, int *shiftLeft, int *shiftRight) {
    int pivot_pos = right; // Chọn phần tử cuối làm pivot
    int pivot = arr[pivot_pos];
    right -= 1; // Dịch con trỏ phải sang trái để tránh pivot

    while (1) {
        // Tìm phần tử lớn hơn hoặc bằng pivot từ bên trái
        while (arr[left] < pivot) {
            (*shiftLeft)++;
            left++;
        }

        // Tìm phần tử nhỏ hơn pivot từ bên phải
        while (arr[right] >= pivot) {
            (*shiftRight)++;
            right--;
        }

        // Nếu con trỏ trái >= con trỏ phải, thoát vòng lặp
        if (left >= right) break;

        // Hoán đổi hai phần tử
        swaps(&arr[left], &arr[right]);
    }

    // Đặt pivot vào đúng vị trí
    swaps(&arr[left], &arr[pivot_pos]);

    return left; // Trả về vị trí của pivot
}

// Hàm QuickSort
void quickSort(int arr[], int low, int high, int *shiftLeft, int *shiftRight) {
    if (low < high) {
        int pi = partition(arr, low, high, shiftLeft, shiftRight);

        quickSort(arr, low, pi - 1, shiftLeft, shiftRight);
        quickSort(arr, pi + 1, high, shiftLeft, shiftRight);
    }
}

// Hàm sinh mảng ngẫu nhiên
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 101; // Giá trị từ 0 đến 100
    }
}

// Hàm in tần suất
void printFrequency(int freq[], int size, const char *label) {
    printf("Tần suất của %s:\n", label);
    for (int i = 0; i < size; i++) {
        if (freq[i] > 0) {
            printf("Giá trị %d: %d lần\n", i, freq[i]);
        }
    }
    printf("------------------------\n");
}

// Hàm chính
int main() {
    srand(time(NULL));

    int k[] = {10, 100, 1000, 10000}; // Số lần thực hiện thí nghiệm
    for (int t = 0; t < 4; t++) {
        int trials = k[t];
        long long totalShiftLeft = 0, totalShiftRight = 0;

        // Khởi tạo mảng tần suất
        int freqShiftLeft[MAX_SHIFTS] = {0};
        int freqShiftRight[MAX_SHIFTS] = {0};

        for (int i = 0; i < trials; i++) {
            int arr[N];
            generateRandomArray(arr, N);
            int shiftLeft = 0, shiftRight = 0; // Đếm dịch chuyển cho từng lần thử

            quickSort(arr, 0, N - 1, &shiftLeft, &shiftRight);

            // Cập nhật tổng
            totalShiftLeft += shiftLeft;
            totalShiftRight += shiftRight;

            // Cập nhật tần suất
            if (shiftLeft < MAX_SHIFTS) freqShiftLeft[shiftLeft]++;
            if (shiftRight < MAX_SHIFTS) freqShiftRight[shiftRight]++;
        }

        // In kết quả
        printf("K = %d:\n", trials);
        printf("Trung bình shiftLeft: %.2f\n", (double)totalShiftLeft / trials);
        printf("Trung bình shiftRight: %.2f\n", (double)totalShiftRight / trials);

        // In bảng tần suất
        printFrequency(freqShiftLeft, MAX_SHIFTS, "shiftLeft");
        printFrequency(freqShiftRight, MAX_SHIFTS, "shiftRight");
    }

    return 0;
}
