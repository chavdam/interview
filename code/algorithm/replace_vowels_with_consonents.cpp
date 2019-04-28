#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

bool isVowel(char c){
  string vowels = "aeoiuAEOIU";
  return (vowels.find(c, 0) != string::npos);
}

string replaceVowels(string s){
  int length = s.length();
  queue<int> q;
  
  for(int i=0; i<length; i++){
    if(isVowel(s[i])){
      q.push(i);
    }
    else{
      while(!q.empty()){
        int index = q.front();
        q.pop();
        s[index] = s[i];
      }
    }
  }
  while(!q.empty()){
    int index = q.front();
    q.pop();
    s.erase(index);
  }


  return s;
}

int main(){
  string s = "aaaa";
  string newStr = replaceVowels(s);
  cout << newStr << endl;

  return 0;
}