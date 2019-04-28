#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

bool canMove(vector<vector<int> >& board, int r, int c){
  int N = board.size();
  if(r < N && r >= 0 && c < N && c >= 0 && board[r][c] == -1)
    return true;
  else
    return false;
}

void knightMoves(vector<vector<int> >& board, int row, int col){
  static int step = 0;
  static int xMoves[] = { -2, -2,  2, 2,  -1, 1, -1, 1 };
  static int yMoves[] = { -1,  1, -1, 1,  -2, -2, 2, 2 };

  if(!canMove(board, row, col))
    return;
  
  board[row][col] = step++;

  for(int i=0; i<8; i++){
    int r = row + xMoves[i];
    int c = col + yMoves[i];
    if(canMove(board, r, c))
      knightMoves(board, r, c);
  }
}

int main(){
  int N = 8;
  vector<int> cols(N, -1);
  vector<vector<int> > m(N, cols);
  knightMoves(m, 0, 0);
  for(int i = 0; i< m.size(); i++){
    for(int j = 0; j<m[0].size(); j++){
      string rs = m[i][j] < 10 ? "0" + to_string(m[i][j]) : to_string(m[i][j]);
      cout << rs << "   ";
    }
    cout << endl;
  }
  return 0;
}