#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef struct NodeType {
    int data;
    struct NodeType* left, * right;
} TreeNode;

typedef struct BinaryTreeType{
    TreeNode * root;
} BinaryTree;

TreeNode* makeNode(int data){
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//init binarytree
void init(BinaryTree* tree) {
    tree->root=NULL;
}
//in cây theo thứ tự duyệt trước - preorder (root - left - right) (DFS)
void printTreePreorder(TreeNode* node) {
    if(node == NULL) return;
    printf("%d ", node->data);
    printTreePreorder(node->left);
    printTreePreorder(node->right);
}
//Hàm tính chiều cao của cây
int heightOfTree(TreeNode *root){
    if(root == NULL) return -1;
    else{
        int lheight = heightOfTree(root->left);
        int rheight = heightOfTree(root->right);
        if(lheight > rheight) return (lheight + 1);
        else return (rheight + 1);
    }
}
//Tính tổng data nhánh dài nhất
int sumOfLongestBranch(TreeNode *node, int *maxSum, int sum, int height, int count){
    if(node == NULL) return *maxSum;
    sum += node->data;
    sumOfLongestBranch(node->left, maxSum, sum, height, count + 1);
    sumOfLongestBranch(node->right, maxSum, sum, height, count + 1);
    if(count == height && sum > *maxSum){
        *maxSum = sum;
    }
    return *maxSum;
}
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
//tổng data trên nhánh nào lớn nhất
//hàm in đường đi
void printPath(TreeNode *node, int leaf){
    if(node == NULL) return;
    if(node->data == leaf){
        printf("%d\n", node->data);
        return;
    }
    printf("%d - ", node->data);
    if(node->data > leaf) printPath(node->left, leaf);
    else printPath(node->right, leaf);
    return;
}
//Hàm kiểm tra node lá
int isLeaf(TreeNode *node){
    if(node->left == NULL && node->right == NULL) return 1;
    else return 0;
}
void findMaxSumOnBranch(TreeNode *node, int *maxSum, int sum, int *leaf){
    if(node == NULL) return;
    sum += node->data;
    findMaxSumOnBranch(node->left, maxSum, sum, leaf);
    findMaxSumOnBranch(node->right, maxSum, sum, leaf);
    if(isLeaf(node) && sum > *maxSum){
        *leaf = node->data;
        *maxSum = sum;
    }
    return;
}
//Xóa tất cả các số nguyên lẻ(trừ root) trên cây nhị phân nhập vào
void deleteAllOddNumbersInTree(TreeNode *node, BinaryTree* tree) {
    if(node == NULL) return;
    deleteAllOddNumbersInTree(node->left, tree);
    deleteAllOddNumbersInTree(node->right, tree);
    if(node->data % 2 != 0 && node != tree->root){
        deleteNode(tree, node->data);
    }
    return;
}

//Giải phóng bộ nhớ của cây
void freeTree(TreeNode *node){
    if(node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main(){
    BinaryTree tree;
    init(&tree);
    tree.root = makeNode(15);
    //cây left
    tree.root->left = makeNode(10);
    tree.root->left->left = makeNode(8);
    tree.root->left->right = makeNode(11);
    tree.root->left->right->right = makeNode(12);
    tree.root->left->right->right->right = makeNode(14);
    tree.root->left->left->left = makeNode(6);
    tree.root->left->left->right = makeNode(9);
    //cây right
    tree.root->right = makeNode(18);
    tree.root->right->left = makeNode(16);
    tree.root->right->right = makeNode(17);
    printTreePreorder(tree.root);
    printf("\n");
    int leaf = 0, maxSum = INT_MIN;
    findMaxSumOnBranch(tree.root, &maxSum, 0, &leaf);
    printf("largest sum: %d\n", maxSum);
    printf("branch: ");
    printPath(tree.root, leaf);
    printTreePreorder(tree.root);
    freeTree(tree.root);
    return 0;
}