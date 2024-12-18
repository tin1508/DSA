#include <stdio.h>
#include <stdlib.h>

#define MAX 7

typedef struct Queue_type
{
    int head, tail;
    int arr[MAX];

} CircularQueue;

void init(CircularQueue *q){
    q->head = -1;
    q->tail = -1;
}

int isEmpty(CircularQueue *q){
    if(q->head == -1) return 1;
    return 0;                                                                                                       
}
int isFull(CircularQueue *q){
    if(q->tail == MAX - 1 && q->head == 0){
        return 1;
    }
    else if(q->tail != -1 && q->tail < q->head){
        if((MAX - q->head) + q->tail == MAX - 1){
            return 1;
        }
    }
    return 0;
}
void put(CircularQueue *q, int value){
    if(isFull(q)){
        printf("CircularQueue is full\n");
        return;
    }
    if(q->head == -1){
        (q->head)++;
    }
    if(q->tail == MAX - 1){
        q->tail = -1;
    }
    (q->tail)++;
    q->arr[q->tail] = value;
}

int get(CircularQueue *q){
    if(isEmpty(q)){
        return 0;
    }
    int element = q->arr[q->head];
    if(q->head == MAX - 1){
        q->head = -1;
    }
    (q->head)++;
    if(q->head == q->tail + 1){
        q->head = -1;
    }
    return element;
}

void displayQueue(CircularQueue *q){
    if(isEmpty(q)){
        printf("Circular Queue is Empty!!\n");
        return;
    }
    if(q->head <= q->tail){
        for(int i = q->head; i <= q->tail; i++){
            printf("%d ", q->arr[i]);
        }
    }
    else{
        int i = q->head;
        while(i != q->tail){
            printf("%d ", q->arr[i]);
            if(i == MAX - 1){
                i = -1;
            }
            i++;
        }
        printf("%d ", q->arr[i]);
    }
    return;
}
int main(){
    //CircularQueue
    CircularQueue q;
    init(&q);
    int num[7]  = {-5, 2, 4, -3, 1, 0, 9};
    printf("MAX = %d\n\n", MAX);
    printf("PUT\n");
    for(int i = 0; i < 7; i++){
        printf("put %d: \n",num[i]);
        if(!isFull(&q)){
            put(&q,num[i]);
            displayQueue(&q);
            printf("\n");
        }
        else
            printf("Circular Queue is full. \n\n");
    }
    //get
    printf("GET\n");
    int i = 0;
    while(i < 5){
        printf("get %d: %d\n", i, get(&q));
        displayQueue(&q);
        i++;
        printf("\n");
    }
    //put
    int num1[3] = {8, 4, -3};
    printf("PUT\n");
    for(int k = 0; k < 3; k++){
        printf("put %d: \n",num1[k]);
        if(!isFull(&q)){
            put(&q,num1[k]);
            displayQueue(&q);
            printf("\n");
        }
        else
            printf("Circular Queue is full. \n\n");
    }
    //get
    printf("GET\n");
    int j = 0;
    while(j < 3){
        printf("get %d: %d\n", j, get(&q));
        displayQueue(&q);
        j++;
        printf("\n");
    }
    return 0;
}
