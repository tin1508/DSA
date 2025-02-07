#include <stdio.h>

//1. u(n) = 1/(2n + 1)
//2.
float S(int n){
    //Base case
    if(n == 0) return (float) 1;
    //Khoi tao 1 bien fraction de tinh phan so moi lan de quy
    float fraction = (float) 1/(2*n + 1);
    return fraction + S(n - 1);
}
//3.Phan tich quy trinh 4 buoc
//Base case: n == 0
//Result of base case: S(0) = 1
//Before base case: S(1) = 1/(2*1 + 1) + S(0) = 1/3 + 1 = 4/3
//Before before: S(2) = 1/(2*2 + 1) + S(1) = 1/5 + 4/3 = 23/15

//4. Su dung ki thuat ko de quy
float S1(int n){
    //khoi tao sum = 0 voi kieu float
    float sum = 0;
    //thuc hien vong lap tinh tong day so
    for(int i = 0; i <= n; i++){
        sum += (float) 1/(2*i + 1);
    }
    //tra ve ket qua 
    return sum;
}
int main(){
    //khoi tao bien n = 10
    int n = 10;
    //xuat ra ket qua khi su dung 2 ki thuat
    printf("tong khi su dung de quy la: %f\n", S(n));
    printf("tong khi khong su dung de quy la: %f\n", S1(n));
    return 0;
}