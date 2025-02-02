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
    else  prev->right = newNode;
}
int main(){
    BinaryTree tree;
    init(&tree);
    //insert cac cay o cau 1.1
    //1.1.1
    // int arr1[] = {4, 6, 2, 3, 5, 1, 7};
    // int size1 = sizeof(arr1) / sizeof(int);
    // for(int i = 0; i < size1; i++){
    //     insert(&tree, arr1[i]);
    // }
    //1.1.2
    // int arr2[] = {8, 10, 3, 6, 14, 1, 7, 13, 4};
    // int size2 = sizeof(arr2) / sizeof(int);
    // for(int i = 0; i < size2; i++){
    //     insert(&tree, arr2[i]);
    // }
    //1.1.3
    int arr3[] = {50, 25, 75, 10, 33, 56, 89, 4, 11, 40, 52, 61, 82, 95};
    int size3 = sizeof(arr3) / sizeof(int);
    for(int i = 0; i < size3; i++){
        insert(&tree, arr3[i]);
    }
    print(tree.root);
    return 0;
}