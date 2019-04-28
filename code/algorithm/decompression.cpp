#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
#include<map>

using namespace std;

bool isInt(char c){
  int ascii = c - '0';
  if(c >= 0 && c <= 9)
    return true;
  else
    return false;
}

bool isAlphabet(char c){
  return !isInt(c) && c != '[' && c != ']';
}

string repeat(string s, int times){ 
  for(int i=0;i<times;i++){
    s += s;
  }
  return s;

}

string decompressUtil(string input, int repeatTimes){
  cout << "input  = " << input << ", repeatTimes = " << repeatTimes << endl;
  int index = 0;
  int multiplier = 1;
  int size = input.length();
  
  if(size == 0) return "";

  string alphabets = "";

  if(index < size && isInt(input[index])){
    string s = "";
    while(index < size && isInt(input[index])){
      s += string(1, input[index]);
      index++;
    }
    multiplier = stoi(s);
  }
  if(index < size && isAlphabet(input[index])){
    while(index < size && isAlphabet(input[index])){
      alphabets += string(1, input[index]);
      index++;
    }
    return repeat(alphabets, repeatTimes);
  }
  if(index < size && input[index] == '['){
    index++;
    return repeat(decompressUtil(input.substr(index, size-index), multiplier), repeatTimes);
  }
  /*if(index < size && input[index] == ']'){
    if(alphabets != ""){
      for(int i=0;i<repeatTimes;i++){
        alphabets += alphabets;
      }
      return alphabets;
    }
  }*/
}

string decompress(string input){
  string output = decompressUtil(input, 1);
  return output;
}

int main()
{
  string input = "2[3[a]b]";
  cout << decompress(input) << endl;

  return 1;
}