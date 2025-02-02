#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minPos = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minPos]) {
                minPos = j;
            }
        }
        if(minPos != i){
            swap(&arr[i], &arr[minPos]);
        }
    }
}

int minTime(int times[], int N, int K) {
    SelectionSort(times, N);
    if (N <= K) {
        int maxTime = 0;
        for (int i = 0; i < N; i++) {
            if (times[i] > maxTime) {
                maxTime = times[i];
            }
        }
        return maxTime;
    }

    int total_time = 0;
    int current_index = N - 1;

    while (current_index >= 3) {
        int option1 = times[1] + times[0] + times[current_index] + times[1];
        int option2 = times[current_index] + times[current_index - 1] + 2 * times[0];
        if (option1 < option2) {
            total_time += option1;
        } else {
            total_time += option2;
        }
        current_index -= 2;
    }

    if (current_index == 2) {
        total_time += times[2] + times[1] + times[0];
    } else if (current_index == 1) {
        total_time += times[1];
    } else {
        total_time += times[0];
    }

    return total_time;
}

int main() {
    int k, n; scanf("%d %d", &k, &n);
    int arr[1000];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int shortestTime = minTime(arr, n, k);
    printf("%d", shortestTime);
    return 0;
}
