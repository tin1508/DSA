#include <stdio.h>
#include <stdlib.h>

//Kích thước giới hạn cho stack
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
//hàm xóa cuối
int deleteEnd(LinkedList *list){
    Node *temp = list->head;
    int deletedData;
    if(temp->next == NULL){
       deletedData = temp->data;
       free(temp);
       list->head = NULL;
    }
    else{
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        deletedData = temp->next->data;
        free(temp->next);
        temp->next = NULL;
    }
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
//Cài đặt cấu trúc stack
typedef struct Stack_type
{
    LinkedList *list;
    //biến top dùng để kiểm tra stack rỗng hay đầy và lưu chỉ số index của phần tử top
    int top;
} Stack;
//hàm khởi tạo 1 stack mới
void init(Stack *s){
    s->top = -1;
    initLinkedList(s->list);
}
//kiểm tra stack có trống không
int isEmpty(Stack *s){
    if(s->top == -1){
        return 1;
    }
    else return 0;
}
//kiểm tra stack có đầy không
int isFull(Stack *s){
    if(s->top == MAX - 1){
        return 1;
    }
    else return 0;
}
//thêm phần tử vào stack
void push(Stack *s, int value){
    if(isFull(s)){
        printf("Stack is full!\n");
        return;
    }
    s->top++;
    insertEnd(value, s->list);
}
//hàm xóa và lấy phần tử ra khỏi stack
int pop(Stack *s){
    if(isEmpty(s)){
        return s->top;
    }
    (s->top)--;
    return deleteEnd(s->list);
}
//in stack ra màn hình
void displayStack(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty!!!\n");
    }
    else{
        printLinkedList(s->list);
    }
}
int main(){
    Stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    displayStack(&s);
    while(!isEmpty(&s)){
        printf("%d popped from stack\n", pop(&s));
    }
    return 0;
}