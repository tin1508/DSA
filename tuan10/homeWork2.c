#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include "queue.h"

typedef struct NodeType {
    int data;
    struct NodeType* left, *right;
} TreeNode;
typedef struct BinaryTreeType{
    TreeNode *root;
} BinaryTree;
//init binarytree
void init(BinaryTree* tree) {
    tree->root=NULL;
}
//Hàm tạo 1 node mới cho cây
TreeNode* makeNode(int data){
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
//hàm tìm kiếm value có xuất hiện trong node của cây không
TreeNode* search(BinaryTree *tree, int value) {
    TreeNode *temp = tree->root;
    while(temp != NULL){
        if(temp->data == value) return temp;
        else if(temp->data > value) temp = temp->left;
        else temp = temp->right;
    }
    return NULL;
}
//hàm chèn 1 node mới vào cây
void insert(BinaryTree *tree, int value){
    TreeNode *newNode = makeNode(value);
    if(tree->root == NULL){
        tree->root = newNode;
    }
    else{
        TreeNode *parent = NULL, *curr = tree->root;
        while(curr != NULL){
            parent = curr;
            if(value > parent->data) curr = curr->right;
            else curr = curr->left;
        }
        if(parent->data > value) parent->left = newNode;
        else parent->right = newNode;
    }
}
void deleteNode(BinaryTree *tree, int value){
    //TH nếu ko có nút xóa
    if(search(tree, value) == NULL){
        printf("value is not found in Binary tree!!\n");
        return;
    }
    //Tìm nút cha của nút cần xóa
    TreeNode *curr = tree->root;
    TreeNode *parent = NULL;
    while(curr->data != value){
        parent = curr;
        if(parent->data > value) curr = curr->left;
        else curr = curr->right;
    }
    //TH1: nút cần xóa ko có nút con hay nút cần xóa là nút lá
    if(curr->left == NULL && curr->right == NULL){
        if(parent == NULL) tree->root = NULL;
        else if(parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
        free(curr);
    }
    //TH2: nút cần xóa chỉ có 1 nút con bên trái
    else if(curr->left != NULL && curr->right == NULL){
        if(parent == NULL) tree->root = curr->left;
        else if(parent->left == curr) parent->left = curr->left;
        else parent->right = curr->left;
        free(curr);
    }
    //TH3: nút cần xóa chỉ có 1 nút con bên phải
    else if(curr->left == NULL && curr->right != NULL){
        if(parent == NULL) tree->root = NULL;
        else if(parent->left == curr) parent->left = curr->right;
        else parent->right = curr->right;
        free(curr);
    }
    //TH4: nút cần xóa có 2 nút con
    else if(curr->left != NULL && curr->right != NULL){
        //tìm node lớn nhất bên con trái của node cần xóa -> tìm node phải nhất của con trái node cần xóa
        curr = curr->right, parent = NULL;
        while(curr->left != NULL){
            parent = curr;
            curr = curr->left;
        }
        //Gán node cần xóa bằng node vừa tìm được
        curr->data = curr->data;
        //xóa curr
        if(parent == NULL) curr->right = curr->right;
        else parent->left = curr->right;
        free(curr);
    }
}

//in cây theo thứ tự duyệt trước - preorder (root - left - right)
void printTreePreorder(TreeNode* node) {
    if(node == NULL) return;
    printf("%d ", node->data);
    printTreePreorder(node->left);
    printTreePreorder(node->right);
}
//Hàm cho biết các node ở level thứ k của tree
//Dùng thuật toán DFS: Depth First Search
void nodesAtLevelKInTree(TreeNode *node, int level, int k){
    if(node == NULL) return;
    if(k == level){
        printf("%d ", node->data);
    }
    nodesAtLevelKInTree(node->left, level + 1, k);
    nodesAtLevelKInTree(node->right, level + 1, k);
}
//Giải phóng bộ nhớ cho cây
void freeTree(TreeNode *node){
    if(node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}
int main(){
    BinaryTree tree;
    init(&tree);
    // //1.1
    // tree.root = makeNode(1);
    // //cây left
    // tree.root->left = makeNode(2);
    // tree.root->left->left = makeNode(4);
    // tree.root->left->right = makeNode(5);
    // tree.root->left->left->left = makeNode(8);
    // tree.root->left->left->right = makeNode(9);
    // tree.root->left->right->left = makeNode(10);
    // tree.root->left->right->right = makeNode(11);
    // //cây right
    // tree.root->right = makeNode(3);
    // tree.root->right->left = makeNode(6);
    // tree.root->right->right = makeNode(7);
    // tree.root->right->left->left = makeNode(12);
    // tree.root->right->left->right = makeNode(13);
    // tree.root->right->right->left = makeNode(14);
    // tree.root->right->right->right = makeNode(15);
    // //in cây theo thứ tự preorder(root - left - right)
    // printTreePreorder(tree.root);
    // printf("\n");
    // //2.1
    // //Tìm nút có giá trị 25
    // int value = 25;
    // TreeNode *s = search(&tree, value);
    // if(s != NULL){
    //     printf("%d Found in Tree!\n", value);
    // }
    // else printf("%d Not found in Tree!\n", value);
    // //2.2
    // //Xóa nút có giá trị 12
    // deleteNode(&tree, 12);
    // //2.3
    // insert(&tree, 23);
    // //2.4
    // //nhập level muon tim nodes
    // int k = 3;
    // printf("Cac node o level %d cua cay la: \n", k);
    // nodesAtLevelKInTree(tree.root, 0, k);
    // printf("Cay sau khi thuc hien cac thao tac: \n");
    // printTreePreorder(tree.root);
    // freeTree(tree.root);

    // //1.2
    // tree.root = makeNode(50);
    // //cây left
    // tree.root->left = makeNode(17);
    // tree.root->left->left = makeNode(9);
    // tree.root->left->right = makeNode(23);
    // tree.root->left->left->right = makeNode(14);
    // tree.root->left->left->right->left = makeNode(12);
    // tree.root->left->right->left = makeNode(19);
    // //cây right
    // tree.root->right = makeNode(76);
    // tree.root->right->left = makeNode(54);
    // tree.root->right->left->right = makeNode(72);
    // tree.root->right->left->right->left = makeNode(67);
    // //in cây theo thứ tự preorder(root - left - right)
    // printTreePreorder(tree.root);
    // printf("\n");
    // //2.1
    // //Tìm nút có giá trị 25
    // int value = 25;
    // TreeNode *s = search(&tree, value);
    // if(s != NULL){
    //     printf("%d Found in Tree!\n", value);
    // }
    // else printf("%d Not found in Tree!\n", value);
    // //2.2
    // //Xóa nút có giá trị 12
    // deleteNode(&tree, 12);
    // //2.3
    // insert(&tree, 23);
    // //2.4
    // //nhập level muon tim nodes
    // int k = 3;
    // printf("Cac node o level %d cua cay la: \n", k);
    // nodesAtLevelKInTree(tree.root, 0, k);
    // printf("\nCay sau khi thuc hien cac thao tac: \n");
    // printTreePreorder(tree.root);
    // freeTree(tree.root);

    // //1.3
    // tree.root = makeNode(15);
    // //cây left
    // tree.root->left = makeNode(11);
    // tree.root->left->left = makeNode(8);
    // tree.root->left->right = makeNode(12);
    // tree.root->left->left->left = makeNode(6);
    // tree.root->left->left->right = makeNode(9);
    // tree.root->left->right->right = makeNode(14);
    // //cây right
    // tree.root->right = makeNode(26);
    // tree.root->right->left = makeNode(20);
    // tree.root->right->right = makeNode(30);
    // tree.root->right->right->right = makeNode(35);
    // //in cây theo thứ tự preorder(root - left - right)
    // printTreePreorder(tree.root);
    // printf("\n");
    // //2.1
    // //Tìm nút có giá trị 25
    // int value = 25;
    // TreeNode *s = search(&tree, value);
    // if(s != NULL){
    //     printf("%d Found in Tree!\n", value);
    // }
    // else printf("%d Not found in Tree!\n", value);
    // //2.2
    // //Xóa nút có giá trị 12
    // deleteNode(&tree, 12);
    // //2.3
    // insert(&tree, 23);
    // //2.4
    // //nhập level muon tim nodes
    // int k = 3;
    // printf("Cac node o level %d cua cay la: \n", k);
    // nodesAtLevelKInTree(tree.root, 0, k);
    // printf("\nCay sau khi thuc hien cac thao tac: \n");
    // printTreePreorder(tree.root);
    // freeTree(tree.root);

    //1.4
    tree.root = makeNode(3);
    //cây left
    tree.root->left = makeNode(1);
    tree.root->left->left = makeNode(13);
    tree.root->left->right = makeNode(5);
    tree.root->left->right->left = makeNode(6);
    //cây right
    tree.root->right = makeNode(10);
    tree.root->right->left = makeNode(11);
    tree.root->right->right = makeNode(16);
    tree.root->right->right->left = makeNode(15);
    tree.root->right->right->left->left = makeNode(9);
    tree.root->right->right->left->right = makeNode(4);
    tree.root->right->right->right = makeNode(2);
    //in cây theo thứ tự preorder(root - left - right)
    printTreePreorder(tree.root);
    printf("\n");
    //2.1
    //Tìm nút có giá trị 25
    int value = 25;
    TreeNode *s = search(&tree, value);
    if(s != NULL){
        printf("%d Found in Tree!\n", value);
    }
    else printf("%d Not found in Tree!\n", value);
    //2.2
    //Xóa nút có giá trị 12
    deleteNode(&tree, 12);
    //2.3
    insert(&tree, 23);
    //2.4
    //nhập level muon tim nodes
    int k = 3;
    printf("Cac node o level %d cua cay la: \n", k);
    nodesAtLevelKInTree(tree.root, 0, k);
    printf("\nCay sau khi thuc hien cac thao tac: \n");
    printTreePreorder(tree.root);
    freeTree(tree.root);
    return 0;
}