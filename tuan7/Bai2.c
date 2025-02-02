//2.1
// #include <stdio.h>
// void printElementOfArray(int arr[], int n){
//     if(n == 0){
//         printf("%d ", arr[0]);
//         return;
//     }
//     printElementOfArray(arr, n - 1);
//     printf("%d ", arr[n]);
//     return;
// }
// int main(){
//     int n; scanf("%d", &n);
//     int arr[100];
//     for(int i = 0; i < n; i++){
//         scanf("%d", &arr[i]);
//     }
//     printElementOfArray(arr, n - 1);
//     return 0;
// }

// //2.2
// #include <stdio.h>
// int LinearSearchRecursion(int arr[], int i, int n, int value){
//     if(arr[i] == value){
//         return i;
//     }
//     if(i > n - 1){
//         return -1;
//     }
//     return LinearSearchRecursion(arr, i + 1, n, value);
// }
// int main(){
//     int n; scanf("%d", &n);
//     int arr[100];
//     for(int i = 0; i < n; i++){
//         scanf("%d", &arr[i]);
//     }
//     int value; scanf("%d", &value);
//     int index = LinearSearchRecursion(arr, 0,  n, value);
//     if(index == -1){
//         printf("Not Found\n");
//     }
//     else{
//         printf("Found at index = %d\n", index);
//     }
//     return 0;
// }

//2.3.a
// #include <stdio.h>
// #define MAX 20
// //Implement stack 
// typedef struct Stack_type
// {
//     int a[MAX];
//     int top;
// } Stack;
// void init(Stack *s){
//     s->top = -1;
// }
// int isEmpty(Stack *s){
//     if(s->top == -1){
//         return 1;
//     }
//     else return 0;
// }
// int isFull(Stack *s){
//     if(s->top == MAX - 1){
//         return 1;
//     }
//     else return 0;
// }
// void push(Stack *s, int value){
//     if(isFull(s)){
//         printf("Stack is full!\n");
//         return;
//     }
//     (s->top)++;
//     s->a[s->top] = value;
// }
// int pop(Stack *s){
//     if(isEmpty(s)){
//         printf("Stack is empty!\n");
//         return s->top;
//     }
//     int temp = s->a[s->top];
//     s->a[s->top] = s->a[s->top - 1];
//     (s->top)--;
//     return temp;
// }
// void displayStack(Stack *s){
//     if(isEmpty(s)){
//         printf("Stack is empty!!");
//         return;
//     }
//     for(int i = 0; i <= s->top; i++){
//         printf("%d ", s->a[i]);
//     }
// }
// void popStackRecursion(Stack *s){
//     if(isEmpty(s)){
//         printf("Stack is empty!\n");
//         return ;
//     }
//     printf("pop %d\n", s->a[s->top]);
//     (s->top)--;
//     popStackRecursion(s);
//     return;
// }
// int main(){
//     Stack s;
//     init(&s);
//     int n = 20; 
//     for(int i = 0; i < n; i++){
//         int elements; scanf("%d", &elements);
//         push(&s, elements);
//     }
//     popStackRecursion(&s);
//     displayStack(&s);
//     return 0;
// }

// //2.3.b
// #include <stdio.h>
// #define MAX 20
// //Implement queue
// typedef struct Queue_type{
//     int head, tail;
//     int a[MAX];
// } Queue;
// void init(Queue* q)
// {
//     q->head = 0;
//     q->tail = -1;
// }
// int isEmpty(Queue* q) {
//     if(q->tail < q->head){
//         return 1;
//     }
//     else return 0;
// }
// int isFull(Queue* q) { 
//     if(q->tail == MAX - 1){
//         return 1;
//     }
//     else return 0;
// }
// void put(Queue* q, int value)
// {
//     if (isFull(q)) {
//         printf("Queue is full\n");
//         return;
//     }
//     (q->tail)++;
//     q->a[q->tail] = value;
// }
// int get(Queue* q)
// {
//     if(isEmpty(q)){
//         return -1;
//     }
//     int element = q->a[q->head];
//     q->head++;
//     return element;
// }
// void displayQueue(Queue* q)
// {
//     if(isEmpty(q)){
//         printf("Queue is Empty!!");
//         return;
//     }
//     for(int i = q->head; i <= q->tail; i++){
//         printf("%d ", q->a[i]);
//     }
//     return;
// }
// void getQueueRecursion(Queue* q)
// {
//     if(isEmpty(q)){
//         printf("Queue is empty!\n");
//         return;
//     }
//     printf("get %d\n", q->a[q->head]);
//     q->head++;
//     getQueueRecursion(q);
//     return;
// }
// int main(){
//     Queue q;
//     init(&q);
//     int n = 20;
//     for(int i = 0; i < n; i++){
//         int elements; scanf("%d", &elements);
//         put(&q, elements);
//     }
//     getQueueRecursion(&q);
//     displayQueue(&q);
//     return 0;
// }

//2.4
// #include <stdio.h>
// int binarySearchRecur(int arr[], int l, int r, int value){
//     if(l <= r){
//         int m = (l + r) / 2;
//         if(arr[m] == value)
//             return m;
//         if(arr[m] > value)
//             return binarySearchRecur(arr, l, m - 1, value);
//         if(arr[m] < value)
//             return binarySearchRecur(arr, m + 1, r, value);
//     }
//     return -1;
// }
// int main(){
//     int n; scanf("%d", &n);
//     int arr[100];
//     printf("Nhap mang theo thu tu tang dan: ");
//     for(int i = 0; i < n; i++){
//         scanf("%d", &arr[i]);
//     }
//     int value; scanf("%d", &value);
//     int index = binarySearchRecur(arr, 0, n - 1, value);
//     if(index == -1){
//         printf("Not found\n");
//     }
//     else{
//         printf("%d\n", index);
//     }
//     return 0;
// }