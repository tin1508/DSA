#include <stdio.h>
#include <stdlib.h>

//Cài đặt linked list
typedef struct NodeType
{
    int data;
    struct NodeType *next;
}Node;
typedef struct LinkedListType{
    Node *head;
}LinkedList;
//khởi tạo linked list
void initList(LinkedList *list){
    list->head = NULL;
}
//hàm tạo 1 node mới 
Node* makeNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
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
//Cài đặt cây nhị phân
typedef struct NodeTreeType {
    int data;
    struct NodeTreeType* left, * right;
} TreeNode;

typedef struct BinaryTreeType{
    TreeNode * root;
} BinaryTree;

TreeNode* makeTreeNode(int data){
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
//init binarytree
void initTree(BinaryTree* tree) {
    tree->root=NULL;
}
//in cây theo thứ tự duyệt trước - preorder (root - left - right) (DFS)
void printTreePreorder(TreeNode* node) {
    if(node == NULL) return;
    printf("%d ", node->data);
    printTreePreorder(node->left);
    printTreePreorder(node->right);
}
//Giải phóng bộ nhớ của cây
void freeTree(TreeNode *node){
    if(node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}
//Hàm kiểm tra node đó có phải node lá ko
int isLeaf(TreeNode *node){
    if(node->left == NULL && node->right == NULL) return 1;
    else return 0;
}
//Tạo hàm sao chép các phần tử ở nút lá của cây nhị phân vào dslk theo thứ tự tăng dần
void copyLeafNodeToLinkedList(TreeNode *node, LinkedList *list){
    if(node == NULL) return;
    copyLeafNodeToLinkedList(node->left, list);
    copyLeafNodeToLinkedList(node->right, list);
    if(isLeaf(node)){
        insertFollowAscendingOrder(list, node->data);
    }
    return;
}
int main(){
    BinaryTree tree;
    initTree(&tree);
    tree.root = makeTreeNode(1);
    //cây left
    tree.root->left = makeTreeNode(2);
    tree.root->left->left = makeTreeNode(4);
    tree.root->left->right = makeTreeNode(5);
    tree.root->left->left->left = makeTreeNode(8);
    tree.root->left->left->right = makeTreeNode(9);
    tree.root->left->right->left = makeTreeNode(10);
    tree.root->left->right->right = makeTreeNode(11);
    //cây right
    tree.root->right = makeTreeNode(3);
    tree.root->right->left = makeTreeNode(6);
    tree.root->right->right = makeTreeNode(7);
    tree.root->right->left->left = makeTreeNode(12);
    tree.root->right->left->right = makeTreeNode(13);
    tree.root->right->right->left = makeTreeNode(14);
    tree.root->right->right->right = makeTreeNode(15);
    printf("Cay nhi phan: ");
    printTreePreorder(tree.root);
    printf("\n");
    LinkedList list;
    initList(&list);
    copyLeafNodeToLinkedList(tree.root, &list);
    printf("danh sach sau khi sao chep nut la: ");
    printLinkedList(&list);
    freeList(&list);
    freeTree(tree.root);
    return 0;
}