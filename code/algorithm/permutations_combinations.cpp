#include<iostream>
#include<vector>

using namespace std;

void getPermutations(vector<int>& set, vector<vector<int> >& output, int l, int i, int index){

  static vector<int> data(l);

  if(index == l){
      output.push_back(data);
      return;
  }

  if(i >= set.size())
    return;

  data[index] = set[i];

  getPermutations(set, output, l, i + 1, index + 1);
  getPermutations(set, output, l, i + 1, index);

}


void getCombinations(vector<string>& set, vector<vector<string> >& output, unsigned l, unsigned i, unsigned index){
    static vector<string> data(l);

    if(index == l){
        //if(isWinningPair(data[0] + data[1])){
            output.push_back(data);
        //}
        return;
    }

    if(i >= set.size())
        return;
    
    data[index] = set[i];

    getCombinations(set, output, l, i + 1, index + 1);
    getCombinations(set, output, l, i + 1, index);
}


int main(){

  vector<int> set ;
  set.push_back(1);
  set.push_back(2);
  set.push_back(3);
  //set.push_back(4);
  //set.push_back(5);
  //set.push_back(6);
  vector<vector<int> > output;
  
  getPermutations(set, output, 2, 0, 0);

  for(unsigned i=0;i<output.size();i++){
    cout << endl;
    for(unsigned j=0; j<output[i].size(); j++){
      cout << output[i][j] << " ";
    }
  }

  cout << endl;


  vector<string> set2;
  set2.push_back("9300455");
  set2.push_back("5559948277");
  set2.push_back("012334556");
  set2.push_back("56789");
  set2.push_back("123456879");
  vector<vector<string> > out;
  
  getCombinations(set2, out, 2, 0,0);


for(unsigned i=0;i<out.size();i++){
    cout << endl;
    for(unsigned j=0; j<out[i].size(); j++){
      cout << out[i][j] << " ";
    }
  }

  cout << endl;


  return 0;
}
