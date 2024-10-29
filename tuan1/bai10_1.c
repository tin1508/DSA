#include <stdio.h>
#include <string.h>

#define MAX 1001

int indexArr[MAX], size1 = 0;
int countArr[MAX], size2 = 0;

// hàm tìm mã độc trong gói tin
void findSubStr(char str[], char subStr[]){
    int j = 0; // j là biến đếm của chuỗi subStr
    int count = 0;
    int i = 0;
    while(i < strlen(str)){
        if(str[i] == subStr[j]){
            int init = i;
            while(str[i] == subStr[j]){
                i++; j++;
            }
            if(i - init == strlen(subStr)){
                indexArr[size1] = init;
                size1++;
                count++;
            }
            j = 0;
        }
        else i++;
    }
    countArr[size2] = count;
    size2++;
}

int main(){
    char str[MAX];
    scanf("%s", str);
    int k; 
    scanf("%d", &k);
    getchar();
    char subStrArr[5][MAX];
    for(int i = 0; i < k; i++){
        scanf("%s", subStrArr[i]);
        findSubStr(str, subStrArr[i]);
    }
    int j = 0;
    for(int i = 0; i < size2; i++){
        printf("%d %s ",countArr[i], subStrArr[i]);
        int temp = countArr[i];
        while(temp--){
            printf("%d", indexArr[j]);
            if(temp != 0){
                printf(", ");
            }
            j++;
        }
        printf("\n");
    }
    return 0;
}