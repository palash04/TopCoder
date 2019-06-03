#include <bits/stdc++.h>
using namespace std;

int countX;

class AliceAndBobMedium{
public:
    int count(vector<int> a){
        int xo=0;
        for (int i=0;i<a.size();i++){
            xo ^= a[i];
        }
        if (!xo) return 0;
            
        for (int i=0;i<a.size();i++){
            int xors = 0;
            for (int j=0;j<a.size();j++){
                if (j == i) continue;
                xors ^= a[j];
            }
            if (a[i]-xors > 0){
                countX++;
            }
        }
        return countX;
    }
};
