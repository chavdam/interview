#include<iostream>
#include<set>

using namespace std;

int main(){

  set<string> myset;

  myset.insert("abc");
  myset.insert("abc"); // It has unique values
  myset.insert("xyz");
  myset.insert("pqr");
  myset.insert("dfg");
  

  for(set<string>::iterator it = myset.begin(); it != myset.end(); ++it){
    cout << " " << *it;
  }

  set<string>::iterator it = myset.find("abc"); // There is NO [] operator...

  if(it != myset.end()){
    cout << "\n found";
  }
  else{
    cout << "\n not found";
  }

  cout << endl;

  return 0;

}