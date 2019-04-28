#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

string convertToBase3(int N){
  string base3 = "";
  int dividend = N;
  int quotient = 0;

  while(dividend > 0){
    quotient = dividend % 3;
    dividend = dividend / 3;
    base3 = to_string(quotient) + base3;
  }
  return base3;
}

int main(){

  string str = convertToBase3(50);
  cout << str << endl;

  return 0;
}