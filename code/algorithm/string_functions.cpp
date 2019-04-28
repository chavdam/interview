#include <iostream>
#include<vector>
#include <string>
#include<sstream>

using namespace std;

string replaceAll(string subject, string search, string replacement){
  string output = subject;

  size_t searchLen = search.length();
  size_t pos = 0;

  while((pos = output.find(search, pos)) != string::npos){
    output = output.replace(pos, searchLen, replacement);
  }

  return output;
}

// "My Testing is done";
/*
1. prevPos = 0, nextPos = 2, My
2. prevPos = 3, nextPos = 10, Testing
3. prevPos = 11, nextPos = 13, is
4. prevPos = 14, nextPos = npos, done
*/

vector<string> split(string subject, char delimiter){
  vector<string> result;

  size_t prevPos = 0;
  size_t nextPos = 0;

  while(true){
    nextPos = subject.find(delimiter, prevPos);
    if(nextPos != string::npos){
      result.push_back(subject.substr(prevPos, (nextPos - prevPos)));
      prevPos = nextPos + 1;
    }
    else{
      result.push_back(subject.substr(prevPos));
      break;
    }
  }

  return result;
}

vector<string> split2(const string& subject, char delimiter){
  vector<string> result;
  stringstream ss(subject);
  string item;

  while(getline(ss, item, delimiter))
    result.push_back(item);

  return result;

}

int main(){
  string s = "ftyf ytf ytf ytf ytfy tf yfu fu fuyf uyfuy";
  cout << " s.substring(6,8) " << endl;
  cout << s.substr(6, 8);
  cout << endl;
  cout << " s.substring(6) " << endl;
  cout << s.substr(6);
  cout << endl;
  
  cout << " s.find(\"yt\") " << endl;
  size_t index = s.find("yt");
  if(index == string::npos){
    cout << " not found ";
  }
  else{
    cout << " Found at " << index;
  }
  cout << endl;
  cout << " s.find(\"yt\", 6) " << endl;
  cout << s.find("yt", 6);
  cout << endl;

  cout << " s.replace(4, 6, \"ab\") " << endl; // starting pos, length, replacement
  cout << s.replace(4, 6, "ab");
  cout << endl;

  cout << " s.replaceAll() " << endl;
  cout << replaceAll("this is my testing isn't it great ?", "is", "what");
  cout << endl;

  double d = 4.666666;
  cout << " to_string() " << endl; 
  cout << " double = " + to_string(d);
  cout << endl;
  
  string strD = "3.14";
  double dr = stod(strD);
  cout << " stod() " << endl; 
  cout << " double = " << dr;
  cout << endl;

  cout << "Spliting the string" << endl;
  vector<string> splitedString = split2("My Testing is done", ' ');
  for(unsigned indx=0;indx<splitedString.size();indx++){
    cout << splitedString[indx] << endl;
  }
  

  return 0;
}
