#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool isPerfectSquare(vector<string>& input, int dim){
  int row;
  for(row = 0;row < dim; row++){
    int col;
    for(col = 0; col < dim; col = col+1){
      if(input[row][col] != input[col][row]){
        break;
      }
    }
    if(col < dim)
      break;
  }

  bool ret = (row == dim);

  if(ret){
    for(int k = 0;k<input.size();k++){
            cout << input[k] << endl;
          }
          cout << endl;
  }

  cout <<  " ret = " << ret <<  " << row = " << row  << ", dim  = " << dim  << endl;

  return ret;

}

void perfectSquareCombsBruteForce(vector<vector<string> >& result, vector<string>& words, int iWords, int iData, int length){
  static vector<string> data(length, "");
  if(iData == length){
    //if(isPerfectSquare(data, length)){
      result.push_back(data);
    //}
    return;
  }

  if(iWords >= words.size())
    return;

  data[iData] = words[iWords];
  perfectSquareCombsBruteForce(result, words, iWords + 1, iData + 1, length);
  perfectSquareCombsBruteForce(result, words, iWords + 1, iData, length);
}

void perfectSquareDP(vector<vector<string> >& result, vector<string>& words){
  int size = words.size();
  //cout << "size = " <<  size;
  for(int i=0; i<size; i++){
    vector<bool> visted(size, false);
    visted[i] = true;
    vector<string> temp;
    temp.push_back(words[i]);
    int dim = 1;

    for(int j=0; j<size; j++){
      if(!visted[j]){
        visted[j] = true;
        temp.push_back(words[j]);
        dim++;
        if(!isPerfectSquare(temp, dim)){
          temp.pop_back();
          dim--;
        }
        if(dim == size){
          for(int k = 0;k<temp.size();k++){
            cout << temp[k] << endl;
          }
          break;
        }
      }
    }

    if(dim == size){
      cout << " done ";
      result.push_back(temp);
    }
  }
}

int main(){
  vector<string> input;
  input.push_back("AREA");
  input.push_back("BALL");
  input.push_back("DEAR");
  input.push_back("LADY");
  input.push_back("LEAD");
  input.push_back("YARD");

  vector<vector<string> > result;

  perfectSquareDP(result, input);

  //cout << result.size();

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