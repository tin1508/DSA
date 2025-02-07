#include <stdio.h>

//1. u(n) = n*(n + 1) = n^2 + n
//2.
int S(int n){
    //base case:
    if(n == 1) return 2;
    int sum = n*n + n;
    return sum + S(n - 1);
}
//3. Quy trình 4 bước
//Base case: n = 1
//Result of base case: S(1) = 2;
//Before base case: S(2) = (2*2 + 2) + S(1) = 6 + 2 = 8
//Before before: S(3) = (3*3 + 3) + S(2) = 12 + 8 = 20 

//4. Sử dụng vòng lặp
int S1(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i*i + i;
    }
    return sum;
}
int main(){
    int n = 100;
    int sum = S(n);
    int sum1 = S1(n);
    printf("Tong khi dung de quy la: %d\n", sum);
    printf("Tong ko dung de quy: %d\n", sum1);
    return 0;
}