#include <bits/stdc++.h>
using namespace std;

bool solveLTUtil(vector<int> price,int imove,int sum,int x,vector<int> sol){
    
    if (sum == x){
        return true;
    }
    if (sum > x) return false;
    
    sol[imove]=1;
    
    for (int i=0;i<sol.size();i++){
        if (sol[i] == 0){
            sum += price[i];
            if (solveLTUtil(price, i, sum, x, sol)) {
                return true;
            }
            else{
                sum -= price[i];
                //sol[i] = 0;
            }
        }
    }
    
    return false;
    
}

bool solveLT(vector<int> price, int x){
    
    vector<int> sol(4,0);
    
    for (int i=0;i<4;i++){
        if (solveLTUtil(price,i,price[i],x,sol)){
            return true;
        }
    }
    return false;
}

class LotteryTicket{
  
public:
    string buy(int price,int b1,int b2,int b3,int b4){
        
        string res = "IMPOSSIBLE";
        
        vector<int> p;
        p.push_back(b1);
        p.push_back(b2);
        p.push_back(b3);
        p.push_back(b4);
        
        int x = price;
        bool isP = solveLT(p,x);
        if (isP) return "POSSIBLE";

        return res;
        
    }
    
};

int main(){
    
    LotteryTicket lt;
    cout << lt.buy(10, 1, 5, 10, 15);
    cout << endl;
    return 0;
}
