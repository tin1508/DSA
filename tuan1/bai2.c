#include <stdio.h>
#include <string.h>

#define MAX 1000

// hàm dùng để chuyển kí tự hoa thành kí tự thường
char toLower(char c){
    if(c >= 'A' && c <= 'Z'){
        return c += 32;
    }
    return c;
}
int main(){
    char str[MAX];
    fgets(str, sizeof(str), stdin);
    char c; 
    scanf("%c", &c);
    int check = 0; // dùng để kiểm tra có kí tự trong chuỗi không
    for(int i = 0; i < strlen(str); i++){
        // vì đề ko yêu cầu phân biệt hoa thường nên chuyển kí tự thành kí tự thường hết để dễ so sánh
        if(toLower(str[i]) == toLower(c)){ 
            check = 1;
            printf("Found %c at %d\n", c, i);
        }
    }
    if(check == 0){
        printf("Not found!");
    }
    return 0;
}