#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<vector<string> > getSubstrings(string str){
  vector<vector<string> > result;
  unsigned n = str.length();

  for(int indx=0; indx<n; indx++){
    vector<string> tempV;
    for(int grps=1; grps<=n; grps++){
      string temp = "";
      for(int i=indx; i<grps; i++){
        temp += str[i];
      }
      tempV.push_back(temp);
    }
    result.push_back(tempV);
  }
  
  return result;

}

int main(){
  string s = "abcdefg";
  vector<vector<string> > result = getSubstrings(s);

  int count = 0;
  for(int i=0;i<result.size();i++){
    for(int j=0;j<result[i].size();j++){
      cout << result[i][j] << "  ";
      count++;
    }
    
    cout<<endl;
  }
  cout << endl << "total = " << count << endl;

  return 0;
}