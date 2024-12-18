#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int a, int *comps){
    if(a < 2) return 0;
    *comps = 0;
    for(int i = 2; i <= sqrt(a); i++){
        (*comps)++;
        if(a % i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    time_t t;
    srand((unsigned)time(&t));
    int min = 1, max = 10000;
    int a, comps;
    double  AverageComps[1001];
    int CompsQuant[1001], aQuant[1001];
    double average = 0;
    for(int i = 1; i <= 1000; i++){
        a = min + rand() % (max - min + 1);
        int check = isPrime(a, &comps);
        AverageComps[i] = (double) comps / a;
        average += AverageComps[i];
        CompsQuant[i] = comps;
        aQuant[i] = a;
    }
    printf("Pass-through \t Comparisons \t a \t Average\n");
    for(int i = 1; i <= 1000; i++){
        printf("%d \t\t %d \t\t %d \t\t %.2f\n", i, CompsQuant[i], aQuant[i], AverageComps[i]);
    }
    //tổng kết thuật toán
    average /= (double) 1000;
    printf("Final Conclusion: Average is %.2f\n", average);
    return 0;
}