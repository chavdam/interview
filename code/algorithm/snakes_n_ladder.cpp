#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int minMoves(vector<int>& board){
  int size = board.size();
  queue<pair<int, int> > q;
  vector<bool> visited(size, false);

  visited[0] = true;
  pair<int, int> v = make_pair(0,0);
  q.push(v);

  while(!q.empty()){
    v = q.front();
    q.pop();
    cout << v.first << ", " << v.second << endl;
    
    if(v.first == size-1)
      break;

    for(int i=v.first+1; i<(v.first+6) && i<size;i++){
        if(!visited[i]){
          visited[i] = true;

        if(board[i] == -1){
          q.push(make_pair(i, v.second + 1));
        }
        else{
          q.push(make_pair(board[i], v.second + 1));
        }
      }
    }
  }

  return v.second;

}

int main(){
  int V = 36;
  vector<int> board(V, -1);
  
  // Ladders
  board[2] = 15;
  board[14] = 24;
  board[20] = 31;

  //Snakes
  board[11] = 1;
  board[29] = 3;
  board[34] = 21;

  int moves = minMoves(board);

  cout << "Minimum moves = " << moves << endl;

  return 0;
}