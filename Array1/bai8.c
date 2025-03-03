#include <stdio.h>
#include <string.h>

#define MAX 1001

void deleteElement(char *str, int index){
    for(int i = index; i < strlen(str) - 1; i++){
        str[i] = str[i + 1];
    }
    str[strlen(str) - 1] = '\0';
}
int main(){
    char str[MAX];
    scanf("%s", str);
    int index; // chỉ số để xóa
    scanf("%d", &index);
    deleteElement(str, index);
    printf("%s", str);
    return 0;
}