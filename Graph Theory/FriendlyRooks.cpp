#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<int> *adj;
public:
    Graph(int V){
        this->V = V;
        adj = new vector<int>[V];
    }
    
    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void DFSUtil(int u,bool *visited){
        visited[u] = true;
        
        for (auto i = adj[u].begin();i!=adj[u].end();i++){
            if (!visited[*i]){
                DFSUtil(*i, visited);
            }
        }
    }
    
    int DFS(bool *visited){
        int count = 0;
        for (int i=0;i<V;i++){
            if (!visited[i]){
                DFSUtil(i,visited);
                count++;
            }
        }
        return count;
    }
    
};

class FriendlyRooks{
public:
    
    int getMinFriendlyColoring(vector<string> board){
        
        int V = (int)board.size() * (int)board[0].size();
        Graph g(V);
        int nn = (int)board.size();
        int mm = (int)board[0].size();
        int bd[nn][mm];
        int val = 0;
        bool *visited = new bool[V];
        memset (visited,true,V);
        for (int i=0;i<nn;i++){
            for (int j=0;j<mm;j++){
                if (board[i][j] == 'R') visited[val] = false;
                bd[i][j] = val;
                val++;
            }
        }
        
        for (int i=0;i<nn;i++){
            for (int j=0;j<mm;j++){
                if (board[i][j] != '.') {
                    if (j<mm){
                        for (int x=j+1;x<board[0].size();x++){
                            if (board[i][x] == 'R'){
                                int u = bd[i][j];
                                int v = bd[i][x];
                                g.addEdge(u, v);
                                break;
                            }
                        }
                    }
                    if (j>0){
                        for (int x=j-1;x>=0;x--){
                            if (board[i][x] == 'R'){
                                int u = bd[i][j];
                                int v = bd[i][x];
                                g.addEdge(u, v);
                                break;
                            }
                        }
                    }
                    if (i<nn){
                        for (int x = i+1;x<board.size();x++){
                            if (board[x][j] == 'R'){
                                int u = bd[i][j];
                                int v = bd[x][j];
                                g.addEdge(u, v);
                                break;
                            }
                        }
                    }
                    if (i>0){
                        for (int x=i-1;x>=0;x--){
                            if (board[x][j] == 'R'){
                                int u = bd[i][j];
                                int v = bd[x][j];
                                g.addEdge(u, v);
                                break;
                            }
                        }
                    }
                }
            }
        }
        return g.DFS(visited);
    }
};
