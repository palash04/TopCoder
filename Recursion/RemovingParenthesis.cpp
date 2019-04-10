#include <bits/stdc++.h>
using namespace std;

static int cWays = 0;

bool isSafe(vector<char> v){
    stack<char> st;
    
    for (int i=0;i<v.size();i++){
        if (v[i] == '('){
            st.push(v[i]);
            continue;
        }
        
        // closing bracket first
        if (st.empty()){
            return false;
        }
        
        if (v[i] == ')'){
            st.pop();
        }
    }
    
    return (st.empty());
}

void solve(vector<char> v){
    
    if (v.size() == 0){
        cWays++;
        return;
    }
    
    for (int i=1;i<v.size();i++){
        vector<char> v1 = v;
        if (v1[i] == ')'){
            v1.erase(v1.begin()+i);
            v1.erase(v1.begin());
            if(isSafe(v1)){
                solve(v1);
            }
        }
    }
}

class RemovingParenthesis{
public:
    int countWays(string s){
        vector<char> v(s.begin(),s.end());
        solve(v);
        return cWays;
    }
};

int main(){
    
    string s;
    cin>>s;
    
    RemovingParenthesis r;
    cout << r.countWays(s) << endl;
    
    return 0;
    
}
