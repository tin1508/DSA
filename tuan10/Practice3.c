#include <stdio.h>
#include <stdlib.h>

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
//print binarytree
void print(TreeNode* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        print(node->left);
        print(node->right);
    }
}
//init binarytree
void init(BinaryTree* tree) {
    tree->root=NULL;
}

//insert binarytree
void insert(BinaryTree *tree, int data){
    TreeNode* newNode = makeNode(data);
    if(tree->root == NULL){
        tree->root = newNode;
        return;
    }
    TreeNode* prev = NULL, *cur = tree->root;
    while(cur != NULL){
        prev = cur;
        if(cur->data > data) cur = cur->left;
        else cur = cur->right;
    }
    if(prev->data > data) prev->left = newNode;
    else prev->right = newNode;
}
//search in binary tree
TreeNode *search(TreeNode* node, int val){
    if(node == NULL || node->data == val){
        return node;
    }
    else if(node->data > val) return search(node->left, val);
    else search(node->right, val);
}
int main(){
    BinaryTree tree;
    init(&tree);
    //1.1.3
    int arr3[] = {50, 25, 75, 10, 33, 56, 89, 4, 11, 40, 52, 61, 82, 95};
    int size3 = sizeof(arr3) / sizeof(int);
    for(int i = 0; i < size3; i++){
        insert(&tree, arr3[i]);
    }
    print(tree.root);
    printf("\n");
    int val[] = {75, 89, 33, 61, 35};
    int sizeVal = sizeof(val) / sizeof(int);
    for(int i = 0; i < sizeVal; i++){
        TreeNode *findVal = search(tree.root, val[i]);
        if(findVal != NULL)
            printf("%d at %p\n", val[i], search(tree.root, val[i]));
        else         
            printf("%d Not found\n", val[i]);
    }
    return 0;
}