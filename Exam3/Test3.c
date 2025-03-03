
//Hàm tính tổng giá trị low đến high bằng kĩ thuật đệ quy

// int sumFromLowToHigh(int low, int high){

//     //Base case:

//     if(low == high) return high;

//     //Nếu low không bằng thì + và tăng low lên cho đến khi bằng high

//     return low + sumFromLowToHigh(low + 1, high);

// }

//Quy trình 4 bước:

//Base case: low == high

//Result of base case: sumFromLowToHigh(high, high) = high;

//Before base case: sumFromLowToHigh(low, high) = sumFromLowToHigh(high - 1, high) = (high-1) + sumFromLowToHigh(high, high) = (high - 1) + high = 2*high - 1

//Before before: sumFromLowToHigh(low, high) = sumFromLowToHigh(high - 2, high) = (high - 2) + sumFromLowToHigh(high - 1, high) = (high - 2) + 2*high - 1 = 3*high - 3


//Chương trình test thử

#include <stdio.h>

//Hàm tính tổng giá trị low đến high bằng kĩ thuật đệ quy

int sumFromLowToHigh(int low, int high){

    //Base case:

    if(low == high) return high;

    //Nếu low không bằng thì + và tăng low lên cho đến khi bằng high

    return low + sumFromLowToHigh(low + 1, high);

}

//Quy trình 4 bước:

//Base case: low == high

//Result of base case: sumFromLowToHigh(high, high) = high;

//Before base case: sumFromLowToHigh(low, high) = sumFromLowToHigh(high - 1, high) = (high-1) + sumFromLowToHigh(high, high) = (high - 1) + high = 2*high - 1

//Before before: sumFromLowToHigh(low, high) = sumFromLowToHigh(high - 2, high) = (high - 2) + sumFromLowToHigh(high - 1, high) = (high - 2) + 2*high - 1 = 3*high - 3

int main(){

    //Khai báo 2 biến low high

    int low, high;

    //Nhập 2 biến low high

    printf("nhap low: ");

    scanf("%d", &low);

    printf("nhap high: ");

    scanf("%d", &high);

    //Khởi tạo biến sum lưu kết quả

    int sum = sumFromLowToHigh(low, high);

    //in kết quả ra màn hình

    printf("tong cac gia tri tu low den high la: %d\n", sum);

    return 0;

}

//Output:

//tong cac gia tri tu low den high la: 55 (low = 1, high = 10)