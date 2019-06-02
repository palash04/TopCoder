#include <bits/stdc++.h>
using namespace std;

#define UP "N"
#define DOWN "S"
#define WEST "W"
#define EAST "E"

bool isSafe(int x,int y){
    return (x>=0 && x<30 && y>=0 && y<30);
}

class VisitN{
public:
    string visit(int n, int r, int c){
        string res = "";
        int maze[30][30];
        memset(maze, -1, sizeof(maze));
        --n;
        maze[r][c] = 0;
        int next_x = r ,next_y = c;
        while (next_x > 0 && n > 0){
            next_x--;
            res += UP;
            maze[next_x][next_y] = 0;
            n--;
        }
        while (next_y > 0 && n > 0){
            next_y--;
            res += WEST;
            maze[next_x][next_y] = 0;
            n--;
        }
        int dir = 0;
        while (n>0){
            if (dir%4 == 0){
                next_y++;
                if (isSafe(next_x,next_y)){
                    res += EAST;
                    if (maze[next_x][next_y] == -1){
                        n--;
                        maze[next_x][next_y] = 0;
                    }
                }
                if (next_y == 29) dir = 1;
            }
            if (n<=0) break;
            if (dir%4 == 1 || dir%4 == 3){
                next_x++;
                if (isSafe(next_x,next_y)){
                    res += DOWN;
                    if (maze[next_x][next_y] == -1){
                        n--;
                        maze[next_x][next_y] = 0;
                    }
                }
                if (dir%4 == 1) dir = 2;
                if (dir%4 == 3) dir = 0;
            }
            if (n<=0) break;
            if (dir%4 == 2){
                next_y--;
                if (isSafe(next_x,next_y)){
                    res += WEST;
                    if (maze[next_x][next_y] == -1){
                        n--;
                        maze[next_x][next_y] = 0;
                    }
                }
                if (next_y == 0) dir = 3;
            }
        }
        return res;
    }
};

int main(){
    VisitN v;
    cout << v.visit(90, 0 , 0) << endl;
    
}
