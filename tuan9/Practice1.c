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
    list->head = list->head->next;
    free(temp);
}
//Ham main
int main(){
    LinkedList list;
    init(&list);
    //Tao danh sach tu dong
    for(int i = 0; i < 10; i++){
        insertHead(i, &list);
    }
    //them 15 vao dau danh sach
    insertHead(15, &list);
    //xoa phan tu dau khoi danh sach
    deleteHead(&list);
    //In danh sach
    printList(&list);
    return 0;
}