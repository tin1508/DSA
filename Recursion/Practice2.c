#include <stdio.h>

//S1 = 1 + 1/2 + 1/3 + ... + 1/n
/*
Base case la : n = 1
Ket qua cua Base Case: S1(a, 1) = 1
Truong hop nam truoc Base Case la n = 2: S1(a, 2) = 1 + 1/2
Truong hop nam truoc Base Case la n = 3: S1(a, 3) = 1 + 1/2 + 1/3 
*/
double S1(int n){
    if(n == 1){
        return 1;
    }
    return ((double) 1 / n) + S1(n - 1);
}
//S2 = 1/2 + 1/4 + ... + 1/2n
/*
Base case la : n = 1
Ket qua cua Base Case: S2(a, 1) = 1/2
Truong hop nam truoc Base Case la n = 2: S2(a, 2) = 1/2 + 1/4
Truong hop nam truoc Base Case la n = 3: S2(a, 3) = 1/2 + 1/4 + 1/6
*/
double S2(int n){
    if(n == 1) return (double) 1/2;
    return ((double) 1/(2*n)) + S2(n - 1);
}
//S3 = 1/2 + 2/3 + 3/4 + ... + n/n+1
/*
Base case la : n = 1
Ket qua cua Base Case: S3(a, 1) = 1/2
Truong hop nam truoc Base Case la n = 2: S3(a, 2) = 1/2 + 2/3
Truong hop nam truoc Base Case la n = 3: S3(a, 3) = 1/2 + 2/3 + 3/4
*/
double S3(int n){
    if(n == 1) return (double) 1/2;
    return ((double) n/(n + 1)) + S3(n - 1);
}
//f(0) = 2, f(1) = 3, f(n) = 6*f(n - 1) - 9*f(n - 2)
/*
Base case la : n = 0 va n = 1
Ket qua cua Base Case: f(0) = 2 va f(1) = 3
Truong hop nam truoc Base Case la n = 2: f(2) = 6*3 - 9*2
Truong hop nam truoc n = 2 la n = 3: f(3) = 6*f(2) - 9*f(1) = 6*(6*3 - 9*2) - 9*3
*/
int f(int n){
    if(n == 0) return 2;
    if(n == 1) return 3;
    return 6*f(n - 1) - 9*f(n - 2);
}
int main(){
    int n; scanf("%d", &n);
    printf("S1 = %f\n", S1(n));
    printf("S2 = %f\n", S2(n));
    printf("S3 = %f\n", S3(n));
    printf("f(%d) = %d\n", n, f(n));
    return 0;
}