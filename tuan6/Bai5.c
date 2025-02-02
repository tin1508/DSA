#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
//setup queue
//Implement queue
typedef struct Queue_type{
    int head, tail;
    int a[MAX];
} Queue;
void init(Queue* q)
{
    q->head = 0;
    q->tail = -1;
}
int isEmpty(Queue* q) {
    if(q->tail < q->head){
        return 1;
    }
    else return 0;
}
int isFull(Queue* q) { 
    if(q->tail == MAX - 1){
        return 1;
    }
    else return 0;
}
void put(Queue* q, int value)
{
    if (isFull(q)) {
        //printf("Queue is full\n");
        return;
    }
    (q->tail)++;
    q->a[q->tail] = value;
}
int get(Queue* q)
{
    if(isEmpty(q)){
        return -1;
    }
    int element = q->a[q->head];
    q->head++;
    return element;
}
void displayQueue(Queue* q)
{
    if(isEmpty(q)){
        printf("Queue is Empty!!");
        return;
    }
    for(int i = q->head; i <= q->tail; i++){
        printf("%d ", q->a[i]);
    }
    return;
}
//hàm swaps 2 số nguyên
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//cài đặt hàm selectionSort để sắp xếp thời gian
void selectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int minPos = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minPos]){
                minPos = j;
            }
        }
        if(minPos != i){
            swap(&arr[i], &arr[minPos]);
        }
    }
}
//hàm tìm thời gian tối thiếu để tất cả qua cầu
int shortestTime(int times[], int n, int k){
    //sắp xếp lại mảng thời gian
    selectionSort(times, n);
    Queue q;
    init(&q);
    int minTime = 0;
    for(int i = 0; i < n; i++){
        if(q.tail - q.head < k - 1){
            put(&q, times[i]);
        }
        else if(q.tail - q.head == k - 1){
            int temp = get(&q);
            minTime += temp;
            for(int j = q.head; j <= q.tail; j++){
                q.a[j] -= temp;
            }
            put(&q, times[i]);
        }
    }
    //cộng thời gian 
    while(isEmpty(&q) == 0){
        int temp = get(&q);
        minTime += temp;
        for(int j = q.head; j <= q.tail; j++){
            q.a[j] -= temp;
        }
    }
    return minTime;
}
int main(){
    int k, n; scanf("%d %d", &k, &n);
    int times[MAX];
    for(int i = 0; i < n; i++){
        scanf("%d", &times[i]);
    }
    int result = shortestTime(times, n, k);
    printf("%d", result);
    return 0;
}