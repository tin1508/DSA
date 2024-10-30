#include <stdio.h>

#define MAX 1000

// mảng index dùng để lưu các chỉ số xuất hiện của các cặp tọa độ
// size dùng để lưu kích thước của mảng chỉ số
int size = 0, indexArr[MAX]; 
// hàm tìm ra chỉ số để xóa cặp tọa độ
void FindIndexToDelete(float a[][2], int n, float x1, float y1){
    for(int i = 0; i < n; i++){
        if(a[i][0] == x1 && a[i][1] == y1){
           indexArr[size] = i;
           size++; 
        }
    }
}
// hàm delete cặp tọa độ
void deletePairElement(float a[][2], int *n, int index){
    for(int i = index; i < *n; i++){
        a[i][0] = a[i + 1][0];
        a[i][1] = a[i + 1][1];
    }
    *n -= 1;
}
int main(){
    int n; scanf("%d", &n);
    float a[MAX][2];
    float x, y; // cặp tọa độ mỏ đá quý
    for(int i = 0; i < n; i++){
        scanf("%f %f", &x, &y);
        a[i][0] = x;
        a[i][1] = y;
    }
    float x1, y1; // tọa độ người dùng cung cấp
    scanf("%f %f", &x1, &y1);
    FindIndexToDelete(a, n, x1, y1);
    if(size == 0){
        printf("Can not delete %.2f %.2f from the array", x1, y1);
    }
    else{
        for(int i = 0; i < size; i++){
            deletePairElement(a, &n, indexArr[i]);
        }
        for(int i = 0; i < n; i++){
            printf("%.2f %.2f\n", a[i][0], a[i][1]);
        }
        printf("Delete %.2f %.2f at ", x1, y1);
        for(int i = 0; i < size; i++){
            printf("%d", indexArr[i]);
            if(i != size - 1){
                printf(", ");
            }
        }
    }
    return 0;
}