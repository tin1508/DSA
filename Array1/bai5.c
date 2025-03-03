#include <stdio.h>
#include <string.h>

#define MAX 1001

// hàm chèn 1 chuỗi vào 1 mảng chuỗi
void insertStr(char str[][MAX], int *n, int index, char s[]){
    for(int i = *n; i > index; i--){
        strcpy(str[i], str[i - 1]);
    }
    strcpy(str[index], s);
    *n += 1;
}
int main(){
    int n, m; scanf("%d %d", &n, &m);
    getchar(); // để xử lý lỗi trôi lệnh khi nhập chuỗi sau số nguyên
    char str[MAX][MAX];
    for(int i = 0; i < n; i++){
        scanf("%s", str[i]);
    }
    int index; 
    scanf("%d", &index);
    char s[MAX];
    scanf("%s", s);
    insertStr(str, &n, index, s);
    for(int i = 0; i < n; i++){
        printf("%s ", str[i]);
    }
    return 0;
}