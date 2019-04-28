#include<iostream>
#include<vector>

using namespace std;

vector<int> indexOf(char* subject, char* pattern){
  vector<int> indices;
  int pattLength = strlen(pattern);
  int subLength = strlen(subject);

  for(int iSub=0; iSub<subLength; iSub++){
    int iPat = 0;
    while(iPat < pattLength && subject[iSub + iPat] == pattern[iPat])
      iPat++;
    if(iPat == pattLength)
      indices.push_back(iSub);
  }

  return indices;
}

int main(){
  char subject[] = "this is my room";
  char patt[] = "is";

  vector<int> indices = indexOf(subject, patt);
  int length = indices.size();

  for(int i=0;i<length;i++){
    cout << indices[i] << " ";
  }

  cout <<endl;

  return 0;
}