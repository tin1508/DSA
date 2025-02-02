#include <stdio.h>
#include <stdlib.h>
typedef struct NodeType{
    int data;
    struct NodeType *next;
} Node;
typedef struct LinkedListType{
    Node *head;
} LinkedList;

void init(LinkedList *list){
    list->head = NULL;
}
Node *makeNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//chèn 1 node vào vị trí thứ k
void insertAtIndex(int data, LinkedList *list, int k){
    Node *newNode = makeNode(data);
    if(k == 0){
        newNode->next = list->head;
        list->head = newNode;
    }
    else{
        Node *currentNode = list->head;
        int currentIndex = 0;
        while(currentIndex < (k - 1)){
            currentNode = currentNode->next;
            currentIndex++;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
}
//hàm chèn data sao cho danh sách có thứ tự giảm dần
void insert(LinkedList *list, int data){
    Node *newNode = makeNode(data);
    if(list->head == NULL){
        list->head = newNode;
        return;
    }
    //Nếu data >= data của nút đầu thì chèn vào đầu
    if(list->head->data <= data){
        newNode->next = list->head;
        list->head = newNode;
    }
    else{
        Node *temp = list->head;
        //duyệt đến khi nào tìm được 1 nút có data < hơn data của newNode hoặc có trường hợp sễ cần chèn vào cuối
        while(temp->next->data >= data && temp->next->next != NULL){
            temp = temp->next;
        }
        //Đây là trường hợp chèn vào cuối
        if(temp->next->next == NULL){
            temp->next->next = newNode;
            newNode->next = NULL;
        }
        //Trường hợp còn lại
        else{
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
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
int main(){
    LinkedList linkedList;
    init(&linkedList);
    printf("nhap so phan tu: ");
    int n; scanf("%d", &n);
    int arr[1000];
    printf("nhap danh sach giam dan: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        insertAtIndex(arr[i], &linkedList, i);
    }
    printf("nhap data can chen: ");
    int data; scanf("%d", &data);
    insert(&linkedList, data);
    printLinkedList(&linkedList);
    return 0;
}