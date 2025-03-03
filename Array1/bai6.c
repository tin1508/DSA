#include <stdio.h>
#define MAX 1000
float res[MAX], valueArr[MAX];
int IndexArr[MAX];
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sortArr(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] > arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }
}
// thuật toán:
/*
Khai báo 1 mảng trống res, dùng 1 mảng lưu index cần chèn và 1 mảng
lưu giá trị cần chèn tương ứng
Sau đó, với mỗi phần tử của mảng a ở chỉ số j sẽ so sánh với với
a ở chỉ số index xem có bằng ko thì đó chính là vị trí cần chèn
sau đó sẽ đẩy phần tử cần chèn vào mảng res trước rồi sau đó
tới phần tử ở vị trí đó của mảng a 
*/
void insertArr(float a[], int *n, int m, int indexArr[], float valueArr[]){
    *n += m;
    int j = 0, k = 0;
    for(int i = 0; i < *n; i++){
        if(a[j] == a[indexArr[k]]){
            res[i] = valueArr[indexArr[k]];
            k++;
        }
        else{
            res[i] = a[j];
            j++;
        }
    }
}
int main(){
    int n; scanf("%d", &n);
    float a[MAX];
    for(int i = 0; i < n; i++){
        scanf("%f", &a[i]);
    }
    int m; scanf("%d", &m);
    float number;
    int index;
    int size = 0; // kích thước của mảng index
    for(int i = 0; i < m; i++){
        scanf("%f %d", &number, &index);
        IndexArr[i] = index;
        size++;
        valueArr[index] = number;
    }
    /*
    hàm sort này dùng để sort các chỉ số index theo kiểu tăng dần
    để khi chèn dễ hơn
    */
    sortArr(IndexArr, size);
    insertArr(a, &n, m, IndexArr, valueArr);
    for(int i = 0; i < n; i++){
        printf("%.2f ", res[i]);
    }
    return 0;
}