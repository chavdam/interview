#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<unordered_map>

using namespace std;


int main(){
  for(int i=0;i<100; i++){
    cout << rand() % 30 << endl;
  }
  return 0;
}