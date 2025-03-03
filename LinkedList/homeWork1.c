#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType
{
    int data;
    struct NodeType *next;
}Node;

typedef struct LinkedListType
{
    Node *head;
}LinkedList;
//hàm khởi tạo linked list
void init(LinkedList *list){
    list->head = NULL;
}
//hàm tạo 1 node mới
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
//hàm xóa 1 node tại vị trí thứ k
void deleteAtIndex(LinkedList *list, int k){
    if(k == 0){
        Node *temp = list->head;
        list->head = temp->next;
        free(temp);
    }
    else{
        Node *currentNode = list->head;
        int currentIndex = 0;
        while(currentIndex < (k - 1)){
            currentNode = currentNode->next;
            currentIndex++;
        }
        Node *temp = currentNode->next;
        Node *nodeAfterDeletedNode = currentNode->next->next;
        currentNode->next = nodeAfterDeletedNode;
        free(temp);
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
    //nhập số lượng phần tử của danh sách
    int n; scanf("%d", &n);
    int arr[1000];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        insertAtIndex(arr[i], &linkedList, i);
    }
    //nhập data và vị trí cần chèn k1
    int data, k1;
    printf("nhap data va vi tri can chen: ");
    scanf("%d %d", &data, &k1);
    insertAtIndex(data, &linkedList, k1 - 1);
    printLinkedList(&linkedList);
    //nhập vị trí cần xóa
    printf("nhap vi tri can xoa: ");
    int k2; scanf("%d", &k2);
    deleteAtIndex(&linkedList, k2 - 1);
    printLinkedList(&linkedList);
    freeList(&linkedList);
    return 0;
}