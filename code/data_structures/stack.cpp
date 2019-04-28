#include<iostream>
#include<stack>

using namespace std;

int main(){
  stack<string> s;

  s.push("abc");
  s.push("xyz");
  s.push("asf");
  s.push("pqr");

  cout << "size : " << s.size() << endl;

  while(!s.empty()){
    cout << s.top() << "   ";
    s.pop();
  }

  return 0;
}