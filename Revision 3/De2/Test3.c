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
void sumOfRootToLeaf(TreeNode *node, int sum, int len, int *maxLen, int *maxSum){
    if(node == NULL){
        if(len > *maxLen){
            *maxLen = len;
            *maxSum = sum;
        }
        else if(len == *maxLen &&  sum > *maxSum){
            *maxSum = sum;
        }
        return;
    }
    sumOfRootToLeaf(node->left, sum + node->data, len + 1, maxLen, maxSum);
    sumOfRootToLeaf(node->right, sum + node->data, len + 1, maxLen, maxSum);
}
int sumOfLongRootToLeafPath(TreeNode *node){
    if(node == NULL) return 0;
    int maxSum = INT_MIN, maxLen = 0;
    sumOfRootToLeaf(node, 0, 0, &maxLen, &maxSum);
    return maxSum;
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
//Xóa tất cả các số nguyên lẻ(trừ root) trên cây nhị phân nhập vào
void deleteAllOddNumbersInTree(BinaryTree* tree) {
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
        // Check if the node contains an odd number
        if (temp->data % 2 != 0) {
            deleteNode(tree, temp->data);
        }
    }
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
    tree.root = makeNode(50);
    // Left subtree
    tree.root->left = makeNode(17);
    tree.root->left->left = makeNode(9);
    tree.root->left->right = makeNode(23);
    tree.root->left->left->right = makeNode(14);
    tree.root->left->left->right->left = makeNode(12);
    tree.root->left->right->left = makeNode(19);
    // Right subtree
    tree.root->right = makeNode(76);
    tree.root->right->left = makeNode(54);
    tree.root->right->left->right = makeNode(72);
    tree.root->right->left->right->left = makeNode(67);
    printTreePreorder(tree.root);
    printf("\n");
    deleteAllOddNumbersInTree(&tree);
    printTreePreorder(tree.root);
    freeTree(tree.root);
    return 0;
}