#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
  unordered_map<string, int> mymap;

  mymap["abc"] = 1;
  mymap["pqr"] = 3;
  mymap["def"] = 5;
  mymap["abc"] = 10; // Duplicate key not allowed
  mymap["abc"]++;
  mymap.insert(pair<string, int>("pair", 12));

  for(unordered_map<string, int>::iterator it = mymap.begin(); it != mymap.end(); ++it){
    cout << " Key : " << it->first << ", Value : " << it->second << endl;
  }

  return 0;
}