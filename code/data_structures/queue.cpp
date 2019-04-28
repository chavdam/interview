#include<iostream>
#include<queue>

using namespace std;

int main(){

  queue<string> q;

  q.push("abc");
  q.push("pqr");
  q.push("xyz");
  q.push("fgt");

  cout << "size : " << q.size() << endl;

  while(!q.empty()){
    cout << q.front() << "  ";
    q.pop();
  }

  return 0;
}