#include <stdio.h>
#include <string.h>

#define MAX 1000 // kích thước của mảng chuỗi
#define size_str 11 // độ dài của mỗi chuỗi trong danh sách

// hàm chèn chuỗi
void Insertion(char str[][size_str] , int *n, char subStr[size_str], int index){
    for(int i = *n; i > index; i--){
        strcpy(str[i], str[i - 1]);
    }
    strcpy(str[index], subStr);
    *n += 1;
}
//hàm so sánh thứ tự 2 chuỗi (so sánh xem chuỗi 1 có lớn hơn chuỗi 2 ko?)
// Mục đích để chèn thành 1 mảng chuỗi tăng dần theo chỉ số thứ tự
int compareStr(char s1[size_str], char s2[size_str]){
    if(s1[0] == s2[0]){
        if(s1[1] >= s2[1]){
            return 1;
        }
        else return 0;
    }
    else if(s1[0] > s2[0]){ 
        return 1;
    }
    return 0;
}
void InsertStr(char str[][size_str], int *n, int m, char s[][size_str]){
    for(int i = 0; i < m; i++){
        // kiểm tra xem chuỗi cần chèn có thứ tự có lớn hơn chuỗi cuối cùng trong mảng không
        if(compareStr(s[i], str[*n - 1])){
            (*n)++;
            strcpy(str[*n - 1], s[i]); 
        }
        else{
            for(int j = 0; j < *n; j++){
                if(compareStr(str[j], s[i])){
                    Insertion(str, n, s[i], j);
                    break;
                }
            }
        }
    }
}
int main(){
    int n; scanf("%d", &n);
    char str[MAX][size_str];
    for(int i = 0; i < n; i++){
        scanf("%s", str[i]);
    }
    int m; scanf("%d", &m);
    char s[MAX][size_str];
    for(int i = 0; i < m; i++){
        scanf("%s", s[i]);
    }
    InsertStr(str, &n, m, s);
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%s\n", str[i]);
    }
    return 0;
}