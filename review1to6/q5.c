#include <stdio.h>

void f(int a[], int n, int b[], int *comps, int *assign)
{
    printf("Initial array:[");
    for(int i = 0; i < n; i++){
        printf("%d ", b[i]);
    }
    printf("]\n");
    int sumComps = 0, sumAssign = 0;
    for (int i = 0; i < n; i++)
    {
        *comps = 0, *assign = 0;
        for (int j = 0; j < n; j++)
        {
            (*comps)++;
            if (a[i] == a[j])
            {
                b[a[i]]++;
                (*assign)++;
            }
        }
        sumComps += *comps;
        sumAssign += *assign;
        printf("Pass-through %d: [", i + 1);
        for(int k = 0; k < n; k++){
            printf("%d ", b[k]);
        }
        printf("]\n");
        printf("Comps: %d, Assign: %d\n", *comps, *assign);
    }
    int totalSteps = sumComps + sumAssign;
    printf("Total Comps: %d, Total Assign: %d\n", sumComps, sumAssign);
    printf("Total steps: %d\n", totalSteps);
}

int main(){
    int arr[6] = {5, 1, 0, 5, 4, 0};
    int n = 6;
    int comps, assign;
    int b[6] = {0};
    f(arr, n, b, &comps, &assign);
    return 0;
}