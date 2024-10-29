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
    double distance = (double) abs(arr[0] - m);
    double result = arr[0];
    int index = 0;
    for(int i = 1; i < n; i++){
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
