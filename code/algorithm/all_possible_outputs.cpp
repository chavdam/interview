#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<unordered_map>

using namespace std;

vector<string> split(const string& input, char delim){
  vector<string> result;
  stringstream ss(input);
  string item;
  while(getline(ss, item, delim)){
    result.push_back(item);
  }
  return result;
}

void allPossibleStrings(string& input, vector<string>& output){
  string part = "";
  int start = 0;
  size_t startPos = input.find('{', start);
  if(startPos != string::npos){
    part = input.substr(start, startPos - start);
    size_t endPos = input.find('}', startPos + 1);
    if(endPos != string::npos){
      string combs = input.substr(startPos + 1, endPos - startPos - 1);
      vector<string> combsArr = split(combs, ',');
      for(int i = 0; i<combsArr.size(); i++){
        string tempInput = input;
        tempInput.replace(startPos, endPos - startPos + 1, combsArr[i]);
        allPossibleStrings(tempInput, output);
      }
    }
    else{
      return;
    }
  }
  else{
    output.push_back(input);
    return;
  }
}

int main(){
  
  string input = "abc{d,e}f{gh,ij}";
  //string input = "abc{d,e,gh}";
  vector<string> output;
  allPossibleStrings(input, output);
  for(int i = 0; i<output.size(); i++){
    cout << output[i] << endl;
  }
  
  return 0;
}