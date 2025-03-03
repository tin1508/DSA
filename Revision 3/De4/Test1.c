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

//hàm chèn node vào danh sách theo thứ tự tăng dần
void insertFollowAscendingOrder(LinkedList *list, int data){
    Node *newNode = makeNode(data);
    //nếu danh sách rỗng
    if(list->head == NULL){
        list->head = newNode;
        return;
    }
    //Nếu data <= list->head->data thì chèn vào đầu
    if(data <= list->head->data){
        newNode->next = list->head;
        list->head = newNode;
        return;
    }
    else{
        //Các trường hợp còn lại
        Node *currentNode = list->head;
        while(currentNode->next != NULL && currentNode->next->data <= data){
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        return;
    }
}
// hàm tìm tất cả các nodes có gtri nhỏ hơn value cho trc
void findNodesSmallerValue(LinkedList *list, int value, LinkedList *newList){
    if(list->head == NULL){
        printf("list is empty!");
        return;
    }
    Node *currentNode = list->head;
    Node *prev = NULL;
    while(currentNode != NULL){
        if(currentNode->data <= value){
            insertFollowAscendingOrder(newList, currentNode->data);
            //thực hiện xóa
            //nếu như node có gtri <= value là list->head
            if(currentNode == list->head){
                Node *temp = list->head;
                list->head = temp->next;
                free(temp);
                currentNode = list->head;
            }
            else{
                Node *temp = currentNode;
                currentNode = temp->next;
                prev->next = currentNode;
                free(temp);
            }
        }
        else{
            prev = currentNode;
            currentNode = currentNode->next;
        }
    }
    return;
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
    LinkedList list, newList;
    init(&list);
    init(&newList);
    int arr[] = {2, 7, 6, 3, 1, 4};
    int size = sizeof(arr) / sizeof(int);
    for(int i = 0; i < size; i++){
        insertAtIndex(arr[i], &list, i);
    }
    int value = 4;
    findNodesSmallerValue(&list, value, &newList);
    printf("list after delete node smaller value: ");
    printList(&list);
    printf("newlist: ");
    printList(&newList);
    freeList(&list);
    freeList(&newList);
    return 0;
}

