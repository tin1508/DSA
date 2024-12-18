#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 1000
void initializeArray(int arr[], int n, int max, int min){
    for(int i = 0; i < n; i++){
        arr[i] = min + rand() % (max - min + 1);
    }
}

void f(int a[], int n, int b[], int *comps, int *assign)
{
    *comps = 0, *assign = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (*comps)++;
            if (a[i] == a[j])
            {
                b[a[i]]++;
                (*assign)++;
            }
        }
    }
}

int main(){
    time_t t;
    srand((unsigned)time(&t));
    int n = 20;
    int arr[MAX];
    int max = 100, min = 0;
    printf("\n");
    int k[3] = {100, 1000, 10000};
    int comps, assign;
    //khởi tạo biến để tổng kết cuối thuật toán
    double averageCmps, averageAssign;
    for(int i = 0; i < 3; i++){
        int freqComps[MAX] = {0}, freqAssign[MAX] = {0};
        double AverageComps = 0, AverageAssign = 0;
        for(int j = 0; j < k[i]; j++){
            initializeArray(arr, n, max, min);
            int b[101] = {0};
            f(arr, n, b, &comps, &assign);
            freqComps[comps]++;
            freqAssign[assign]++;
            AverageComps += (double) comps;
            AverageAssign += (double) assign;
        }
        printf("with k = %d\n", k[i]);
        printf("Steps\t Comps\t Assign\n");
        for(int m = 0; m <= n*n; m++){
            if(freqComps[m] != 0 || freqAssign[m] != 0){
                printf("%d\t %d\t %d\n", m, freqComps[m], freqAssign[m]);
            }
        }
        AverageComps /= (double) k[i];
        AverageAssign /= (double) k[i];
        printf("Average Comps: %.2f, Average Assign: %.2f\n", AverageComps, AverageAssign);
        averageCmps += AverageComps;
        averageAssign += AverageAssign;
        printf("\n");
    }
    averageCmps /= (double) 3;
    averageAssign /= (double) 3;
    printf("Final Conclusion: Average Comps: %.2f, Average Assign: %.2f\n", averageCmps, averageAssign);
    return 0;
}