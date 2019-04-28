#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main()
{
  int size = 10;
  deque<string> d(size,"Mahesh");

  d.push_back("Nirupama");
  d.push_front("test");

  for(int i=0;i<d.size();i++){
    cout << d[i] << " ";
  }

  return 0;
}