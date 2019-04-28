#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;
int N = 4;

bool isSafe(vector<vector<int> >& board, int row, int col){
  if(!(row >= 0 && row < N && col >= 0 && col < N))
    return false;
  for(int c = col; c>=0; c--){
    if(board[row][c] == 1)
      return false;
  }
  for(int r=row, c=col; r>=0 && c>=0; r--, c--){
    if(board[r][c] == 1)
      return false;
  }
  for(int r=row, c=col; r<N && c>=0; r++, c--){
    if(board[r][c] == 1)
      return false;
  }
  
  return true;
}

bool PlaceNQ(vector<vector<int> >& board, int c){
  if(c >= N)
    return true;
  
  for(int r=0; r<N; r++){
    if(isSafe(board, r, c)){
      board[r][c] = 1;
      if(PlaceNQ(board, c+1))
        return true;

      board[r][c] = 0;
    }
  }

  return false;
}

int main(){
  vector<vector<int> > board(N, vector<int>(N, 0));
   PlaceNQ(board, 0);
   for(int i=0;i<board.size(); i++){
     for(int j=0; j<board[i].size(); j++){
       cout << board[i][j] << "   ";
     }
     cout << endl;
   }
  return 0;
}