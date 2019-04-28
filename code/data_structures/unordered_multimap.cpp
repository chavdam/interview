#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
  unordered_multimap<string, int> mymap;

  mymap.insert(pair<string, int>("abc", 1));
  mymap.insert(pair<string, int>("abc", 5)); // duplicate keys allowed
  mymap.insert(pair<string, int>("xyz", 7));
  mymap.insert(pair<string, int>("pqr", 89));
  mymap.insert(pair<string, int>("ads", 100));


  for(unordered_map<string, int>::iterator it = mymap.begin(); it != mymap.end(); ++it){
    cout << " Key : " << it->first << ", Value : " << it->second << endl;
  }

  return 0;
}