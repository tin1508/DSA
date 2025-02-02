#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
TreeNode* makeNode(int data){
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
//in cây theo thứ tự duyệt trước - preorder (root - left - right)
void printTreePreorder(TreeNode* node) {
    if(node == NULL) return;
    printf("%d ", node->data);
    printTreePreorder(node->left);
    printTreePreorder(node->right);
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
    

    //1.3
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
    return 0;
}