#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1001
//set up stack
//Implement char stack
typedef struct Stack_typeChar
{
    char a[MAX];
    int top;
} StackChar;
 
void initStChar(StackChar *s){
    s->top = -1;
}
int isEmptyStchar(StackChar *s){
    if(s->top == -1){
        return 1;
    }
    else return 0;
}
int isFullStChar(StackChar *s){
    if(s->top == MAX - 1){
        return 1;
    }
    else return 0;
}
void pushStChar(StackChar *s, char value){
    if(isFullStChar(s)){
        printf("Stack is full!\n");
        return;
    }
    (s->top)++;
    s->a[s->top] = value;
}
char popStChar(StackChar *s){
    if(isEmptyStchar(s)){
        printf("Stack is empty!\n");
        return s->top;
    }
    char temp = s->a[s->top];
    s->a[s->top] = s->a[s->top - 1];
    (s->top)--;
    return temp;
}
void displayStackChar(StackChar *s){
    if(isEmptyStchar(s)){
        printf("Stack is empty!!");
        return;
    }
    for(int i = 0; i <= s->top; i++){
        printf("%c ", s->a[i]);
    }
}
//Implement int stack 
typedef struct Stack_typeInt
{
    int a[MAX];
    int top;
} StackInt;
 
void initStInt(StackInt *s){
    s->top = -1;
}
int isEmptyStInt(StackInt *s){
    if(s->top == -1){
        return 1;
    }
    else return 0;
}
int isFullStInt(StackInt *s){
    if(s->top == MAX - 1){
        return 1;
    }
    else return 0;
}
void pushStInt(StackInt *s, int value){
    if(isFullStInt(s)){
        printf("Stack is full!\n");
        return;
    }
    (s->top)++;
    s->a[s->top] = value;
}
int popStInt(StackInt *s){
    if(isEmptyStInt(s)){
        printf("Stack is empty!\n");
        return s->top;
    }
    int temp = s->a[s->top];
    s->a[s->top] = s->a[s->top - 1];
    (s->top)--;
    return temp;
}
void displayStackInt(StackInt *s){
    if(isEmptyStInt(s)){
        printf("Stack is empty!!");
        return;
    }
    for(int i = 0; i <= s->top; i++){
        printf("%d ", s->a[i]);
    }
}
//hàm chuyển chữ số thành số: '9' -> 9
int convertCharToInt(char c){
    int number = (int) c - '0';
    return number;
}
//chuyển đổi toán tử kiểu char thành phép tính
int calcFollowOper(int a, int b, char oper){
    switch (oper){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}
void solve(char str[], int *result){
    StackChar output, operators;
    initStChar(&output);
    initStChar(&operators);
    //chuyển biểu thức sang dạng postfix
    for(int i = 0; i < strlen(str); i++){
        if(isdigit(str[i])){
            pushStChar(&output, str[i]);
        }
        else if(isEmptyStchar(&operators) == 1 && (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')){
            pushStChar(&operators, str[i]);
        }
        else if(isEmptyStchar(&operators) == 0){
            if(str[i] == '+' || str[i] == '-'){
                while(isEmptyStchar(&operators) == 0){
                    char topOperators = popStChar(&operators);
                    pushStChar(&output, topOperators);
                }
                pushStChar(&operators, str[i]);
            }
            else{
                char topOperators = operators.a[operators.top];
                while(topOperators != '+' && topOperators != '-'){
                    pushStChar(&output, popStChar(&operators));
                    topOperators = operators.a[operators.top];
                }
                pushStChar(&operators, str[i]);
            }
        }
    }
    if(isEmptyStchar(&operators) == 0){
        while(isEmptyStchar(&operators) == 0){
            pushStChar(&output, popStChar(&operators));
        }
    }
    for(int i = strlen(str) - 1; i >= 0; i--){
        str[i] = popStChar(&output);
    }
    //tính giá trị biểu thức từ dạng postfix
    StackInt calcValue;
    initStInt(&calcValue);
    for(int i = 0; i < strlen(str); i++){
        //isdigit() là hàm kiểm tra xem kí tự đó có phải chữ số ko
        if(isdigit(str[i])){
            pushStInt(&calcValue, convertCharToInt(str[i]));
        }
        else{
            int firstNumber = popStInt(&calcValue);
            int secondNumber = popStInt(&calcValue);
            pushStInt(&calcValue, calcFollowOper(secondNumber, firstNumber, str[i]));
        }
    }
    *result = popStInt(&calcValue);
}
int main(){
    char str[MAX];
    scanf("%s", str);
    int result;
    solve(str, &result);
    printf("%s\n", str);
    printf("Result = %d\n", result);
    return 0;
}