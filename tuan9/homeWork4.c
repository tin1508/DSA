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
//chèn 1 node vào vị trí thứ k bằng đệ quy
void insertAtIndexRecur(int data, Node **node, int k){
    //để cho thuận tiện khi thay đổi trực tiếp con trỏ của ds liên kết list->head thì ở đây sẽ dử dụng con trỏ cấp 2 để lưu địa chỉ list->head
    if(k == 0){
        Node *newNode = makeNode(data);
        newNode->next = *node;
        *node = newNode;
        return;
    }
    insertAtIndexRecur(data, &((*node)->next), k - 1);
}
//Quy trình 4 bước của hàm insertAtIndexRecur
//Base case: k = 0
//Lấy ví dụ danh sách 2->3->4->5->6->7 với data = 1 và k = 3
//Result of base case: danh sách với nút được chèn ở vị trí k, với ví dụ trên thì kết quả là: 2->3->1->4->5->6->7
//Before base case: k = 1, (*node)->data = ((list->head)->next)->next->data = 3, 2->3->
//Before before: k = 2, (*node)->data = (list->head)->next->data = 2, 2->

//hàm xóa 1 node tại vị trí thứ k bằng đệ quy
void deleteAtIndexRecur(Node **node, int k){
    //để cho thuận tiện khi thay đổi trực tiếp con trỏ của ds liên kết list->head thì ở đây sẽ dử dụng con trỏ cấp 2 để lưu địa chỉ list->head
    if(k == 0){
        Node *temp = *node;
        *node = temp->next;
        free(temp);
        return;
    }
    deleteAtIndexRecur(&((*node)->next), k - 1);
}
//Quy trình 4 bước của hàm deleteAtIndexRecur
//Base case: k = 0
//Lấy ví dụ danh sách 2->3->4->5->6->7 với k = 3
//Result of base case: danh sách với nút được xóa ở vị trí k, với ví dụ trên thì kết quả là: 2->3->4->5->6->7
//Before base case: k = 1, (*node)->data = ((list->head)->next)->next->data = 3, 2->3->
//Before before: k = 2, (*node)->data = (list->head)->next->data = 2, 2->

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
    printf("nhap so phan tu: ");
    int n; scanf("%d", &n);
    int arr[1000];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        insertAtIndexRecur(arr[i], &(linkedList.head), i);
    }
    //nhập vị trí cần chèn
    int data, k1;
    printf("nhap data va vi tri can chen: ");
    scanf("%d %d", &data, &k1);
    insertAtIndexRecur(data, &(linkedList.head), k1 - 1);
    printLinkedList(&linkedList);
    //nhập vị trí cần xóa
    printf("nhap vi tri can xoa: ");
    int k2; scanf("%d", &k2);
    deleteAtIndexRecur(&(linkedList.head), k2 - 1);
    printLinkedList(&linkedList);
    freeList(&linkedList);
    return 0;
}