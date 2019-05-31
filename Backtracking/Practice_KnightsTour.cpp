#include <bits/stdc++.h>
using namespace std;

#define N 8

bool isSafe(int x, int y, int sol[N][N]){
    return (x>=0 && x<N && y>=0 && y<N && sol[x][y]==-1);
}

void printSolution(int sol[N][N]){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cout << sol[i][j] << "\t";
        }
        cout << endl;
    }
}

bool solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[N],int yMove[N]){
    
    if (movei == N*N){
        return true;
    }
    int next_x,next_y;
    for (int k=0;k<8;k++){
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x,next_y,sol)){
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei+1, sol, xMove, yMove))
                return true;
            else
                sol[next_x][next_y] = -1;
        }
    }
    return false;
}

void solveKT(){
    int sol[N][N];
    
    memset (sol, -1, sizeof(sol));
    
    int xMove[] = {2, 1, -1, -2, -2, -1, 1,  2  };
    int yMove[] = {1, 2, 2,  1,  -1, -2, -2, -1 };
    
    sol[0][0] = 0;
    
    if (!solveKTUtil(0, 0, 1, sol, xMove, yMove)){
        return;
    }else{
        printSolution(sol);
    }
    
}


int main(){
    solveKT();
    return 0;
}
