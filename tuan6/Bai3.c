#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1001
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
//hàm chuyển chữ số thành số: '9' -> 9
int convertCharToInt(char c){
    int number = (int) c - '0';
    return number;
}
//chuyển đổi toán tử kiểu char thành phép tính
int convertOperators(int a, int b, char oper){
    switch (oper){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}
void solve(char str[], int *result){
    Stack output, operators;
    init(&output);
    init(&operators);
    //chuyển biểu thức sang dạng postfix
    for(int i = 0; i < strlen(str); i++){
        if(isdigit(str[i])){
            push(&output, str[i]);
        }
        else if(isEmpty(&operators) == 1 && (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')){
            push(&operators, str[i]);
        }
        else if(isEmpty(&operators) == 0){
            if(str[i] == '+' || str[i] == '-'){
                while(isEmpty(&operators) == 0){
                    char topOperators = pop(&operators);
                    push(&output, topOperators);
                }
                push(&operators, str[i]);
            }
            else{
                char topOperators = operators.a[operators.top];
                while(topOperators != '+' && topOperators != '-'){
                    push(&output, pop(&operators));
                    topOperators = operators.a[operators.top];
                }
                push(&operators, str[i]);
            }
        }
    }
    if(isEmpty(&operators) == 0){
        while(isEmpty(&operators) == 0){
            push(&output, pop(&operators));
        }
    }
    for(int i = strlen(str) - 1; i >= 0; i--){
        str[i] = pop(&output);
    }
    //tính giá trị biểu thức từ dạng postfix
    Stack calcValue;
    init(&calcValue);
    for(int i = 0; i < strlen(str); i++){
        if(isdigit(str[i])){
            push(&calcValue, str[i]);
        }
        else{
            
        }
    }
}
int main(){
    char str[MAX];
    scanf("%s", str);
    int result;
    solve(str, &result);
    printf("%s", str);
    return 0;
}