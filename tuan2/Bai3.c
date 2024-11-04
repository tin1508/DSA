#include <stdio.h>
#include <string.h>

void insertion(char str[], int index, char character){
    for(int i = strlen(str); i > index; i--){
        str[i] = str[i - 1];
    }
    str[index] = character;
    str[strlen(str) + 1] = '\0';
}
//tìm vị trí của kí tự còn thiếu trong chuỗi
int binarySearch(char str[]){
    if(str[strlen(str) - 1] - 'a' == (strlen(str) - 1)){
        return strlen(str);
    }
    else{
        int l = 0, r = strlen(str) - 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(str[m] - 'a' == m) l = m + 1;
            else if(str[m] - 'a' > m) r = m - 1;
            else return -1;
        }
        return l; // vị trí cần chèn kí tự thiếu
    }
}
int main(){
    char str[27];
    scanf("%s", str);
    int index = binarySearch(str);
    if(index == strlen(str)){
        printf("%c at %d is missing!\n", str[index - 1] + 1, index);
        insertion(str, index, str[index - 1] + 1);
    }
    else{
        printf("%c at %d is missing!\n", str[index] - 1, index);
        insertion(str, index, str[index] - 1);
    }
    printf("%s", str);
    return 0;
}
/*
Em dùng binarySearch để giải bài này. Theo em thấy binarySearch 
phù hợp với vấn đề vì nó sẽ ít bước giải hơn là tìm kiếm tuyến tính.
*/