#include <stdio.h>
#include <stdlib.h>
//Kích thước giới hạn cho queue
#define MAX 1000
//Cài đặt danh sách liên kết đơn
typedef struct NodeType{
    int data;
    struct NodeType *next;
} Node;
typedef struct LinkedListType{
    Node *head;
} LinkedList;
//hàm khởi tạo 1 danh sách 
void initLinkedList(LinkedList *list){
    list->head = NULL;
}
//hàm tạo 1 node mới
Node *makeNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//chen cuoi
void insertEnd(int data, LinkedList *list){
    Node *newNode = makeNode(data);
    if(list->head == NULL){
        list->head = newNode;
        return;
    }
    Node *temp = list->head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
//hàm xóa đầu
int deleteHead(LinkedList *list){
    Node *temp = list->head;
    int deletedData = temp->data;
    list->head = temp->next;
    free(temp);
    return deletedData;
}
//hàm để in danh sách liên kết
void printLinkedList(LinkedList *list){
    Node *node = list->head;
    while(node != NULL){
        // printf("Node address: %p | ", &(node->data));
        printf("%d ", node->data);
        // printf("next node address = %p\n", node->next);
        node = node->next;
    }
    printf("\n");
}
//hàm giải phóng bộ nhớ cho danh sách liên kết
void freeList(LinkedList *list){
    Node *curr = list->head;
    while(curr != NULL){
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
}
//Cài đặt cấu trúc queue
typedef struct Queue_type{
    LinkedList *list;
    int head, tail;
} Queue;
//hàm khởi tạo 1 queue mới
void init(Queue* q)
{
    q->head = 0;
    q->tail = -1;
    initLinkedList(q->list);
}
//kiểm tra queue có trống không
int isEmpty(Queue* q) {
    if(q->tail < q->head){
        return 1;
    }
    else return 0;
}
//kiểm tra queue có đầy không
int isFull(Queue* q) { 
    if(q->tail == MAX - 1){
        return 1;
    }
    else return 0;
}
//thêm phần tử vào queue
void put(Queue* q, int value)
{
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    (q->tail)++;
    insertEnd(value, q->list);
}
//lấy phần tử ra khỏi queue
int get(Queue* q)
{
    if(isEmpty(q)){
        return -1;
    }
    int element = deleteHead(q->list);
    q->head++;
    return element;
}
//in queue ra màn hình
void displayQueue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty!!!\n");
    }
    else{
        printLinkedList(q->list);
    }
}
int main(){
    Queue q;
    init(&q);
    put(&q, 10);
    put(&q, 20);
    put(&q, 30);
    displayQueue(&q);
    while(!isEmpty(&q)){
        printf("%d gotten from queue\n", get(&q));
    }
    return 0;
}