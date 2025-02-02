//1.1
// #include <stdio.h>
// int f(int n){
//     if(n == 1)
//         return 1;
//     return f(n - 1) * 2;
// }
// //Base case: n = 1
// //Result of base case: f(1) = 1
// //Before base case: n = 2, f(2) = f(1) * 2 = 1 * 2 = 2
// //Before before: n = 3, f(3) = f(2) * 2 = 2 * 2 = 4
// int main(){
//     int n; scanf("%d", &n);
//     printf("f(%d) = %d\n", n, f(n));
//     return 0;
// }

//1.2
// #include <stdio.h>
// float g(int n)
// {
//     if (n == 1)
//         return 1.0;
//     return n * n + g(n - 1);
// }
// //Base case: n = 1
// //Result of base case: g(1) = 1.0
// //Before base case: n = 2, g(2) = 2*2 + g(1) = 4 + 1.0 = 5
// //Before before: n = 3, g(3) = 3*3 + g(2) = 9 + 5 = 14
// int main(){
//     int n; scanf("%d", &n);
//     printf("g(%d) = %f\n", n, g(n));
//     return 0;
// }

//1.3
// #include <stdio.h>
// int F(int n)
// {
//     if (n == 1) return 1;
//     if (n == 2) return 1;
//     return F(n-1)+F(n-2);
// }
// //Base case: n = 1 va n = 2
// //Result of base case: F(1) = 1 or F(2) = 1
// //Before base case: n = 3, F(3) = F(2) + F(1) = 1 + 1 = 2
// //Before before: n = 4, F(4) = F(3) + F(2) = 2 + 1 = 3
// int main(){
//     int n; scanf("%d", &n);
//     printf("F(%d) = %d\n", n, F(n));
//     return 0;
// }

//1.4
#include <stdio.h>
int P(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 2;
	if (n == 2) return 3;
    return P(n-1)*P(n-3);
}
//Base case: n = 0 or n = 1 or n = 2
//Result of base case: P(0) = 1 hoac P(1) = 2 hoac P(2) = 3
//Before base case: n = 3, P(3) = P(2)*P(0) = 3*1 = 3
//Before before: n = 4, P(4) = P(3)*P(1) = 3*2 = 6
int main(){
    int n; scanf("%d", &n);
    printf("P(%d) = %d\n", n, P(n));
    return 0;
}


