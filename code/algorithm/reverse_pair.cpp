#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
#include<map>

using namespace std;

vector<pair<int, int> > reverse_pairs(int n[], int size){
  vector<pair<int, int> > output;

  int index = 0;
  // Find the demarkation
  while(index < size-1 && n[index] < n[index+1]){
    index++;
  }

  int indexP1 = 0;
  int indexP2 = index+1;
  int L1 = size-indexP2;

  for(int i=0;i<L1;i++){
    for(int j=indexP2;j<size;j++){
      if(n[i] > n[j]){
        output.push_back(make_pair(n[i], n[j]));
      }
    }
  }

  return output;
}


int main(){
  int A[] = {4, 6, 8, 9, 1, 5, 10, 11};
  vector<pair<int, int> > output = reverse_pairs(A, sizeof(A)/sizeof(A[0]));

  for(vector<pair<int, int> >::iterator it = output.begin(); it != output.end(); ++it){
    cout<< (*it).first << " " << (*it).second << endl;
  }

  return 0;
}