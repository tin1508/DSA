#include <stdio.h>
#include <string.h>

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
int CheckValidParenthesis(char str[], int ErrorIndex[], int *n){
    Stack parenthesis;
    init(&parenthesis);
    int check = 1;
    *n = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '{'){
            push(&parenthesis, '}');
        }
        else if(str[i] == '['){
            push(&parenthesis, ']');
        }
        else if(str[i] == '('){
            push(&parenthesis, ')');
        }
        else if(isEmpty(&parenthesis) == 0 && (str[i] == '}' || str[i] == ']' || str[i] == ')')){
            char temp = pop(&parenthesis);
            if(temp != str[i]){
                check = 0;
                str[i] = temp;
                ErrorIndex[*n] = i;
                (*n)++;
            }
        }
    }
    //nếu stack vẫn chưa empty tức là vẫn còn dấu ngoặc trong đó
    //phép tính vẫn còn bị thiếu hay dư dấu ngoặc
    //Th ví dụ là: [[3 + 5] + (6 + 8) 
    if(isEmpty(&parenthesis) == 0){
        pop(&parenthesis);
        check = 0;
    }
    return check;
}
int main(){
    char str[MAX];
    //khai bao kich thuoc cua mang luu nhung vi tri sai
    int ErrorIndex[MAX], n;
    scanf("%s", str);
    if(CheckValidParenthesis(str, ErrorIndex, &n) == 1){
        printf("No error.\n");
    }
    else{
        printf("Error at ");
        for(int i = 0; i < n; i++){
            printf("%d", ErrorIndex[i]);
            if(i != n - 1){
                printf(", ", ErrorIndex[i]);
            }
        }
        printf("\n%s\n", str);
    }
    return 0;
}