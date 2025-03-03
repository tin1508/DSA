#include <stdio.h>

int sum(int a[], int n){
    if(n == 1){
        return a[0];
    }
    return sum(a, n - 1) + a[n - 1];
}
//Base case: n = 1
//Result of base case: sum(a, 1) = a[0]
//Before base case: n = 2, sum(a, 2) = a[1] + a[0]
//Before before: n = 3, sum(a, 3) = a[2] + a[1] + a[0]
int main(){
    int n; scanf("%d", &n);
    int arr[100];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int sumOfArray = sum(arr, n);
    printf("%d", sumOfArray);
    return 0;
}