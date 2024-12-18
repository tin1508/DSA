#include <stdio.h>
#include <stdlib.h>

#define MAX 5

//Implement queue in C
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
        printf("Queue is full\n");
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

int main(){
    //queue
    Queue q;
    init(&q);
    int num[6] = {1,-2,3,-4,5,-6};
    // push
    printf("MAX = %d\n\n", MAX);
    printf("PUT\n");
    for (int i = 0; i < 6; i++){
        printf("put %d: \n",num[i]);
        if(!isFull(&q)){
            put(&q,num[i]);
            displayQueue(&q);
            printf("\n");
        }
        else
            printf("Queue is full. \n\n");
    }
    // get
    printf("GET\n");
    int i = 0;
    while (!isEmpty(&q)) {
        printf("get %d: %d\n", i, get(&q));
        displayQueue(&q);
        i++;
        printf("\n");
    }
    return 0;
}