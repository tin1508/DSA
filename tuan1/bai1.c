#include <stdio.h>
#include <math.h>
#define MAX 1000
int main(){
    int n; 
    scanf("%d", &n);
    float arr[MAX];
    for(int i = 0; i < n; i++){
        scanf("%f", &arr[i]);
    }
    int m; scanf("%d", &m);
    // tính khoảng cách từ số đầu tiên trước với số đã cho
    double distance = (double) abs(arr[0] - m); 
    double result = arr[0]; // dùng để lưu kết quả 
    int index = 0; // dùng để lưu chỉ số của kết quả tìm được
    for(int i = 1; i < n; i++){
        // tính khoảng cách từ số thứ 2 với số đã cho và so sánh với distance
        double temp = (double) abs(arr[i] - m); 
        if(distance > temp){
            distance = temp;
            result = arr[i];
            index = i;
        }
    }
    printf("%.2f at index %d nearest to %d", result, index, m);
    return 0;
}
