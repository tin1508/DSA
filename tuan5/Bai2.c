#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 1000

//hàm sinh mảng ngẫu nhiên
void initializeArray(int arr[], int n, int max, int min){
    for(int i = 0; i < n; i++){
        arr[i] = min + rand()%(max - min + 1);
    }
}
//ham hoan vi 2 so nguyen a va b
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//bubble sort
void bubbleSort(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] < arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
//selection sort
void selectionSort(int arr[], int n){
    for(int i = 0; i < n; i++){
        int maxPos = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] > arr[maxPos]){
                maxPos = j;
            }
        }
        if(i != maxPos){
            swap(&arr[i], &arr[maxPos]);
        }
    }
}
//insertion sort
void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int tempValue = arr[i], pos = i - 1;
        int compsTemp = 1;
        while(pos >= 0 && arr[pos] < tempValue){
            arr[pos + 1] = arr[pos];
            --pos;
            if(pos == 0 && arr[pos] > tempValue){
                arr[pos + 1] = arr[pos];
                compsTemp++;
                break;
            }
            compsTemp++;
        }
        arr[pos + 1] = tempValue;
    }
}
int main(){
    time_t t;
    srand((unsigned)time(&t));
    int n = 20;
    int arr[MAX], arr1[MAX], arr2[MAX];
    int max = 100, min = -100;
    initializeArray(arr, n, max, min);
    //lưu mảng arr vào 2 mảng khác để thực hiện việc sắp xếp bằng 3 thuật toán
    for(int i = 0; i < n; i++){
        arr1[i] = arr[i];
        arr2[i] = arr[i];
    }
    printf("Initial Array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\nArray after bubble sort:\n");
    bubbleSort(arr, n);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\nArray after selection sort:\n");
    selectionSort(arr1, n);
    for(int i = 0; i < n; i++){
        printf("%d ", arr1[i]);
    }
    printf("\nArray after insertion sort:\n");
    insertionSort(arr2, n);
    for(int i = 0; i < n; i++){
        printf("%d ", arr2[i]);
    }
    return 0;
}
//ý tưởng chỉnh sửa
/*
-Bubble sort: thuật toán bubble sort gốc (sắp xếp tăng dần) sẽ hoán đổi 2 phần tử kề nhau, nên sắp xếp giảm dần
sẽ hoán đổi 2 phần tử nếu phần tử trước nhỏ hơn phần tử sau(đổi dấu '>' thành dấu '<')
-Selection sort: thuật toán selection sort gốc (sắp xếp tăng dần) sẽ sắp xếp bằng cách tìm phần tử nhỏ nhất trong
phần mảng chưa được sắp xếp và hoán đổi nó với vị trí đầu của phần mảng đó, nên sắp xếp theo thứ tự giảm dần
thì chỉ cần tìm phần tử lớn nhất. 
-Insertion sort: thuật toán insertion sort gốc (sắp xếp tăng dần) sắp xếp bằng cách shift những phần tử > tempValue chỗ trống bên phải
nên nếu sắp xếp giảm dần thì chúng ta sẽ shift những phần tử < tempValue. 
*/
