#include <bits/stdc++.h>
using namespace std;

int grid[400][600];
vector<int> res;
int countA;

bool isSafe(int x,int y){
    return (x>=0 && x<400 && y>=0 && y<600 && !grid[x][y]);
}

void DFSUtil(int x,int y){
    
    stack<pair<int,int>> st;
    st.push(make_pair(x, y));
    
    while (!st.empty()){
        x = st.top().first;
        y = st.top().second;
        st.pop();
        
        if (!grid[x][y]){
            grid[x][y] = 1;
            countA++;
        }
        if (isSafe(x-1,y)){
            st.push(make_pair(x-1, y));
        }
        if (isSafe(x+1, y)){
            st.push(make_pair(x+1, y));
        }
        if (isSafe(x, y-1)){
            st.push(make_pair(x, y-1));
        }
        if (isSafe(x, y+1)){
            st.push(make_pair(x, y+1));
        }
    }
}

void DFS(){
    for (int i=0;i<400;i++){
        for (int j=0;j<600;j++){
            if (!grid[i][j]){
                DFSUtil(i,j);
                res.push_back(countA);
                countA=0;
            }
        }
    }
}

class grafixMask{
public:
    vector<int> sortedAreas(vector<string> rectangles){
        memset (grid,0,sizeof(grid));
        
        for (int i=0;i<rectangles.size();i++){
            string s = rectangles[i];
            int arr[4];
            int idx=0;
            string word = "";
            for (auto x:s){
                if (x == ' '){
                    arr[idx] = stoi(word);
                    word = "";
                    idx++;
                }else{
                    word = word + x;
                }
            }
            arr[idx] = stoi(word);
            for (int x = arr[0];x<=arr[2];x++){
                for (int y=arr[1];y<=arr[3];y++){
                    grid[x][y] = 1;
                }
            }
        }
        DFS();
        sort(res.begin(),res.end());
        return res;
    }
};
