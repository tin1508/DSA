#include <stdio.h>

#define MAX 100

void deleteArray(int a[], int *n, int index){
    for(int i = index; i < *n; i++){
        *(a + i) = *(a + i + 1);
    }
    *n -= 1;
}
int main(){
    int n; 
    scanf("%d", &n);
    int a[MAX];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int index; 
    scanf("%d", &index);
    deleteArray(a, &n, index);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}