#include <iostream>

using namespace std;

int main(){
  int M; cin >> M;
  double money = ((double) 10 / 100) * M;
  int year = 1;
  while(money != (double) M*2){
    money = money + ((double) 10 / 100) * M;
    year = year + 1;
  }
  cout << year;
  return 0;
}