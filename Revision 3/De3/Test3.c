#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType
{   
    int data;
    struct NodeType *left, *right;
}TreeNode;
typedef struct TreeType
{
    TreeNode *root;
}BinaryTree;
//Khoi tao tree
void init(BinaryTree *tree){
    tree->root = NULL;
}
//Tao 1 node moi
TreeNode* makeNode(int data){
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
//Ham giai phong bo nho cho cay sau khi su dung
void freeTree(TreeNode *node){
    if(node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}
//in cây theo thứ tự duyệt trước - preorder (root - left - right) (DFS)
void printTreePreorder(TreeNode* node) {
    if(node == NULL) return;
    printf("%d ", node->data);
    printTreePreorder(node->left);
    printTreePreorder(node->right);
}
//Ham tim kiem value trong cay
TreeNode* search(BinaryTree *tree, int value){
    TreeNode *temp = tree->root;
    while(temp != NULL){
        if(value == temp->data){
            return temp;
        }
        else if(value > temp->data) temp = temp->right;
        else temp = temp->left;
    }
    return NULL;
}
//hàm xóa node 
void deleteNode(BinaryTree *tree, int value){
    TreeNode *deletedNode = search(tree, value);
    //TH nếu ko có nút xóa
    if(deletedNode == NULL){
        printf("value is not found in Binary tree!!\n");
        return;
    }
    //Tìm nút cha của nút cần xóa
    TreeNode *curr = tree->root;
    TreeNode *parent = NULL;
    while(curr != deletedNode){
        parent = curr;
        if(parent->data > value) curr = curr->left;
        else curr = curr->right;
    }
    //TH1: nút cần xóa ko có nút con hay nút cần xóa là nút lá
    if(curr->left == NULL && curr->right == NULL){
        if(parent == NULL) tree->root = NULL;
        else if(parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
    }
    //TH2: nút cần xóa chỉ có 1 nút con bên trái
    else if(curr->left != NULL && curr->right == NULL){
        if(parent == NULL) tree->root = curr->left;
        else if(parent->left == curr) parent->left = curr->left;
        else parent->right = curr->left;
    }
    //TH3: nút cần xóa chỉ có 1 nút con bên phải
    else if(curr->left == NULL && curr->right != NULL){
        if(parent == NULL) tree->root = curr->right;
        else if(parent->left == curr) parent->left = curr->right;
        else parent->right = curr->right;
    }
    //TH4: nút cần xóa có 2 nút con
    else if(curr->left != NULL && curr->right != NULL){
        //tìm node lớn nhất bên con trái của node cần xóa -> tìm node phải nhất của con trái node cần xóa
        curr = deletedNode->left, parent = NULL;
        while(curr->right != NULL){
            parent = curr;
            curr = curr->right;
        }
        //Gán node cần xóa bằng node vừa tìm được
        deletedNode->data = curr->data;
        //xóa curr
        if(parent == NULL) deletedNode->left = curr->left;
        else parent->right = curr->left;
    }
    free(curr);
}
//Xóa tất cả các số nguyên lẻ(trừ root) trên cây nhị phân nhập vào
// Hàm xóa tất cả các số âm (trừ root) trên cây nhị phân
// Xóa tất cả các số nguyên âm (trừ root) trên cây nhị phân
void deleteAllNegativeNumbersInTree(BinaryTree* tree) {
    if (tree->root == NULL) return;
    // Initialize a queue of TreeNode
    TreeNode* q[1000];
    int head = 0, tail = -1;
    if (tree->root->left != NULL) {
        tail++;
        q[tail] = tree->root->left;
    }
    if (tree->root->right != NULL) {
        tail++;
        q[tail] = tree->root->right;
    }
    while (head <= tail) {
        TreeNode* temp = q[head];
        head++;
        if (temp->left != NULL) {
            tail++;
            q[tail] = temp->left;
        }
        if (temp->right != NULL) {
            tail++;
            q[tail] = temp->right;
        }
        // Check if the node contains a negative number
        if ((temp->data) < 0) {
            deleteNode(tree, temp->data);
        }
    }
}
int main(){
    BinaryTree tree;
    init(&tree);
    tree.root = makeNode(-5);
    //cây left
    tree.root->left = makeNode(-8);
    tree.root->left->left = makeNode(-10);
    tree.root->left->right = makeNode(-7);
    //cay right
    tree.root->right = makeNode(3);
    tree.root->right->left = makeNode(-2);
    tree.root->right->left->left =  makeNode(-4);
    tree.root->right->left->right = makeNode(-1);
    printTreePreorder(tree.root);
    printf("\n");
    deleteAllNegativeNumbersInTree(&tree);
    printTreePreorder(tree.root);
    freeTree(tree.root);
    return 0;
}