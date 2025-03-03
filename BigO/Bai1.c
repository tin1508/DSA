#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 1000

//sinh mảng số thực trong đoạn [min, max]
void initializeArray(float arr[], int n, int min, int max){
    for(int i = 0; i < n; i++){
        //sinh phần nguyên trong đoạn [min, max - 1]
        arr[i] = min + rand() % (max - min); 
        // sinh phần thập phân trong đoạn [0, 100] sau đó chia cho 100 để thành số thập phân 
        float temp = (float) (rand() % 101) / 100;
        //cộng phần nguyên và phần thập phân
        arr[i] += temp;
    }
}
//hàm tìm chỉ số nhỏ nhất của phần tử nhỏ nhất
int minIndex(float arr[], int n, int *assignment, int *comps){
    //khởi tạo biến min_index bắt đầu từ chỉ số 0
    int min_index = 0;
    *assignment = 0, *comps = 0;
    for(int i = 1; i < n; i++){
        // tìm phần tử nhỏ nhất trong mảng
        (*comps)++;
        if(arr[i] < arr[min_index]){ 
            min_index = i;
            (*assignment)++;
        }
    }
    return min_index;
}

int main(){
    time_t t;
    srand((unsigned)time(&t));
    int n = 20;
    float arr[MAX];
    int k[5] = {10, 20, 50, 100, 1000};
    //khởi tạo min max để sinh mảng ngẫu nhiên trong đoạn [min, max]
    int min = -2 * n, max = 2 * n;
    int comps, assignment;
    for(int i = 0; i < 5; i++){
        //khởi tạo 2 mảng để đếm tần suất của comps và assigment
        int freqComps[21] = {0}, freqAssign[21] = {0};
        float avgComps = 0, avgAssignment = 0;
        for(int j = 0; j < k[i]; j++){
            initializeArray(arr, n, min, max);
            int MinIndex = minIndex(arr, n, &assignment, &comps);
            avgComps += (float) comps;
            avgAssignment += (float) assignment;
            freqComps[comps]++;
            freqAssign[assignment]++;
        }
        printf("with k = %d\n", k[i]);
        //tạo bảng tần số của comps và assignment
        printf("Steps \t FreqComps \t FreqAssign\n");
        for(int l = 0; l < 21; l++){
            printf("%3d   %8d   %14d\n", l + 1, freqComps[l], freqAssign[l]);
        }
        //tính số comps và assignment trung bình
        avgComps /= (float) k[i];
        avgAssignment /= (float) k[i];
        printf("Average of Comps's steps is: %.2f\n", avgComps);
        printf("Average of Assignment's steps is: %.2f\n", avgAssignment);
        printf("========================================\n");
    }
    return 0;
}