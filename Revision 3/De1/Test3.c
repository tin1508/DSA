#include <stdio.h>
#include <stdlib.h>

//1.
/*
Cây nhị phân trên có lỗi sai vì: node 7 không nằm đúng vị trí, node 7 phải nằm bên nhánh trái của node 8 mới đúng vì:
7 < 34 nên 7 sẽ nằm bên nhánh trái của 34
7 < 10 nên 7 sẽ nằm bên nhánh trái của 10
7 < 8 nên 7 sẽ nằm bên nhánh trái của 8
cây nhị phân sau khi sửa xong:
                    34
                /       \
              10          75
            /   \        /
            8    29     65
           /     /     /  \
          7     19    50  70
                 \      \
                  26     55         
*/

//2, 3
typedef struct NodeType{
    int data;
    struct NodeType *left, *right;
}TreeNode;

typedef struct BinaryTreeType
{
    TreeNode *root;
}BinaryTree;

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
TreeNode *search(BinaryTree *tree, int value){
    TreeNode *temp = tree->root;
    while(temp != NULL){
        if(value == temp->data) return temp;
        else if(value > temp->data) temp = temp->right;
        else temp = temp->left;
    }
    return NULL;
}
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
        if(parent == NULL) tree->root = NULL;
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
        else parent->left = curr->left;
    }
    free(curr);
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
int main(){
    BinaryTree tree;
    init(&tree);
    int arr[] = {34, 10, 75, 8, 29, 65, 19, 50, 70, 7, 26, 55};
    int size = sizeof(arr) / sizeof(int);
    for(int i = 0; i < size; i++){
        insert(&tree, arr[i]);
    }
    printTreePreorder(tree.root);
    int value[] = {7, 50, 65};
    int sizeValue = sizeof(value) / sizeof(int);
    for(int i = 0; i < sizeValue; i++){
        printf("\nXoa node %d: ", value[i]);
        deleteNode(&tree, value[i]);
        printTreePreorder(tree.root);
    }
    freeTree(tree.root);
    return 0;
}