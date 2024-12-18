#include <stdio.h>
#include <math.h>

#define MAX 10000

//hàm đếm số lượng chữ số của 1 số
int NumQuant(int n){
    int count = 0;
    while(n != 0){
        n /= 10;
        count++;
    }
    return count;
}
//ktra từ phải qua trái giảm dần
// int IncreaseNumber(int n, int *comps){
//     int temp = n;
//     int back_nums = temp % 10;
//     temp /= 10;
//     (*comps) = 0;
//     while(temp != 0){
//         int front_nums = temp % 10;
//         (*comps)++;
//         if(front_nums <= back_nums){
//             back_nums = front_nums;
//             temp /= 10;
//         }
//         else return 0;
//     }
//     return 1;
// }

//kiểm tra tăng dần từ trái qua phải
int IncreaseNumber(int n, int *comps){
    int size = NumQuant(n);
    int nums = pow(10, size - 1);
    int front_nums, back_nums = 1;
    (*comps) = 0;
    int i = 1;
    while(back_nums != 0){
        front_nums = n / nums;
        back_nums = n / nums;
        (*comps)++; 
        if(front_nums <= back_nums){
            n = n % ((int) pow(10, size - i));
        }
        else return 0;
        i--;
    }
    return 1;
}

int main(){
    int comps;
    int sumComps = 0;
    for(int i = 1000; i <= 2000; i++){
        int result = IncreaseNumber(i, &comps);
        printf("with n: %d\t comps: %d\n", i, comps);
        if(result == 0){
            printf("n = %d is not increasing number, comps: %d\n", i, comps);
        }
        else{
            printf("n = %d is increasing number \t, comps: %d\n", i, comps);
        }
        sumComps += comps;
    }
    double averageComps = (double) sumComps / 1001;
    printf("Final Conclusion: %.3f", averageComps);
    return 0;
}