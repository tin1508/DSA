#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 1000

//sinh mảng số thực trong đoạn [min, max]
void initializeArray(float arr[], int n, int min, int max){
    for(int i = 0; i < n; i++){
        //sinh phần nguyên trong đoạn [min, max - 1]
        arr[i] = (float) min + rand() % (max - min);
        // sinh phần thập phân trong đoạn [0, 100] sau đó chia cho 100 để thành số thập phân 
        float temp = (float) (rand() % 101) / 100;
        //cộng phần nguyên và phần thập phân
        arr[i] += temp;
    }
}
//hàm hoán đổi 2 số thực
void swap(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}
// hàm sort theo yêu cầu 1 của đề bài
void sort(float arr[], int statis[], int n, int *comparison){
    for(int i = 0; i < n; i++){
        int minIndex = i;
        *comparison = 0;
        for(int j = i + 1; j < n; j++){
            (*comparison)++;
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(i != minIndex){
            swap(&arr[i], &arr[minIndex]);   
        }
        statis[i] = *comparison;
    }
}

int main(){
    time_t t;
    srand((unsigned)time(&t));
    int n = 40;
    float arr[MAX];
    // giới hạn phần tử trong mảng trong đoạn[1, 100] 
    int min = 0, max = 10;
    //sinh mảng ngẫu nhiên trong đoạn [min, max]
    initializeArray(arr, n, min, max);
    printf("random array is: \n");
    for(int i = 0; i < n; i++){
        printf("%.2f ", arr[i]);
    }
    //mảng statis để thống kê số lần comps ở mỗi vòng
    int statis[41], comps;
    sort(arr, statis, n, &comps);
    printf("\nrandom array is sorted: \n");
    for(int i = 0; i < n; i++){
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    int sum = 0;
    //tạo bảng thống kê
    printf("Passthrough \t Comparison's Steps\n");
    for(int i = 0; i <= 39; i++){
        printf("%5d   %20d\n", i + 1, statis[i]);
        sum += statis[i];
    }
    float average = (float) sum / n;
    printf("total comparsion's steps is: %d\n", sum);
    printf("average comparison's steps is: %.2f", average);
    return 0;
}

/*
    từ bảng thống kê chúng ta có thế thấy được 
    tổng số comparison sẽ là: 
    (n - 1) + (n - 2) + ... + 1
    Vậy ta sẽ có công thức là (n * (n - 1)) / 2.
    Do đó số lần so sánh cho thuật toán Sort trên sẽ là n^2 / 2
    trog trường hợp xấu nhất cũng như trong trường hợp trung bình.
    Do đó độ phức tạp về thời gian của trường hợp trung bình và trường hợp xấu nhất
    đều là O(n^2). 
*/