#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool canBeSummed(vector<int>& temp, vector<int>& tempRes, int target){
  while(true){
    for(int i=0;i<temp.size();i++){
      if(target >=  temp[i]){
        target -= temp[i];
        tempRes.push_back(temp[i]);
      }
    }
    if(target == 0){
      return true;
    }
    else{
      return false;
    }
  }
}

void combSumUtil(vector<vector<int> > result, vector<int>& candidates, int& target){
  int length = candidates.size();
  for(int i=0;i<length;i++){
    for(int grp=1;grp<=length;grp++){
      vector<int> temp;
      vector<int> tempRes;
      for(int j=i;j<grp;j++){
        temp.push_back(candidates[j]);
      }
      if(canBeSummed(temp, tempRes, target)){
        result.push_back(tempRes);
      }
    }
  }
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {   
  vector<vector<int> > result;
  combSumUtil(result, candidates, target);
  return result;
}


int main(){
  vector<int> input;
  input.push_back(2);
  input.push_back(3);
  input.push_back(6);
  input.push_back(7);
  vector<vector<int> > result = combinationSum(input, 7);

  for(int i=0;i<result.size();i++){
    cout << "[";
    for(int j=0;j<result[i].size();j++){
      cout << result[i][j] << " ";
    }
    cout << "]" << endl;
  }

  return 0;
}