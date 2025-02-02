#include <stdio.h>
#define MAX 100
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
    printf("\n");
}
void pushStackRecursion(Stack *s, int value){
    if(s->top == MAX - 1){
        printf("Stack is Full!\n");
        return;
    }
    if(value == 0){
        return;
    }
    (s->top)++;
    s->a[s->top] = value;
    scanf("%d", &value);
    pushStackRecursion(s, value);
    return;
}
//Base case: value == 0 va s->top == MAX - 1
//Result of base case: Ca 2 deu cho ra stack
//Before base case: pushStackRecursion(s, value): Mang co index tu [arr[0] ... arr[s.top - 1]]
//Before before: pushStackRecursion(s, value): Mang co index tu [arr[0] ... arr[s.top - 2]]
void popStackRecursion(Stack *s){
    if(s->top == 0){
        printf("pop %d\n", s->a[s->top]);
        (s->top)--;
        return;
    }
    printf("pop %d\n", s->a[s->top]);
    (s->top)--;
    popStackRecursion(s);
    return;
}
//Base case: s.top = 0
//Result of base case: popStackRecursion(s) = "pop s->a[s->top]"
//Before base case: popStackRecursion(s) = "pop s->a[s->top + 1]"
//Before before: popStackRecursion(s) = "pop s->a[s->top + 2]"
int main(){
    Stack s;
    init(&s);
    int number;
    scanf("%d", &number);
    pushStackRecursion(&s, number);
    displayStack(&s);
    popStackRecursion(&s);
    displayStack(&s);
    return 0;
}