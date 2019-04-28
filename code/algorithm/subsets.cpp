#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<vector<int> > getSubSets(vector<int> arr){
  vector<vector<int> > result;
  unsigned n = arr.size();

  unsigned maxNumOfCombs = pow(2, n);

  for(int i=0;i<maxNumOfCombs; i++){
    vector<int> temp;
    for(int j=0;j<n;j++){
      if(i & (1 << j)){
        temp.push_back(arr[j]);
      }
    }
    result.push_back(temp);
  }

  return result;

}

int main(){
  vector<int> arr;
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(4);
  arr.push_back(5);
  arr.push_back(6);
  vector<vector<int> > result = getSubSets(arr);

  int count = 0;
  for(int i=0;i<result.size();i++){
    for(int j=0;j<result[i].size();j++){
      cout << result[i][j] << "  ";
    }
    count++;
    cout<<endl;
  }
  cout << endl << "total = " << count << endl;

  return 0;
}