#include<iostream>
#include<unordered_set>

using namespace std;

int main(){

  unordered_set<string> myset;

  myset.insert("abc");
  myset.insert("pqr");
  myset.insert("abc"); // duplicate not allowed ...
  myset.insert("xyz");
  myset.insert("asd");

  for(unordered_set<string>::iterator it = myset.begin(); it != myset.end(); ++it){
    cout << " " << *it;
  }

  unordered_set<string>::iterator it = myset.find("pqr");

  if(it != myset.end()){
    cout << " Found \n";
  }
  else{
    cout << " Not Found \n";
  }

  cout << endl;

  return 0;
}