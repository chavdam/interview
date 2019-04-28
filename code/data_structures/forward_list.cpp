#include<iostream>
#include<forward_list>

using namespace std;

int main()
{
  int size = 10;
  forward_list<int> l(size, 0);

  l.push_front(89);
  //l.push_back(89); ===> ERROR as no push_back function exists.

  for(forward_list<int>::iterator it = l.begin(); it != l.end(); ++it){
    cout << *it << " ";
  }

  return 0;
}