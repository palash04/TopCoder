#include <bits/stdc++.h>
using namespace std;

#define N 8

bool isSafe(int board[N][N],int row, int col){
    for (int i=0;i<col;i++){
        if (board[row][i]){
            return false;
        }
    }
    for (int i=row,j=col;i>=0 && j>=0;i--,j--){
        if (board[i][j]) return false;
    }
    for (int i=row,j=col;i<N && j>=0;i++,j--){
        if (board[i][j]) return false;
    }
    return true;
}

void printSolution(int board[N][N]){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool solveNQUtil(int board[N][N],int col){
    if (col == N){
        printSolution(board);
        return true;
    }
    bool res = false;
    
    for (int i=0;i<N;i++){
        if (isSafe(board,i,col)){
            board[i][col] = 1;
            res = solveNQUtil(board, col+1) || res;
            board[i][col] = 0;
        }
    }
    return res;
}

void solveNQ(){
    int board[N][N];
    memset(board,0,sizeof(board));
    
    if (!solveNQUtil(board,0)){
        cout << "Solution doesn't exits\n";
        return;
    }
    
}

int main(){
    solveNQ();
    return 0;
}
