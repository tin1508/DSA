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
    //Dùng để đếm số lượng phần tử trong list để đảm bảo ko vượt quá số lượng phần tử cho phép trong stack
    int count;
} LinkedList;
//hàm khởi tạo 1 danh sách 
void initLinkedList(LinkedList *list){
    list->head = NULL;
    list->count = 0;
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
    (list->count)++;
}
//hàm xóa cuối vì stack sẽ xóa những phần tử được thêm vào sau cùng trước
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
    (list->count)--;
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
} Stack;
//hàm khởi tạo 1 stack mới
void init(Stack *s){
    s->list = (LinkedList*)malloc(sizeof(LinkedList));
    initLinkedList(s->list);
}
//kiểm tra stack có trống không
int isEmpty(Stack *s){
    if(s->list->head == NULL){
        return 1;
    }
    else return 0;
}
//kiểm tra stack có đầy không
int isFull(Stack *s){
    if(s->list->count >= MAX){
        return 1;
    }
    else return 0;
}
//thêm phần tử vào stack
void push(Stack *s, int value){
    if(isFull(s)){
        printf("Stack is full!!!\n");
        return;
    }
    insertEnd(value, s->list);
}
//hàm xóa và lấy phần tử ra khỏi stack
int pop(Stack *s){
    if(isEmpty(s)){
        return -1;
    }
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
void freeStack(Stack *s){
    //Giải phóng bộ nhớ cho các node trong danh sách
    freeList(s->list);
    //Giải phóng bộ nhớ cho s.list (vì chúng ta cấp phát động trong hàm init)
    free(s->list);
}
int main(){
    Stack s;
    //khởi tạo 1 stack rỗng
    init(&s);
    //thêm phần tử vào stack
    int arr[] = {10, 23, 45, 87, 32, 5};
    int size = sizeof(arr) / sizeof(int);
    for(int i = 0; i < size; i++){
        printf("push %d: ", arr[i]);
        push(&s, arr[i]);
        displayStack(&s);
    }
    //xóa phần tử ra khỏi stack đến khi nào stack trống
    while(!isEmpty(&s)){
        printf("%d popped from stack\n", pop(&s));
    }
    //giải phóng bộ nhớ cho stack
    freeStack(&s);
    return 0;
}
//Nhận định về việc sử dụng stack trên 2 cấu trúc dữ liệu: mảng và danh sách liên kết đơn
/*
Khi sử dụng Mảng:
-Ưu điểm: + giúp chúng ta truy cập vào phần tử đó nhanh hơn nhờ vào truy vấn index trực tiếp.
+ Ngắn gọn và dễ cài đặt hơn danh sách liên kết đơn.
+ Tiết kiệm bộ nhớ hơn nếu biết trước kích thước tối đa của Stack.
-Nhược điểm: + Nếu chúng ta ko biết trước kích thước tối đa thì sẽ là bất lợi khi sử dụng mảng vì mảng là kích thước cố định dễ đẫn đến tràn bộ nhớ (stack overflow).
+ Nếu kích thước stack thay đổi thì việc mở rộng mảng tăng kích thước mảng sẽ tốn kém hơn về mặt thời gian.
Khi sử dụng dskk đơn
-Ưu điểm: + Kích thước linh hoạt: vì chúng ta cấp phát động bộ nhớ nên có thể thay đổi kích thước động, ko giới hạn kích thước ban đầu.
+ Không tốn thời gian mở rộng như mảng khi thay đổi kích thước stack.
-Nhược điểm: + truy cập chậm hơn mảng: vì ko dùng index trực tiếp được
+ Tốn bộ nhớ hơn mảng vì mỗi phần tử trong dslk đơn phải lưu trữ thêm con trỏ.
*/