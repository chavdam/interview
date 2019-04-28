#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    void addEdge(vector<vector<int>>& graph, int v, int u){
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    
    bool isCyclic(vector<vector<int>>& graph, vector<bool>& visited, 
                  int curr, int parent){
        visited[curr] = true;
        for(int i=0; i<graph[curr].size(); i++){
            int n = graph[curr][i];
            if(!visited[n]){
                if(isCyclic(graph, visited, n, curr))
                    return true;
            }
            else{
                if(n != parent)
                    return true;
            }
        }
        
        return false;
    }
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n);
        for(int i=0; i<edges.size(); i++){
            addEdge(graph, edges[i].first, edges[i].second);
        }
        
        vector<bool> visited(n, false);
        
        if(!isCyclic(graph, visited, 0, -1)){
            for(int i=0; i<n; i++){
                if(!visited[i])
                    return false;
            }
            return true;
        }
        
        return false;
    }
};