#include <stdio.h>
#include <stdlib.h>

//dinh nghia Node
typedef struct NodeType 
{
    int data;
    struct NodeType *next;
}Node;

//Dinh nghia Linked list
typedef struct LinkedListType{
    Node *head;
}LinkedList;

//Khoi tao linked list
void init(LinkedList *list){
    list->head = NULL;
}

//ham tao node moi
Node *makeNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Ham chen node moi vao dau danh sach
void insertHead(int data, LinkedList *list){
    Node *newNode = makeNode(data);
    newNode->next = list->head;
    list->head = newNode;
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

//Ham in linked list
void printList(LinkedList *list){
    Node *node = list->head;
    while(node != NULL){
        printf("Node address: %p | ", &(node->data));
        printf("data = %d| ", node->data);
        printf("next node address = %p\n", node->next);
        node = node->next;
    }
    printf("\n");
}
//ham xoa phan tu dau
void deleteHead(LinkedList *list){
    if(list->head == NULL){
        printf("List is empty\n");
        return;
    }
    Node *temp = list->head;
    list->head = temp->next;
    free(temp);
}
//ham xoa phan tu cuoi
void deleteEnd(LinkedList *list){
    if(list->head == NULL){
        printf("list is empty\n");
        return;
    }
    Node *temp = list->head;
    if(temp->next == NULL){
        free(temp);
        list->head = NULL;
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
//Ham main
int main(){
    LinkedList list;
    init(&list);
    int arr[] = {2, 12, 9, 0, 11, 3, 4, 8};
    int size = sizeof(arr) / sizeof(int);
    for(int i = size - 1; i >= 0; i--){
        insertHead(arr[i], &list);
    }
    insertHead(19, &list);
    insertEnd(-3, &list);
    deleteHead(&list);
    deleteEnd(&list);
    printList(&list);
    return 0;
}