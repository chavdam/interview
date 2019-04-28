#include<iostream>
#include<vector>

using namespace std;

int main()
{
  int size = 10;
  vector<int> v(size);

  v.push_back(8);
  v.push_back(9);

  for(int i=0;i<v.size();i++){
    cout << v[i] << " ";
  }

  cout << "\n================\n";


  for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
    cout << *it << " ";
  }

  return 0;
}