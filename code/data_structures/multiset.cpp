#include<iostream>
#include<set>

using namespace std;

int main(){
  multiset<string> myset;

  myset.insert("abc");
  myset.insert("abc"); // Duplicate allowed...
  myset.insert("pqr");
  myset.insert("rst");
  myset.insert("xyz");
  myset.insert("def");

  for(multiset<string>::iterator it = myset.begin(); it != myset.end(); ++it){
    cout << " " << *it;
  }

  multiset<string>::iterator it = myset.find("def");

  if(it != myset.end()){
    cout << "\n Found";
    cout << endl << *it;
  }
  else{
    cout << "\n Not Found";
  }

  cout << endl;


  return 0;
}