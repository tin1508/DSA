#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 1000

//hàm sinh mảng ngẫu nhiên trong đoạn [min, max]
void initializeArray(int arr[], int n, int max, int min){
    for(int i = 0; i < n; i++){
        arr[i] = min + rand() % (max - min + 1);
    }
}
//hàm hoán đổi 2 số nguyên
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// hàm bubble sort
void bubbleSort(int arr[], int n, int *comps){
    *comps = 0;
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j > i; j--){
            (*comps)++;
            if(arr[j - 1] > arr[j]){
                swap(arr + j - 1, arr + j);
            }
        }
    }
}

int main(){
    // int n = 20;
    int arr[MAX];
    // giới hạn phần tử nằm trong đoạn [0, 10]
    int min = -100, max = 100; 
    // int n[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int k[6] = {10, 20, 50, 100, 1000, 10000};
    int comps;
    for(int m = 0; m < 10; m++){
        printf("with n = %d\n", n[m]);
        //khởi tạo mảng để lưu số lần comparison trung bình ứng với từng lần sinh k lần
        float AverageComps[6] = {0};
        //khởi tạo 1 biến để tính số lần comparison trung bình sau k lần chạy với từng trường hợp n
        float resAverageComps = 0;
        for(int i = 0; i < 6; i++){
            //Khởi tạo biến averageComps để tính số lần comparison trung bình
            float averageComps = 0;
            for(int j = 0; j < k[i]; j++){
                initializeArray(arr, n[m], max, min);
                bubbleSort(arr, n[m], &comps);
                averageComps += (float) comps;
            }
            averageComps /= (float) k[i];
            AverageComps[i] = averageComps; 
        }
        printf("   k \t   average Comparison\n");
        for(int l = 0; l < 6; l++){
            printf("%5d   %14.2f\n", k[l], AverageComps[l]);
            resAverageComps += AverageComps[l];
        }
        resAverageComps /= (float) 6;
        printf("Average after k times generation: %.2f\n", resAverageComps);
        printf("========================================\n");
    }
    return 0;
}
/*
*Yêu cầu 2:
- Với n cố định = 20;
- Nhận xét về số lần comparison trung bình:
+ Ta có thể thấy được số lần comparison sẽ cố định là 190 với n = 20 dù có sinh bao nhiêu lần.
+ Nên chúng ta có thể thấy được số lần comparison trung bình sẽ là (n*(n - 1)) / 2.
*/

/*
*Yêu cầu 3:
- Theo từng trường hợp n có thể cho chúng ta thấy được
số comparison trung bình sau k lần sinh sẽ là (n * (n - 1)) / 2
- Qua đó chúng ta có thể thấy được số comparison sẽ ko thay đổi
dù sinh bao nhiêu lần.
- Do đó số lần so sánh cho thuật toán Sort trên sẽ là n^2 / 2
hay n^2 trog trường hợp xấu nhất cũng như trong trường hợp trung bình.
- Do đó độ phức tạp về thời gian của trường hợp trung bình và trường hợp xấu nhất
đều là O(n^2). 
*/

/*
*Yêu cầu 4:
- Chúng ta có thể thấy được O(n) của 2 thuật toán sort
ở bài 2,3 trong trường hợp trung bình hay xấu nhất là
như nhau.
- Nên là tùy vào trường hợp chúng ta sẽ sử dụng thuật 
toán sort nào cho phù hợp.
- Thuật toán bài 2 sẽ cố số bước swaps ít hơn nên sẽ
giúp chúng ta đỡ bước giải hơn là thuật toán ở bài 3.
*/