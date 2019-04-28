#include<iostream>
#include<vector>

using namespace std;

void insertEdge(vector<vector<pair<int, int> > >& graph, int v1, int v2, int weight){
  graph[v1][v2] = make_pair(v2, weight);
  graph[v2][v1] = make_pair(v1, weight);
}

int min_distance(vector<int>& distance, vector<bool> & visited){
  int minVal = INT_MAX ;
  int minIndex = 0;
  int i=0;

  for(vector<int>::iterator it = distance.begin(); it != distance.end(); ++it){
    if(!visited[i]  && minVal > *it){
      minVal = *it;
      minIndex = i;
    }
    i++;
  }

  return minIndex;

}

void print(vector<int> d){
  for(int i=0;i<d.size();i++){
    cout << i << " ->  " << d[i] << endl;
  }
}

void shortestPath(vector<vector<pair<int, int> > >& graph, int src, vector<int>& distance){
  int V = graph.size();

  vector<int> d(V, INT_MAX);
  vector<bool> sptSet(V, false);

  d[src] = 0;

  for(int i=0;i<V-1;i++){
    int u = min_distance(d, sptSet);
    sptSet[u] = true;

    for(int vi = 0; vi<V; vi++){
      //cout << " u = " << u << ", vi = " << vi << ", graph[u][vi].second = "  << graph[u][vi].second << endl;
      if(graph[u][vi].second != 0 && !sptSet[vi] &&  graph[u][vi].second + d[u] < d[vi]){
        d[vi] = graph[u][vi].second + d[u];
      }
    }
  }

  distance = d;
}

int main(){
  int V = 9;
  vector<int> distance(V);

  vector<pair<int, int> > pairs(V, make_pair(0,0));
  vector<vector<pair<int, int> > > graph(V, pairs);
  insertEdge(graph, 0, 1, 4);
  insertEdge(graph, 0, 7, 8);
  insertEdge(graph, 1, 2, 8);
  insertEdge(graph, 1, 7, 11);
  insertEdge(graph, 7, 8, 7);
  insertEdge(graph, 7, 6, 1);
  insertEdge(graph, 2, 8, 2);
  insertEdge(graph, 6, 8, 6);
  insertEdge(graph, 6, 5, 2);
  insertEdge(graph, 2, 5, 4);
  insertEdge(graph, 2, 3, 7);
  insertEdge(graph, 5, 3, 14);
  insertEdge(graph, 3, 4, 9);
  insertEdge(graph, 5, 4, 10);

  shortestPath(graph, 0, distance);

  print(distance);

  return 0;
}