#include <stdio.h>

#define MAX 1000

int binarySearchRecur(int arr[], int l, int r, int value){
    if(l <= r){
        int m = (l + r) / 2;
        if(arr[m] == value) return m;
        else if(arr[m] > value) return binarySearchRecur(arr, l, m - 1, value);
        else return binarySearchRecur(arr, m + 1, r, value); 
    }
    return -1;
}
//Phân tích quy trình 4 bước
//Base case: TH1: l <= r: arr[m] == value (với m = (l + r) / 2)
//TH2: l > r (trường hợp ko tìm thấy)
//Result of base case: TH1: binarySearchRecur(arr, l, r, value) = m
///TH2: binarySearchRecur(arr, l, r, value) = -1 (trường hợp ko tìm thấy)
//Lấy mảng ví dụ: 1 2 3 4 5 6 với value cần tìm là 4 (này sẽ rơi vào trường hợp tìm thấy value)
//Before base case: binarySearchRecur(arr, 3, 5, 4): m = 4, nên sẽ tìm trong đoạn từ l -> r 4 5 6 (value < arr[m])
//Before before: binarySearchRecur(arr, 0, 5, 4): m = 2, nên sẽ tìm trong đoạn từ l -> r 1 2 3 4 5 6 (value > arr[m])
int main(){
    //nhap 1 mang so nguyen co thu tu
    int n;// khai bao kich thuoc mang
    scanf("%d", &n);
    int arr[MAX];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int value; scanf("%d", &value);
    int index = binarySearchRecur(arr, 0, n - 1, value);
    if(index == -1){
        printf("Not found!\n");
    }
    else printf("Found at index: %d\n", index);
    return 0;
}