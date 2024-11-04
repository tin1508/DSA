#include <stdio.h>
#include <string.h>

// hàm kiểm tra chuỗi tăng dần chưa
int isIncrease(char str[]){
    for(int i = 0; i < strlen(str) - 1; i++){
        if(str[i + 1] - str[i] < 0){
            return 0; // chuỗi này ko tăng dần
        }
    }
    return 1; // chuỗi này tăng dần
}
//linearsearch
int linearSearch(char str[], char value){
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == value){
            return i;
        }
        else if(str[i] > value){
            return -1;
        }
    }
    return -1;
}
//binarysearch
int binarySearch(char str[], char value){
    int l = 0, r = strlen(str) - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(str[mid] < value){
            l = mid + 1;
        }
        else if(str[mid] > value){
            r = mid - 1;
        }
        else 
            return mid;
    }
    return -1;
}
int main(){
    char str[1001], value;
    scanf("%s", str);
    getchar();
    if(isIncrease(str) == 0){
        printf("chuoi khong tang dan!\n");
    }
    else{
        scanf("%c", &value);
        int index1 = linearSearch(str, value);
        int index2 = binarySearch(str, value);
        if(index1 != -1 && index2 != -1){
            printf("chi so cua linearSearch la: %d\n", index1);
            printf("chi so cua binarySearch la: %d\n", index2);
        }
        else printf("Not found!\n");
    }
    return 0;
}
/*
So sánh:
tùy testcase thì binarySearch sẽ cho ra chỉ số giống hoặc khác với linearSearch
Vd: testcase1
    input : bcccdefgh
            c
    output: chi so cua linearSearch la: 1
            chi so cua binarySearch la: 1
    Ví dụ trên cho chúng ta thấy đầu ra chỉ số của 2 thuật toán là như nhau
    testcase2
    input: bcdeeefghi
            e
    output: chi so cua linearSearch la: 3
            chi so cua binarySearch la: 4
    Ví dụ trên cho chúng ta thấy đầu ra chỉ số của 2 thuật toán là khác nhau
Qua 2 ví dụ trên thì chúng ta có thể thấy chỉ số đầu ra của binarySearch là phụ thuộc vào chỉ số middle (vì khi mà str[middle] == value thì nó sẽ trả ra chỉ số)
Nên đối với các trường hợp có kí tự xuất hiện nhiều lần thì đầu ra của 2 thuật toán có thể cho ra output khác nhau
*/