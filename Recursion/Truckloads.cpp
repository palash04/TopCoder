#include <bits/stdc++.h>
using namespace std;

int solveTL(int n,int ls){
    
    if (n <= ls) return 1;
    
    else {
        if (n%2 == 0){
            return solveTL(n/2, ls) + solveTL(n/2, ls);
        }else{
            return solveTL(n/2, ls) + solveTL(n/2+1, ls);
        }
    }
    
}

class TruckLoads{
public:
    int numTrucks(int numCrates,int loadSize){
        return solveTL(numCrates, loadSize);
    }
};

int main(){
    
    TruckLoads tl;
    int res = tl.numTrucks(9999, 2);
    
    cout << res << endl;
    
    return 0;
}
