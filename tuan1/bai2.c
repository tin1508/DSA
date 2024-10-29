#include <stdio.h>
#include <string.h>

#define MAX 1000

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
    int check = 0;
    for(int i = 0; i < strlen(str); i++){
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