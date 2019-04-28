#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<fstream>
#include<unordered_map>

using namespace std;


vector<string> split_string(string);

int getMinIndex(vector<int>& d, vector<bool>& visited){
    int min = INT_MAX, minIndex = -1;
    for(int i = 0; i<d.size(); i++){
        if(!visited[i] && min > d[i]){
            min = d[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void addEdge(vector<vector<pair<int, int>>>& graph, int u, int v, int w){
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}

// Complete the prims function below.
int prims(int n, vector<vector<int>>& edges, int start) {
    vector<vector<pair<int, int>>> graph(n);
    vector<int> d(n, INT_MAX);
    vector<bool> v(n, false);
    int sum = 0;

    for(int i=0; i<edges.size(); i++){
        addEdge(graph, edges[i][0]-1, edges[i][1]-1, edges[i][2]);
    }

    d[start-1] = 0;

    for(int u=0;u<n;u++){
        int k = getMinIndex(d, v);
        v[k] = true;
        sum += d[k];
        
        for(int j=0; j<graph[k].size(); j++){
            int x = graph[k][j].first;
            int w = graph[k][j].second;

            if(!v[x] && d[x] > w){
                d[x] = w;
            }
        }
    }
    
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int start;
    cin >> start;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = prims(n, edges, start);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
