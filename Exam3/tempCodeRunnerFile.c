//Hàm tính tổng giá trị low đến high bằng kĩ thuật đệ quy

int sumFromLowToHigh(int low, int high){

    //Base case:

    if(low == high) return high;

    //Nếu low không bằng thì + và tăng low lên cho đến khi bằng high

    return low + sumFromLowToHigh(low + 1, high);

}