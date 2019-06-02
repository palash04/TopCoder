#include <bits/stdc++.h>
using namespace std;

set<long> st;
int countS;

class MagicNumbersAgain{
public:
    int count(long A,long B);
};

bool isSafe(string s){
    int ini = stoi(to_string(s[0]));
    for (int i=1;i<s.size();i++){
        int num = stoi(to_string(s[i]));
        if (i%2 != 0){
            if (num<=ini) return false;
            ini = num;
        }
        else{
            if (num >= ini) return false;
            ini = num;
        }
    }
    return true;
}

int MagicNumbersAgain::count(long A, long B){
    
    int max = 1e5;
    for (long long i=1;i<=max;i++){
        long long x = i*i;
        if (x > B) break;
        if (x < A) continue;
        
        string s = "";
        while (x>0){
            int a = x % 10;
            s.push_back(a+'0');
            x = x/10;
        }
        reverse(s.begin(),s.end());
        if (isSafe(s)){
            countS++;
        }
        
    }

    return countS;
}
