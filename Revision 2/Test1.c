#include <stdio.h>

#define MAX 1000
/*
Ma tran
m = 4, n = 3;
2 1 3
-2 0 4
1 1 2
-1 2 -3
*/
//Base case: m = 0 va n = 0
//Result of base case: sum2DArray(arr, 0, 0, temp) = arr[0][0] = 2
//Before base case: m = 0 va n = 1, sum2DArray(arr, 0, 1, temp) = arr[0][1] + sum2DArray(arr, 0, 0, temp) = 1 + 2 = 3
//Before before: m = 0 va n = 2, sum2DArray(arr, 0, 2, temp) = arr[0][2] + sum2DArray(arr, 0, 1, temp) = 3 + 3 = 6
int sum2DArray(int arr[][MAX], int m, int n, int temp){
    if(m == 0 && n == 0){
        return arr[0][0];
    }
    int sum;
    sum = arr[m][n];
    if(n == 0){
        n = temp;
        return sum + sum2DArray(arr, m - 1, n, temp);
    }
    else{
        return sum + sum2DArray(arr, m, n - 1, temp);
    }
}
int main(){
    int arr[][MAX] = {{2, 1, 3}, {-2, 0, 4}, {1, 1, 2}, {-1, 2, -3}};
    int m = 4, n = 3;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }
    int sum = sum2DArray(arr, m - 1, n - 1, n - 1);
    printf("%d ", sum);
    return 0;
}