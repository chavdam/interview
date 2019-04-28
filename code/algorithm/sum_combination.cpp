#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

void findCombs(vector<int>& input, vector<vector<int> >& output){
 unordered_map<int, int> mapSum;

 for(int i=0; i<input.size()-1; i++){
   for(int j=i+1; j<input.size(); j++){
    int sum = input[i] + input[j];
    mapSum[sum] = j;
   }
 }
 for(int i=0; i<input.size()-1; i++){
   for(int j=i+1; j<input.size(); j++){
    int sum = input[j] - input[i];
    //cout << sum << "  ";
    if(mapSum[sum] && mapSum[sum] < i){
      vector<int> temp;
      temp.push_back(mapSum[sum] - 1);
      temp.push_back(mapSum[sum] );
      temp.push_back(i);
      temp.push_back(j);

      output.push_back(temp);
    }
   }
 }
}

int main(){
  
  int a[] = {2,3,5,1,10};

  //int a[] = {4,6, 9,3,13,18};
  vector<int> v(a, a + (sizeof(a)/sizeof(a[0])));
  vector<vector<int> > output;
  sort(v.begin(), v.end()); 
  findCombs(v, output);
  if(output.size() > 0){
    //cout << " found == > " << output.size();
    for(int i = 0 ; i < output.size(); i++){
      for(int j = 0; j< output[i].size(); j++){
        cout << v[output[i][j]] << "   ";
      }
      cout << endl;
    }
  }
  else{
    cout << " found none ... " << endl;
  }

  return 0;
}