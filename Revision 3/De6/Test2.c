#include <stdio.h>
#include <stdlib.h>
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

//Giải phóng bộ nhớ của cây
void freeTree(TreeNode *node){
    if(node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}
/*
             15
           /    \
          11     26
        /   \   /   \ 
        8   12  20   30
       / \    \       \
      6   9    14      35
*/
//Quy trình 4 bước
//Base case: node == NULL
//Result of base case: sumBinaryTree(NULL) = 0
/* 
Before base case: sumBinaryTree(6) = sumLeft + sumRight + 6 = 6 (sumLeft = 0, sumRight = 0 vì 2 node con của node này đều là NULL)
va sumBinaryTree(9) = sumLeft + sumRight + 9 = 9 (sumLeft = 0, sumRight = 0 vì 2 node con của node này đều là NULL)
*/
/*
Before before: sumBinaryTree(8) = sumLeft + sumRight + 8 = sumBinaryTree(6) + sumBinaryTree(9) + 8 = 6 + 9 + 8 = 23
*/
int sumBinaryTree(TreeNode *node){
    if(node == NULL) return 0;
    int sumLeft = sumBinaryTree(node->left);
    int sumRight = sumBinaryTree(node->right);
    return sumLeft + sumRight + node->data;
}
int main(){
    BinaryTree tree;
    init(&tree);
    tree.root = makeNode(15);
    //cây left
    tree.root->left = makeNode(11);
    tree.root->left->left = makeNode(8);
    tree.root->left->right = makeNode(12);
    tree.root->left->left->left = makeNode(6);
    tree.root->left->left->right = makeNode(9);
    tree.root->left->right->right = makeNode(14);
    //cây right
    tree.root->right = makeNode(26);
    tree.root->right->left = makeNode(20);
    tree.root->right->right = makeNode(30);
    tree.root->right->right->right = makeNode(35);
    int sum = sumBinaryTree(tree.root);
    printf("sum: %d\n", sum);
    printTreePreorder(tree.root);
    freeTree(tree.root);
    return 0;
}