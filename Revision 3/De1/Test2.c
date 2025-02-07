#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//tạo struct node 
typedef struct NodeType
{
    //node này sẽ lưu biến có kiểu dữ liệu char
    char character;
    struct NodeType *next;
}Node;
//tạo struct linkedlist
typedef struct LinkedListType{
    Node *head;
}LinkedList;
//tạo 1 node mới
Node* makeNode(char c){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->character = c;
    newNode->next = NULL;
    return newNode;
}
//khởi tạo linkedlist
void init(LinkedList *list){
    list->head = NULL;
}
void insert(char c, LinkedList *list, int k){
    Node *newNode = makeNode(c);
    //k = 0 có nghĩa là chèn vào đầu
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
void printLinkedList(LinkedList *list){
    Node *temp = list->head;
    while(temp != NULL){
        printf("%c", temp->character);
        temp = temp->next;
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
    char str[] = "DSATTHS12023";
    printf("Chuoi s: %s\n", str);
    for(int i = 0; i < strlen(str); i++){
        insert(str[i], &list, i);
    }
    printf("Chuoi duoc luu vao list: ");
    printLinkedList(&list);
    freeList(&list);
    return 0;
}