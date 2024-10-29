#include <stdio.h>
#include <string.h>

#define MAX 1001

void deleteSubStr(char str[], int begin, int end){
    for(int i = end + 1; i < strlen(str); i++){
        str[begin] = str[i];
        begin++;
    }
    str[begin] = '\0';
}
// hàm tìm mã độc trong gói tin
void findSubStr(char str[], char subStr[]){
    int j = 0; // j là biến đếm của chuỗi subStr
    int i = 0;
    int size = strlen(str);
    int sizeOfsubStr = strlen(subStr);
    while(i < size){
        if(str[i] == subStr[j]){
            int init = i;
            while(str[i] == subStr[j]){
                i++; j++;
            }
            if(i - init == strlen(subStr)){
                deleteSubStr(str, init, i - 1);
                i = i - sizeOfsubStr;
                size -= sizeOfsubStr;
            }
            j = 0;
        }
        else i++;
    }
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
    printf("%s", str);
    return 0;
}