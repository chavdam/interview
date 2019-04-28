#include<iostream>
#include<array>

using namespace std;

int main()
{
  const int size = 10;
  array<int, size> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  for(int i=0;i<a.size();i++){
    cout<<a[i] << " ";

  }

}