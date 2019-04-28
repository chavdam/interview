#include<iostream>
#include<map>

using namespace std;

void printMap(map<string, int>& inputMap)
{
  for(map<string, int>::iterator it = inputMap.begin(); it != inputMap.end(); ++it)
  {
    cout << " key : " << it->first << ", value : " << it->second << endl;
  }
}

int main()
{
  map<string, int> myMap;

  myMap["abc"] = 1;
  myMap["sqr"] = 2;
  myMap["etr"] = 7;

  printMap(myMap);

  return 0;
}