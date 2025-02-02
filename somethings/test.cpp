#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//InsertArray()
/*
void insertArray(int a[], int n, int value, int index, int *assigns){
    if(n <= index){
        a[index] = value;
        (*assigns)++;
        return;
    }
    a[n] = a[n - 1];
    (*assigns)++;
    insertArray(a, n - 1, value, index, assigns);
}
//Quy trinh 4 buoc
//Base case: n <= index
//Result of Base case:  insertArray(a, n, value, index, assigns): a[index] = value
//Before Base case: 
// TH1: n > index :insertArray(a, n, value, index, assigns): a[index + 1] = a[index]
// TH2: n == index: dan den base case la n n < index: ko xay ra
//Before before: insertArray(a, n, value, index, assigns): a[index + 2] = a[index + 1]
int main(){
    time_t t;
    srand((unsigned)time(&t));
    int a[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 10;
    int k = 10000;
    int min = 10, max = 50;
    int value, index, assigns;
    double average = 0;
    for(int i = 0; i < k; i++){
        assigns = 0;
        value = min + rand()%(max - min + 1);
        index = rand()%11;
        insertArray(a, n, value, index, &assigns);
        average += (double) assigns;
    }
    average /= (double) 10000;
    printf("Average of assigns: %f", average);
    return 0;
}
*/

//Đề sumArray()
int sumArray(int a[], int left, int right, int *count){
    //(*count) += 1;
    if(left <= right){
        (*count) += 2;
        int middle = (left + right) / 2;
        return a[middle] + sumArray(a, left, middle - 1, count) + sumArray(a, middle + 1, right, count);
    }else{
        return 0;
    }
}
//S = 3 + (1 + 0 + (2 + 0 + 0)) + (4 + 0 + (5 + 0 + 0))
//Qui trinh 4 buoc
//Base case: left > right
//Result of base case: Tra ve gia tri 0, sumArray(a, 1, 0) + sumArray(a, 2, 1) + sumArray(a, 4, 3) + sumArray(a, 5, 4) = 0
//Before base case: sumArray(a, 1, 1) = a[1] + sumArray(a, 1, 0) + sumArray(a, 2, 1) = 2 + sumArray(a, 4, 4) = a[4] + sumArray(a, 4, 3) + sumArray(a, 5, 4)= 5
//Before before: sumArray(a, 0, 1) = a[0] + sumArray(a, 0, -1) + sumArray(a, 1, 1) = 3 + sumArray(a, 3, 4) = a[3] + sumArray(a, 3, 2) + sumArray(a, 4, 4) = 9
int main(){
    int a[] = {1, 2, 3, 4, 5};
    int count = 1;
    int sum = sumArray(a, 0, 4, &count);
    printf("Sum = %d\n", sum);
    printf("so phep goi ham la: %d\n", count);
    return 0;
}