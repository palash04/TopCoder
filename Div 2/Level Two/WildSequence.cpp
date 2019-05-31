#include <bits/stdc++.h>
using namespace std;

class WildSequence{
public:
    vector<int> construct(int head, vector<int> rest){
        vector<int> res;
        res.push_back(head);
        if (res.size() == 0) return res;

        sort(rest.begin(),rest.end());
        
        int start = rest[0];
        int end = rest[rest.size()-1];
        
        if (head < start){
            int in = 1;
            while (rest.size() != 0){
                if (in){
                    res.push_back(rest[rest.size()-1]);
                    rest.pop_back();
                    in = 0;
                }else{
                    res.push_back(rest[0]);
                    rest.erase(rest.begin());
                    in = 1;
                }
            }
        }else if (head > end){
            int in = 0;
            while (rest.size() != 0){
                if (!in){
                    res.push_back(rest[0]);
                    rest.erase(rest.begin());
                    in = 1;
                }else{
                    res.push_back(rest[rest.size()-1]);
                    rest.pop_back();
                    in = 0;
                }
            }
        }else{
            int in = 0;
            while (rest.size() != 0){
                if (!in){
                    res.push_back(rest[0]);
                    rest.erase(rest.begin());
                    in = 1;
                }else{
                    res.push_back(rest[rest.size()-1]);
                    rest.pop_back();
                    in = 0;
                }
            }
        }
        return res;
    }
};

//int main(){
//    
//    WildSequence w;
//    vector<int> rest = {1, 2, 3, 6, 7, 5};
//    vector<int> res = w.construct(4, rest);
//    for (auto i=res.begin();i!=res.end();i++){
//        cout << *i << " ";
//    }
//    cout << endl;
//    return 0;
//    
//}
