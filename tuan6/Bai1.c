#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1001
//cach 1
void swaps(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
void reverse1(char str[]){
    for(int i = 0; i < strlen(str) / 2; i++){
        swaps(&str[i], &str[strlen(str) - i - 1]);
    }
}
//cach 2
//set up stack
//Implement char stack in C
typedef struct Stack_type
{
    char a[MAX];
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
void push(Stack *s, char value){
    if(isFull(s)){
        printf("Stack is full!\n");
        return;
    }
    (s->top)++;
    s->a[s->top] = value;
}
char pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty!\n");
        return s->top;
    }
    char temp = s->a[s->top];
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
        printf("%c ", s->a[i]);
    }
}
// đảo ngược chuỗi bằng stack
void reverse2(char str[]){
    Stack s;
    //khởi tạo 1 stack mới
    init(&s);
    for(int i = 0; i < strlen(str); i++){
        push(&s, str[i]);
    }
    for(int i = 0; i < strlen(str); i++){
        str[i] = pop(&s);
    }
}
int main(){
    char str1[MAX], str2[MAX];
    scanf("%s", str1);
    //copy chuỗi 1 vào chuỗi 2 mục đích để so sánh 2 cách làm
    strcpy(str2, str1);
    reverse1(str1);
    printf("Cach 1: Dung mang \n%s\n", str1);
    reverse2(str2);
    printf("Cach 2: Dung Stack \n%s\n", str2);
    return 0;
}
