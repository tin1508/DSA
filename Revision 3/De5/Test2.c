#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef struct NodeType
{
    //Mỗi node của danh sách liên kết sẽ có lưu tọa độ của điểm trong ko gian thực 2 chiều
    double x, y;
    //tính khoảng cách điểm đến tâm O
    double distance;
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
Node *makeNode(double x, double y){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->distance = sqrt(x*x + y*y);
    newNode->next = NULL;
    return newNode;
}
//chèn node vào danh sách liên kết theo thứ tự tăng dần
void insertFollowAscendingOrder(LinkedList *list, double x, double y){
    Node *newNode = makeNode(x, y);
    //TH nếu danh sách rỗng
    if(list->head == NULL){
        list->head = newNode;
        return;
    }
    //Trường hợp nếu distance này nhỏ hơn hoặc bằng distance của điểm đầu trog danh sách
    if(newNode->distance <= (list->head)->distance){
        newNode->next = list->head;
        list->head = newNode;
        return;
    }
    else{
        Node *currentNode = list->head;
        while(currentNode->next != NULL && currentNode->next->distance <= newNode->distance){
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        return;
    }
}
//in danh sách
void printList(LinkedList *list){
    Node *node = list->head;
    while(node != NULL){
        printf("%.2lf-%.2lf ", node->x, node->y);
        node = node->next;
    }
    printf("\n");
}
//Hàm giải phóng bộ nhớ cho danh sách lket 
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
    double arr[MAX][2];
    //5 điểm
    int n = 5;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            scanf("%lf", &arr[i][j]);
        }
    }
    //duyệt mảng để tạo 1 danh sách liên kết theo thứ tự tăng dần từ mảng điểm
    for(int i = 0; i < n; i++){
        insertFollowAscendingOrder(&list, arr[i][0], arr[i][1]);
    }
    printList(&list);
    freeList(&list);
    return 0;
}