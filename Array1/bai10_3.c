#include <stdio.h>
#include <string.h>

#define MAX 1001

// chèn kí tự sau mỗi kí tự là kí tự liền kế kí tự đó
void Insertion(char str[], int index){
    for(int i = strlen(str); i > index + 1; i--){
        str[i] = str[i - 1];
    }
    str[index + 1] = str[index] + 1;
    str[strlen(str) + 1] = '\0';
}
/* hàm chèn sau mỗi kí tự trong mã độc với chỉ số 
bắt đầu và kết thúc của mã độc trong chuỗi
*/
void insertAfterCharOfSubStr(char str[], int begin, int end){
    while(end >= begin){
        Insertion(str, end);
        end--;
    }
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
                insertAfterCharOfSubStr(str, init, i - 1);
                i += sizeOfsubStr;
                size += sizeOfsubStr;
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