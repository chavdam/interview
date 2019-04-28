#include<iostream>
#include<queue>

using namespace std;

class Comparator{
  public:
  bool operator() (int a, int b){
    return (a>b);
  }
};

int main(){
  //vector<int> vect = { 10, 20, 30 };  ==> only works with c++ 11.

  priority_queue<int, vector<int>, Comparator> q;

  q.push(8);
  q.push(4);
  q.push(3);
  q.push(9);

  cout << "size : " << q.size() << endl;

  while(!q.empty()){
    cout << q.top() << "  ";
    q.pop();
  }

  return 0;
}