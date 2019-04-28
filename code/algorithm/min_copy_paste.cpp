#include<iostream>

using namespace std;

int ops = 0;
int numOfMinOps(int n){

  for(int i=2;i<=n;i++){
    while(n % i == 0){
      n = n/i;
      ops += i;
    }
  }

  return ops;
}

int main(){
  cout << numOfMinOps(50);
  return 0;
}