#include<iostream>
#include<list>

using namespace std;

int main()
{
  int size = 10;
  list<string> l(size, "Test");

  l.push_back("back");
  l.push_front("front");

  for(list<string>::iterator it = l.begin(); it != l.end(); ++it){
    cout << *it << " ";
  }

  return 0;
}