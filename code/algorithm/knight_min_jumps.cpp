#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

typedef struct Point{
  int x;
  int y;
  int jumps;
  Point(int _x, int _y, int _jumps):x(_x), y(_y), jumps(_jumps){}
}Point;

int minJumps(pair<int, int> source, pair<int, int> destination){
  queue<Point*> q;
  unordered_map<string, bool> visitedMap;

  q.push(new Point(source.first, source.second, 0));

  int xMoves[] = { -1, 1, -2, -2, -1, 1, 2, 2 };
  int yMoves[] = { -2, -2, -1, 1, 2, 2, -1, 1 };

  while(!q.empty()){
    Point* p = q.front();
    q.pop();
    pair<int, int> cell  = make_pair(p->x, p->y);
    string key = to_string(cell.first) + to_string(cell.second);
    if(!visitedMap[key]){
      visitedMap[key] = true;

      if(p->x == destination.first && p->y == destination.second)
        return p->jumps;

      for(int mv = 0; mv < 8; mv++){
        int newX = p->x + xMoves[mv];
        int newY = p->y + yMoves[mv];
        q.push(new Point(newX, newY, p->jumps + 1));
      }
    }
    
  }

  return -1;
}

int main(){
  
  int jumps = minJumps(make_pair(1, 1), make_pair(30, 30));
  cout << " jumps ==> " << jumps;

  return 0;
}