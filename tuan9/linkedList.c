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
//chèn 1 node vào vị trí thứ k bằng đệ quy
void insertAtIndexRecur(int data, Node **node, int k){
    if(k == 0){
        Node *newNode = makeNode(data);
        newNode->next = *node;
        *node = newNode;
    }
    else insertAtIndexRecur(data, &((*node)->next), k - 1);
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
//hàm xóa 1 node tại vị trí thứ k bằng đệ quy
void deleteAtIndexRecur(Node **node, int k){
    if(k == 0){
        Node *temp = *node;
        *node = temp->next;
        free(temp);
    }
    else{
        deleteAtIndexRecur(&((*node)->next), k - 1);
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
    LinkedList list;
    init(&list);
    int arr[] = {2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(int);
    for(int i = 0; i < size; i++){
        insertAtIndex(arr[i], &list, i);
    }
    insertAtIndexRecur(4, &(list.head), 3);
    printLinkedList(&list);
    freeList(&list);
    return 0;
}