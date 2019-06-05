#include <bits/stdc++.h>
using namespace std;

vector<int> *adj;
set<int> st;
vector<int> gv;
int countDistinctGrps;
int N;
bool oddLength = false;

void addEdge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSUtil(int u, bool *visited){
    
    stack<int> stk;
    stk.push(u);
    
    while (!stk.empty()){
        int u = stk.top();
        stk.pop();
        
        if (!visited[u]){
            visited[u] = true;
            st.insert(u);
        }
        
        for (auto i=adj[u].begin();i!=adj[u].end();i++){
            if (!visited[*i]){
                stk.push(*i);
            }
        }
    }
    
}
int src;
bool checkForOddLength(){
    if (st.size() == 0 || st.size() == 1 || st.size() == 2) return false;
    int colorArr[50];
    memset (colorArr, -1, sizeof(colorArr));
    
    for (auto s:st){
        src = s;
        break;
    }
    colorArr[src] = 1;
    queue<int> q;
    q.push(src);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        
        for (auto i = adj[u].begin();i!=adj[u].end();i++){
            if (colorArr[*i] == -1){
                colorArr[*i] = 1 - colorArr[u];
                q.push(*i);
            }
            else if (colorArr[u] == colorArr[*i]){
                return true;
            }
        }
    }
    return false;
}

void DFS(){
    
    bool *visited = new bool[N];
    memset (visited, false, N);
    
    for (int i=0;i<N;i++){
        if (!visited[i]){
            st.clear();
            DFSUtil(i,visited);
            if (!checkForOddLength()){
                countDistinctGrps++;
            }else{
                oddLength = true;
                break;
            }
        }
    }
}

class Marketing{
public:
    long howMany(vector<string> compete){
        long res;
        N = (int)compete.size();
        adj = new vector<int>[N];
        for (int i=0;i<N;i++){
            vector<int> v;
            string word="";
            for (auto x:compete[i]){
                if (x == ' '){
                    v.push_back(stoi(word));
                    word="";
                }
                word = word + x;
            }
            if (word != "") v.push_back(stoi(word));
            for (auto x:v){
                addEdge(i, x);
            }
        }

        DFS();
        if (oddLength) return -1;
        res = pow(2, countDistinctGrps);
        return res;
    }
};
