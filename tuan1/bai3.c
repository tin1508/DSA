#include <stdio.h>
#include <string.h>

#define MAX 1001 

int search(char serialKey[][MAX], int n, int k, char str[]){
    for(int i = 0; i < n; i++){
        int check = 1;
        if(strlen(serialKey[i]) == strlen(str)){
            for(int j = 0; j < k; j++){
                if(serialKey[i][j] != str[j]){
                    check = 0;
                }
            }
            if(check == 1) return i;
        }
    }
    return -1;
}
int main(){
    int n; scanf("%d", &n);
    int k; scanf("%d", &k);
    getchar();
    char serialKey[MAX][MAX];
    for(int i = 0; i < n; i++){
        scanf("%s", serialKey[i]);
    }
    char str[MAX];
    scanf("%s", str);
    int index = search(serialKey, n, k, str);
    if(index == -1){
        printf("Not found!\n");
    }
    else{
        printf("Found %s at %d\n", str, index);
    }
    return 0;
}
