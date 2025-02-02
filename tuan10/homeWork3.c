#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef struct NodeType{
    int data;
    struct NodeType *left, *right;
}TreeNode;

typedef struct Tree{
    TreeNode *root;
}BinaryTree;

//tao 1 node moi
TreeNode* makeNode(int data){
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
//init binarytree
void initTree(BinaryTree *tree){
    tree->root = NULL;
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
    int head = 0, tail = 0;
    int parent[10005] = {0};
    q[tail] = node;
    tail++;
    parent[node->data] = node->data;
    TreeNode *temp = NULL;
    int leaf = 0;
    while(head < tail){
        temp = q[head];
        head++;
        if(isLeaf(temp)){
            leaf = temp->data;
            break;
        }
        if(temp->left){
            q[tail] = temp->left; tail++;
            parent[temp->left->data] = temp->data;
        }
        if(temp->right){
            q[tail] = temp->right; tail++;
            parent[temp->right->data] = temp->data;
        }
    } 
    printPath(leaf, parent);
    printf("%d ", leaf);
}
//3.2
//tim xem level nao co so node nhieu nhat
int levelHaveLargestNumberOfElements(TreeNode *node){
    if(node == NULL) return -1; // nghia la ko co cay
    TreeNode *q[1000];
    int head = 0, tail = -1;
    tail++;
    q[tail] = node;
    int level = 0, max = INT_MIN, level_no = 0, NodeCount;
    while(head <= tail){
        NodeCount = (tail - head) + 1;
        if(NodeCount > max){
            max = NodeCount;
            level_no = level;
        }
        while(NodeCount > 0){
            TreeNode *temp = q[head]; head++;
            if(temp->left){
                tail++;
                q[tail] = temp->left;
            }
            if(temp->right){
                tail++;
                q[tail] = temp->right;
            }
            NodeCount--;
        }
        level++;
    }
    return level_no;
}
//3.3
//ham kiem tra node co 1 node con hay khong
int haveOnlyOneChild(TreeNode *node){
    if(node->left != NULL && node->right == NULL) return 1;
    else if(node->left == NULL && node->right != NULL) return 1;
    else return 0;
}
//Tinh tong gia tri cac node ma trong do chi co 1 node con
int sumNodeHaveOnlyOneChild(TreeNode *node){
    if(node == NULL) return -1;
    TreeNode *q[1000];
    int head = 0, tail = -1;
    int sum = 0;
    tail++;
    q[tail] = node;
    while(head <= tail){
        TreeNode *temp = q[head]; head++;
        if(haveOnlyOneChild(temp) == 1) sum += temp->data;
        if(temp->left){
            tail++;
            q[tail] = temp->left;
        }
        if(temp->right){
            tail++;
            q[tail] = temp->right;
        }
    }
    return sum;
}
//3.4
//ham kiem tra node do co 1 node con ben trai hay ko?
int haveOnlyOneLeftChild(TreeNode *node){
    if(node->left != NULL && node->right == NULL) return 1;
    else return 0;
}
//Hieu cua gtri o 3.3 tru di tong cac gia tri cua cac node chi co 1 node con ben trai
int subtractOfNodes(BinaryTree *tree){
    if(tree->root == NULL) return -1;
    TreeNode* q[1000];
    int head = 0, tail = -1;
    tail++;
    q[tail] = tree->root;
    TreeNode *node = tree->root;
    int sum = 0;
    while(head <= tail){
        TreeNode *temp = q[head]; head++;
        if(haveOnlyOneLeftChild(temp)) sum += temp->data;
        if(temp->left){
            tail++;
            q[tail] = temp->left;
        }
        if(temp->right){
            tail++;
            q[tail] = temp->right;
        }
    }
    return sumNodeHaveOnlyOneChild(tree->root) - sum;
}
//3.5
TreeNode* nodeNearValue(TreeNode *node, TreeNode *result, int value, int nearestValue){
    if(node == NULL) return result;
    if(abs(node->data - value) <= nearestValue){
        nearestValue = abs(node->data - value);
        result = node;
    }
    if(value > node->data) nodeNearValue(node->right, result, value, nearestValue);
    else if(value < node->data) nodeNearValue(node->left, result, value, nearestValue);
}
//Duyet theo muc - level order
void levelOrder(TreeNode *node){
    TreeNode *q[1000];
    int head = 0, tail = 0;
    q[tail] = node;
    tail++;
    printf("%d ", node->data);
    while(head < tail){
        TreeNode *temp = q[head]; head++;
        if(temp->left != NULL){
            q[tail] = temp->left;
            tail++;
            printf("%d ", temp->left->data);
        }
        if(temp->right != NULL){
            q[tail] = temp->right;
            tail++;
            printf("%d ", temp->right->data);
        }
    }
}
//print Tree
void printTreePreOrder(TreeNode *node){
    if(node == NULL) return;
    printf("%d ", node->data);
    printTreePreOrder(node->left);
    printTreePreOrder(node->right);
}
//free tree
void freeTree(TreeNode *node){
    if(node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}
int main(){
    BinaryTree tree;
    initTree(&tree);   
    tree.root = makeNode(50);
    //cây left
    tree.root->left = makeNode(17);
    tree.root->left->left = makeNode(9);
    tree.root->left->right = makeNode(23);
    tree.root->left->left->right = makeNode(14);
    tree.root->left->left->right->left = makeNode(12);
    tree.root->left->right->left = makeNode(19);
    //cây right
    tree.root->right = makeNode(76);
    tree.root->right->left = makeNode(54);
    tree.root->right->left->right = makeNode(72);
    tree.root->right->left->right->left = makeNode(67);
    TreeNode *result = NULL;
    result = nodeNearValue(tree.root, result, subtractOfNodes(&tree), INT_MAX);
    printf("%d ", result->data);
    freeTree(tree.root);
    return 0;
}