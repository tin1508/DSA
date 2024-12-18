#include <stdio.h>

void binarySearch(int arr[], int n, int k, int *comps){
    int l = 0, r = n - 1;
    int sumComps = 0;
    int i = 0;
    printf("Initial array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    while(l <= r){
        *comps = 0;
        int m = (l + r) / 2;
        printf("\nleft: %d, right: %d\n", arr[l], arr[r]);
        if(arr[m] == k){
            (*comps)++;
            return ;
        }
        else if(arr[m] > k){
            (*comps)++;
            r = m - 1;
        }
        else{
            (*comps)++;
            l = m + 1;
        }
        printf("pass-through %d: ", i + 1);
        for(int j = l; j <= r; j++){
            printf("%d ", arr[j]);
        }
        printf(" - Comps's steps: %d", *comps);
        i++;
        sumComps += *comps;
        // if(l == r){
        //     for(int j = l; j < r; j++){
        //         printf("%d ", arr[j]);
        //     }
        //     printf("ComSteps: %d", *comps);
        // }
    }
    for(int i = l; i < r; i++){
        printf("%d ", arr[i]);
    }
    printf("\nTotal comps's steps is: %d", sumComps);
    return;
}
int main(){
    int arr[] = {1, 2, 7, 19, 23, 24, 28, 37, 49, 55, 122, 124};
    int n = sizeof(arr) / sizeof(int);
    int k = 2;
    int comps;
    binarySearch(arr, n, k, &comps);
    return 0;
}

// void swap(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// // //bubble sort algorithm
// // void bubbleSort(int arr[], int n, int *comps, int *swaps){
// //     int totalComps = 0, totalSwaps = 0, totalSteps = 0;
// //     printf("Initial Array: [");
// //     for(int i = 0; i < n; i++){
// //         printf("%d ", arr[i]);
// //     }
// //     printf("]\n");
// //     for(int i = 0; i < n; i++){
// //         *comps = 0, *swaps = 0;
// //         for(int j = 0; j < n - i - 1; j++){
// //             (*comps)++;
// //             if(arr[j] > arr[j + 1]){
// //                 swap(&arr[j], &arr[j + 1]);
// //                 (*swaps)++;
// //             }
// //         }
// //         printf("pass-through %d: [", i + 1);
// //         for(int k = 0; k < n; k++){
// //             printf("%d ", arr[k]);
// //         }
// //         printf("]\nComparison's steps: %d, Swaps's steps: %d, Assign's step: %d\n",*comps, *swaps);
// //         totalComps += *comps;
// //         totalSwaps += *swaps;
// //     }
// //     printf("Array is sorted: ");
// //     for(int i = 0; i < n; i++){
// //         printf("%d ", arr[i]);
// //     }
// //     totalSteps = totalComps + totalSwaps;   
// //     printf("\nTotal comparison: %d, Total swaps: %d\n", totalComps, totalSwaps);
// //     printf("Total steps: %d", totalSteps);
// // }
// //selection sort
// void selectionSort(int arr[], int n, int *comps, int *swaps){
//     int totalComps = 0, totalSwaps = 0, totalSteps = 0;
//     printf("Initial Array: [");
//     for(int i = 0; i < n; i++){
//         printf("%d ", arr[i]);
//     }
//     printf("]\n");
//     for(int i = 0; i < n; i++){
//         *comps = 0; *swaps = 0;
//         int min_pos = i; 
//         for(int j = i + 1; j < n; j++){
//             (*comps)++;
//             if(arr[j] < arr[min_pos]){
//                 min_pos = j;
//             }
//         }
//         if(i != min_pos){
//             swap(&arr[i], &arr[min_pos]);
//             (*swaps)++;
//         }
//         totalComps += *comps;
//         totalSwaps += *swaps;
//         printf("Pass-through %d: [", i + 1);
//         for(int j = 0; j < n; j++){
//             printf("%d ", arr[j]);
//         }
//         printf("] - Comps: %d, swaps: %d, assign: %d\n", *comps, *swaps);
//     }
//     printf("Array is sorted: ");
//     for(int i = 0; i < n; i++){
//         printf("%d ", arr[i]);
//     }
//     totalSteps = totalComps + totalSwaps;
//     printf("\nTotal comps: %d, total swaps: %d", totalComps, totalSwaps);
//     printf("\nTotal steps: %d", totalSteps);

// }
// // //insertion sort
// void insertionSort(int arr[], int n, int *comps, int *shift){
//     printf("Initial Array: [");
//     for(int i = 0; i < n; i++){
//         printf("%d ", arr[i]);
//     }
//     printf("]\n");
//     int sumComps = 0, sumShift = 0, sumSteps = 0;
//     for(int i = 1; i < n; i++){
//         int pos = i - 1, temp_value = arr[i];
//         *comps = 1, *shift = 0;
//         while(pos >= 0 && arr[pos] > temp_value){
//             arr[pos + 1] = arr[pos];
//             (*shift)++;
                // if(pos != 0){
                //     (*comps)++;
                // }
//             --pos;
//             
//         }
//         arr[pos + 1] = temp_value; 
//         printf("Pass-through %d: [", i);
//         for(int j = 0; j < n; j++){
//             printf("%d ", arr[j]);
//         }
//         printf("] - Comps: %d, shift: %d\n", *comps, *shift);
//         sumComps += *comps;
//         sumShift += *shift;
//     }
//     printf("Array is sorted: ");
//     for(int i = 0; i < n; i++){
//         printf("%d ", arr[i]);
//     }
//     sumSteps = sumComps + sumShift;
//     printf("\ntotal comps: %d, total shift: %d\n", sumComps, sumShift);
//     printf("Total steps: %d", sumSteps);
// }

// int main(){
//     int array[10] = {2, 9, 3, 1, 4, 5, 8, 7, 3, 0};
//     int comps, swaps, shift;
//     //bubbleSort(array, 10, &comps, &swaps);
//     insertionSort(array, 10, &comps, &shift);
//     //selectionSort(array, 10, &comps, &swaps);

//     return 0;
// }
/*
void f(int a[], int n, int b[], int *comps, int *assign)
{
    for (int i = 0; i < n; i++)
    {
        *comps = 0, *assign = 0;
        for (int j = 0; j < n; j++)
        {
            (*comps)++;
            if (a[i] == a[j])
            {
                (*assign)++;
                b[a[i]]++;
            }
        }
        printf("Pass-through %d: [", i + 1);
    }
}

int main(){
    int a[] = {5, 1, 0, 5, 4, 0};
    int n = sizeof(a) / sizeof(int);
    int b[10];
    int comps, assign;
    f(a, n, b, &comps, &assign);
    return 0;
}
*/