#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20
//Implement stack 
typedef struct Stack_type
{
    int a[MAX];
    int top;
} Stack;
void init(Stack *s){
    s->top = -1;
}
int isEmpty(Stack *s){
    if(s->top == -1){
        return 1;
    }
    else return 0;
}
int isFull(Stack *s){
    if(s->top == MAX - 1){
        return 1;
    }
    else return 0;
}
void push(Stack *s, int value){
    if(isFull(s)){
        printf("Stack is full!\n");
        return;
    }
    (s->top)++;
    s->a[s->top] = value;
}
int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty!\n");
        return s->top;
    }
    int temp = s->a[s->top];
    s->a[s->top] = s->a[s->top - 1];
    (s->top)--;
    return temp;
}
void displayStack(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty!!");
        return;
    }
    for(int i = 0; i <= s->top; i++){
        printf("%d ", s->a[i]);
    }
}
//Sinh ngẫu nhiên 20 thẻ được đánh dấu từ 1-10
void initializeArray(int cards[], int n){
    for(int i = 0; i < n; i++){
        cards[i] = 1 + rand() % 10;
    }
}
//kiểm tra xem trong mảng có chắc chắn có số 1 ko?
int checkNumberOneInArr(int cards[], int n){
    for(int i = 0; i < n; i++){
        if(cards[i] == 1){
            return 1;
        }
    }
    return 0;
}
//hàm đệ quy tạo hộp
void creatBoxToSave(Stack *s, int cards[], int i){
    if(cards[i] == 1){
        push(s, cards[i]);
        return;
    }
    push(s, cards[i]);
    creatBoxToSave(s, cards, i + 1);
    return;
}
//Base case: cards[i] = 1
//Result of base case: s.a[s.top] = 1
//Before base case: cards[i - 1] != 1 createBoxToSave(s, cards, i - 1): s.a[s.top] = a[i - 1]
//Before before: cards[i - 2] != 1 createBoxToSave(s, cards, i - 2): s.a[s.top] = a[i - 2]

//hàm đệ quy để tính tổng
int calcSumOfStack(Stack *s){
    if(isEmpty(s)){
        return 0;
    } 
    int sum = pop(s);
    return sum + calcSumOfStack(s);
}
//Lấy ví dụ: Cards in box: 4 9 9 8 6 9 3 10 5 4 2 10 2 4 1
//Base case: isEmpty(s)
//Result of base case: calcSumOfStack(s) = 0
//Before base case: isEmpty(s) = 0, calcSumOfStack(s) = s.a[s.top] + 0 = 1 + 0 = 1 // vì phần tử trên đầu stack lúc nào cũng sẽ là 1
//Before before: isEmpty(s) = 0, calcSumOfStack(s) = s.a[s.top + 1] + calcSumOfStack(s) = 4 + 1 = 5
int main(){
    time_t t;
    srand((unsigned)time(&t));
    int n = 20;
    int cards[MAX], number;
    initializeArray(cards, n);
    //sinh mảng đến khi nào trog mảng có ít nhất 1 phần tử 1
    while(checkNumberOneInArr(cards, n) == 0){
        initializeArray(cards, n);
    }
    printf("20 cards: ");
    for(int i = 0; i < n; i++){
        printf("%d ", cards[i]);
    }
    printf("\nCards in box: ");
    Stack box;
    init(&box);
    creatBoxToSave(&box, cards, 0);
    displayStack(&box);
    int res = calcSumOfStack(&box);
    printf("\n%d\n", res);
    return 0;
}