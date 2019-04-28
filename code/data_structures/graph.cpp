#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void addEdge(unordered_map<int, vector<int> >& adjList, int p1, int p2){
  adjList[p1].push_back(p2);
  adjList[p2].push_back(p1);
}

void DFSUtil(unordered_map<int, vector<int> >& adjList, unordered_map<int, bool>& visited, int u){
  visited[u] = true;
  cout << u << "  ";
  for(int i=0;i < adjList[u].size();i++){
    if(!visited[adjList[u][i]]){
      DFSUtil(adjList, visited, adjList[u][i]);
    }
  }
}

void DFS(unordered_map<int, vector<int> >& adjList){
  unordered_map<int, bool> visited;
  for(unordered_map<int, vector<int> >::iterator it = adjList.begin(); it != adjList.end(); ++it){
    if(!visited[it->first]){
      DFSUtil(adjList, visited, it->first);
    }
  }
}


int main(){
  unsigned short V = 10;

  unordered_map<int, vector<int> > adjList;
  addEdge(adjList, 5, 2);
  addEdge(adjList, 5, 8);
  addEdge(adjList, 2, 11);
  addEdge(adjList, 11, 15);
  addEdge(adjList, 8, 15);
  addEdge(adjList, 9, 8);
  addEdge(adjList, 9, 7);
  addEdge(adjList, 15, 3);
  addEdge(adjList, 7, 4);
  addEdge(adjList, 7, 3);
  addEdge(adjList, 3, 6);
  
  DFS(adjList);

  return 0;
}

unordered_map<string, User*> graph;

void add_edge(unordered_map<string, User*>& graph, User* u1, User* u2){
  if(!graph[u1->id]){
    graph[u1->id] = u1;
  }
  if(!graph[u2->id]){
    graph[u2->id] = u2;
  }
  graph[u1->id]->conn.push_back(u2);
}

typedef struct User{
  string id;
  string email;
  string name;
  vector<User*> conn;
}User;

unordered_map<string, bool> visited;