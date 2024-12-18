#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000
//hàm sinh mảng ngẫu nhiên trong đoạn [min, max]
void initializeArray(int arr[], int n, int min, int max){
    for(int i = 0; i < n; i++){
        arr[i] = min + rand() % (max - min + 1);
    }
}
//hàm copy 1 mảng vào 1 mảng
void ArrCpy(int arr1[], int arr2[], int n){
    for(int i = 0; i < n; i++){
        arr2[i] = arr1[i];
    }
}
//hàm hoán đổi 2 số nguyên
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Thuật toán 1
void caseA(int arr[], int *n, int k, int *comps){
    //khởi tạo biến newSize để lưu kích thước sau khi xóa phần tử
    int newSize = 0;
    //khởi tạo biến comps để đếm số lần so sánh trong thuật toán
    *comps = 0;
    for(int i = 0; i < *n; i++){
        (*comps)++;
        if(arr[i] < k){
            arr[newSize] = arr[i];
            newSize++;
        }
    }
    *n = newSize;
}
//thuật toán 2
void caseB(int arr[], int *n, int k, int *comps){
    /*
    khởi tạo biến comps để đếm số lần so sánh 
    của thuật toán sort trng hàm caseB
    */
    *comps = 0;
    for(int i = 0; i < *n; i++){
        int minIndex = i;
        for(int j = i + 1; j < *n; j++){
            (*comps)++;
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(i != minIndex){
            swap(&arr[i], &arr[minIndex]);
        }
    }
    /*
    khởi tạo biến comps1 để đếm số lần so sánh 
    của của thuật toán xóa phần tử dưới đây
    */
    int comps1 = 0;
    int newSize = 0;
    for(int i = 0; i < *n; i++){
        if(arr[i] >= k){
            comps1++;
            *n = newSize;
            break;
        }
        else{
            newSize++;
            comps1++;
        }
    }
    //tổng số bước so sánh trong hàm caseB
    *comps += comps1;
}
int main(){
    time_t t;
    srand((unsigned)time(&t));
    int n = 100;
    //khởi tạo mảng và 1 mảng copy để dễ so sánh
    int arr1[MAX], arr2[MAX];
    int m[4] = {10, 100, 1000, 10000};
    int min = 1998, max = 2023, k = 2016;
    //comps1: số bước so sánh của caseA
    //comps2: số bước so sánh của caseB
    int comps1, comps2;
    for(int i = 0; i < 4; i++){
        float avgComps1 = 0, avgComps2 = 0;
        for(int j = 0; j < m[i]; j++){
            int n1 = n, n2 = n;
            initializeArray(arr1, n1, min, max);
            //copy arr1 vào arr2
            ArrCpy(arr1, arr2, n1);
            caseA(arr1, &n1, k, &comps1);
            caseB(arr2, &n2, k, &comps2);
            avgComps1 = (float) avgComps1 + comps1;
            avgComps2 = (float) avgComps2 + comps2;
        }
        //tính số bước so sánh trung bình
        avgComps1 /= (float) m[i];
        avgComps2 /= (float) m[i];
        printf("with m = %d\n", m[i]);
        printf("Average comparison's steps of CaseA: %.2f\n", avgComps1);
        printf("Average comparison's steps of CaseB: %.2f\n", avgComps2);
        printf("========================================\n");
    }
    return 0;
}
/*
- Phương pháp đánh giá: sử dụng độ phức tạp thuật toán O(n).
- Cách thực hiện: Sử dụng biến đếm phép so sánh trong 2 thuật toán, sinh mảng m lần
rồi tính số bước so sánh trung bình để ước lượng O(n).
+ Theo như thuật toán trên em sinh mảng m lần và sử dụng 2 thuật toán 
thì thuật toán caseA sẽ tốt hơn với số bước so sánh trung bình là n. Còn
thuật toán ở caseB sẽ tốn khoảng n^2 / 2 bước so sánh trung bình.
+ O(n) của caseA là O(n), O(n) của caseB là O(n^2 / 2) hay O(n^2).
*/