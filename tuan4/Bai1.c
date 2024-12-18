#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 1001

//1.1
/*
//hàm hoán đổi 2 số thực
void swap(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}
//thuật toán sắp xếp bubble sort
void bubbleSort(float arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
int main(){
    printf("Nhap kich thuoc mang: ");
    int n; scanf("%d", &n);
    float arr[MAX];
    printf("Nhap mang so thuc:\n");
    for(int i = 0; i < n; i++){
        scanf("%f", &arr[i]);
    }
    bubbleSort(arr, n);
    printf("Mang so thuc sau khi sap xep la:\n");
    for(int i = 0; i < n; i++){
        printf("%.2f ", arr[i]);
    }
    return 0;
}
*/


//1.2
/*
//thuật toán random chữ cái ngẫu nhiên
void initializeArrayStr(char str[], int n){
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int size = strlen(charset);
    for(int i = 0; i < n; i++){
        str[i] = charset[rand() % size];
    }
    str[n] = '\0';
}
//hàm hoán đổi 2 chữ cái
void swap(char *c1, char *c2){
    char tempChar = *c1;
    *c1 = *c2;
    *c2 = tempChar;
}
//thuật toán sắp xếp bubble sort
void bubbleSort(char str[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(str[j] > str[j + 1]){
                swap(&str[j], &str[j + 1]);
            }
        }
    }
}

int main(){
    time_t t;
    srand((unsigned)time(&t));
    //nhập độ dài của chuỗi
    int n; 
    printf("Nhap do dai cua chuoi: ");
    scanf("%d", &n);
    char str[MAX];
    initializeArrayStr(str, n);
    printf("Chuoi duoc sinh ngau nhien la: \n%s", str);
    bubbleSort(str, n);
    printf("\nChuoi sau khi duoc sap xep: \n%s", str);
    return 0;
}
*/

//1.3
//hàm hoán đổi 2 số thực
void swap(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}
//hàm hoán đổi 2 mảng số thực
void swapArr(float arr1[3], float arr2[3]){
    swap(&arr1[0], &arr2[0]);
    swap(&arr1[1], &arr2[1]);
    swap(&arr1[2], &arr2[2]);
}
//hàm tính giá trị F theo công thức
float F(float arr[]){
    return (float) arr[0] - 2*arr[1] + 3*arr[2];
}
//thuật toán sắp xếp bubble sort
void bubbleSort(float arr[][3], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(F(arr[j]) > F(arr[j + 1])){
                swapArr(arr[j], arr[j + 1]);
            }
        }
    }
}
int main(){
    //nhập kích thước n của mảng
    printf("nhap kich thuoc cua mang: ");
    int n; scanf("%d", &n);
    //khởi tạo mảng a với mỗi phần tử là bộ 3 số thực
    float arr[MAX][3];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            scanf("%f", &arr[i][j]);
        }
    }
    //sắp xếp mảng theo thứ tự tăng dần
    bubbleSort(arr, n);
    printf("Mang sau khi sap xep la:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            printf("%.2f ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
