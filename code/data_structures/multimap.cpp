#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
  multimap<string, int> mymap;

  mymap.insert(pair<string, int>("abc", 7));
  mymap.insert(pair<string, int>("abc", 9));
  mymap.insert(pair<string, int>("xyz", 5));
  mymap.insert(pair<string, int>("pqr", 6));

  for(multimap<string, int>::iterator it = mymap.begin(); it != mymap.end(); ++it){
    cout << "Key : " << it->first << ", Value : " << it->second << endl;
  }

  multimap<string, int>::iterator it = mymap.find("abc");
  cout << "\n found => " << it->first << " :  " << it->second << endl;


  return 0;
}