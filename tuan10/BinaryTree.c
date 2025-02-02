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

TreeNode* search(BinaryTree *tree, int value){
    TreeNode *temp = tree->root;
    while(temp != NULL){
        if(value == temp->data){
            return temp;
        }
        else if(value > temp->data) temp = temp->right;
        else temp = temp->left;
    }
    return temp;
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

//in cây theo thứ tự duyệt trước - preorder (root - left - right) (DFS)
void printTreePreorder(TreeNode* node) {
    if(node == NULL) return;
    printf("%d ", node->data);
    printTreePreorder(node->left);
    printTreePreorder(node->right);
}
//Duyet theo muc - level order (BFS)
void levelOrder(TreeNode *node){
    TreeNode *q[1000];
    int head = 0, tail = -1;
    tail++;
    q[tail] = node;
    printf("%d ", node->data);
    while(head <= tail){
        TreeNode *temp = q[head]; head++;
        if(temp->left != NULL){
            tail++;
            q[tail] = temp->left;
            printf("%d ", temp->left->data);
        }
        if(temp->right != NULL){
            tail++;
            q[tail] = temp->right;
            printf("%d ", temp->right->data);
        }
    }
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
//3.1
//hàm kiểm tra nút lá
int isLeaf(TreeNode *node){
    if(node->left == NULL && node->right == NULL) return 1;
    else return 0;
}
//ham de in duong di
void printPath(int data, int *arr){
    if(arr[data] == data) return;
    printPath(arr[data], arr);
    printf("%d ", arr[data]);
}
//tim duong di co it phan tu nhat tu root - leaf
void findShortestPath(TreeNode *node){
    TreeNode* q[1000];
    int head = 0, tail = -1;
    int parent[10005] = {0};
    tail++;
    q[tail] = node;
    parent[node->data] = node->data;
    TreeNode *temp = NULL;
    int leaf = 0;
    while(head <= tail){
        temp = q[head];
        head++;
        if(isLeaf(temp)){
            leaf = temp->data;
            break;
        }
        if(temp->left){
            tail++;
            q[tail] = temp->left; 
            parent[temp->left->data] = temp->data;
        }
        if(temp->right){
            tail++;
            q[tail] = temp->right;
            parent[temp->right->data] = temp->data;
        }
    } 
    printPath(leaf, parent);
    printf("%d ", leaf);
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
    levelOrder(tree.root);
    freeTree(tree.root);
    return 0;
}