#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];
    fgets(str, 1001, stdin);
    char c;
    scanf("%c", &c);
    int index; 
    scanf("%d", &index);
    for(int i = strlen(str) + 1; i > index; i--){
        str[i] = str[i - 1];
    }
    str[index] = c;
    printf("%s", str);
    return 0;
}