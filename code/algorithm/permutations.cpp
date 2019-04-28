#include<iostream>
#include<vector>

using namespace std;

void swap(vector<int>& nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    
  void permuteUtil(vector<vector<int> >& permutations, vector<int>& nums, int begin, int end){
      
      if(begin == end){
          permutations.push_back(nums);
          return;
      }
      
      for(int i=begin; i<nums.size();i++){
          swap(nums, begin, i);
          permuteUtil(permutations, nums, begin + 1, end);
          swap(nums, begin, i);
      }
  }
  
  vector<vector<int> > permute(vector<int>& nums) {
      vector<vector<int> > permutations;
      permuteUtil(permutations, nums, 0, nums.size()-1);
      return permutations;
  }

int main(){

  vector<int> set ;
  set.push_back(1);
  set.push_back(2);
  set.push_back(3);
  set.push_back(4);
  set.push_back(5);
  set.push_back(6);
  
  vector<vector<int> > output = permute(set);


for(unsigned i=0;i<output.size();i++){
    cout << endl;
    for(unsigned j=0; j<output[i].size(); j++){
      cout << output[i][j] << " ";
    }
  }

  cout << endl;


  return 0;
}
