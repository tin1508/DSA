#include <stdio.h>
#include <string.h>

#define MAX 1001 

// mảng index để lưu các chỉ số xuất hiện chuỗi cần tìm tương ứng, size biểu thị kích thước của mảng index
int indexArr[MAX - 1], size = 0; 
// hàm search để tìm kiếm chuỗi cần tìm
void search(char serialKey[][MAX], int n, int k, char str[]){
    for(int i = 0; i < n; i++){
        int check = 1;
        // trước tiên kiểm tra xem chuỗi trong mảng có kích thước bằng với chuỗi cần tìm không
        if(strlen(serialKey[i]) == strlen(str)){ 
            for(int j = 0; j < k; j++){
                // duyệt từng kí tự của mỗi chuỗi để kiểm tra xem có bằng nhau không, nếu khác thì thoát ra khỏi vòng lặp
                if(serialKey[i][j] != str[j]){
                    check = 0; // biến check dùng để kiểm tra xem 2 chuỗi có giống nhau không
                    break;
                }
            }
            if(check == 1){
                indexArr[size] = i;
                size++;
            }
        }
    }
}
int main(){
    int n; scanf("%d", &n);
    int k; scanf("%d", &k);
    getchar();
    char serialKey[MAX][MAX];
    for(int i = 0; i < n; i++){
        scanf("%s", serialKey[i]);
    }
    char str[MAX]; // chuỗi cần tìm
    scanf("%s", str);
    search(serialKey, n, k, str);
    // nếu size = 0 nghĩa là trong mảng index ko có bất kì phần tử nào => ko có chuỗi cần tìm trong mảng chuỗi đã cho
    if(size == 0){ 
        printf("Not found!\n");
    }
    else{
        printf("Found %s at ", str);
        for(int i = 0; i < size; i++){
            printf("%d", indexArr[i]);
            if(i != size - 1){ // chỉ số cuối ko cần in dấu ,
                printf(", ");
            }
        }
    }
    return 0;
}
