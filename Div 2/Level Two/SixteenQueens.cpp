#include <bits/stdc++.h>
using namespace std;

#define N 50
int board[N][N];
vector<pair<int,int>> vp;
int addQ;
vector<int> res;
set<int> co;

class SixteenQueens{
public:
    vector<int> addQueens(vector<int> row, vector<int> col, int add);
};


bool isSafe(int row, int col){
    // go left
    for (int i=0;i<col;i++){
        if (board[row][i]){
            return false;
        }
    }
    
    // go right
    for (int i=col+1;i<50;i++){
        if (board[row][i]){
            return false;
        }
    }
    
    // go up
    for (int i=0;i<row;i++){
        if (board[i][col]){
            return false;
        }
    }
    
    // go down
    for (int i=row+1;i<50;i++){
        if (board[i][col]) return false;
    }
    
    for (int i=row,j=col;i>=0 && j>=0; i--,j--){
        if (board[i][j]) return false;
    }
    
    for (int i=row,j=col;i<N && j>=0; i++,j--){
        if (board[i][j]) return false;
    }
    
    for (int i=row,j=col;i>=0 && j<N;i--,j++){
        if (board[i][j]) return false;
    }
    for (int i=row,j=col;i<N && j<N;i++,j++){
        if (board[i][j]) return false;
    }
    return true;
}

bool solveQueens(int col){
    if (col>=N || addQ==0) {
        return true;
    }
    for (int i=0;i<N;i++){
        if (co.count(col)>0) {
            col++;
        }
        if (isSafe(i, col)){
            board[i][col] = 1;
            vp.push_back(make_pair(i, col));
            addQ--;
            if (co.count(col+1) > 0) col++;
            if (solveQueens(col+1)){
                return true;
            }else{
                board[i][col] = 0;
                vp.pop_back();
                addQ++;
            }
            
        }
    }
    return false;
}

vector<int> SixteenQueens :: addQueens(vector<int> row, vector<int> col, int add){
    
    memset (board, 0, sizeof(board));
    addQ = add;
    
    for (int i=0;i<row.size();i++){
        board[row[i]][col[i]] = 1;
        co.insert(col[i]);
    }
    solveQueens(0);
    for (auto x: vp){
        res.push_back(x.first);
        res.push_back(x.second);
    }
    return res;
}
