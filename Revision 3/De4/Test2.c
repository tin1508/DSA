#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType
{
    int data;
    struct NodeType *next;
}Node;

typedef struct LinkedListType{
    Node *head;
}LinkedList;

//khởi tạo linked list
void init(LinkedList *list){
    list->head = NULL;
}
//hàm tạo 1 node mới 
Node* makeNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//hàm chèn node mới vào danh sách ở vị trí index bất kì
void insertAtIndex(int data, LinkedList *list, int index){
    Node *newNode = makeNode(data);
    //TH chèn vào đầu
    if(index == 0){
        newNode->next = list->head;
        list->head = newNode;
    }
    else{
        //TH chèn vào vị trí index bất kì
        Node *currentNode = list->head;
        int currentIndex = 0;
        while(currentIndex < (index - 1)){
            currentNode = currentNode->next;
            currentIndex++;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
}
//Quy trình 4 bước
//Base case: node->next == NULL
//Result of Base Case: getTail(node->next = NULL) = node ở cuối cùng của danh sách
//Before base case: getTail(node->next->next = NULL): node ở trước node cuối cùng
//Before before:  getTail(node->next->next->next = NULL): node ở trước trước node cuối cùng

//Ví dụ với danh sách cụ thể: 2 -> 7 -> 6 -> 3 -> 1 -> 4 -> NULL
//Base case: 4->next == NULL
//Result of base case: getTail(4) = 4 (node ở cuối danh sách)
//Before base case: getTail(1): cũng trả về node 4 vì getTail(1) = getTail(1->next) = getTail(4)
//Before before:  getTail(3): cũng trả về node 4 vì getTail(3) = getTail(3->next) = getTail(1) = getTail(1->next) = getTail(4)
Node *getTail(Node *node){
    if(node->next == NULL) return node;
    return getTail(node->next);
}
// in danh sách 
void printList(LinkedList *list){
    Node *node = list->head;
    while(node != NULL){
        printf("%d ", node->data);
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
    int arr[] = {2, 7, 6, 3, 1, 4};
    int size = sizeof(arr) / sizeof(int);
    for(int i = 0; i < size; i++){
        insertAtIndex(arr[i], &list, i);
    }
    printList(&list);
    Node *lastNode = getTail(list.head);
    printf("node address: %p\n", &(lastNode->data));
    printf("data: %d\n", lastNode->data);
    printf("next node address: %p\n", lastNode->next);
    freeList(&list);
    return 0;
}