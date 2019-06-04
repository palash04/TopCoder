#include <bits/stdc++.h>
using namespace std;

int *parent;

int quick_find(int i){
    while (i != parent[i]){
        i = parent[i];
    }
    return i;
}

void quick_union(int u,int v){
    int i = quick_find(u);
    int j = quick_find(v);
    parent[i] = j;
}

class TheSquareCityDiv2{
public:
    vector<int> find(int r, vector<int> t){
        parent = new int[t.size()];
        for (int i=0;i<t.size();i++){
            parent[i] = i;
        }
        vector<int> res;
        vector<pair<pair<int,int>,pair<int,int>>> vpp;
        vector<int> nopeeps(t.size(),1);
        int n = sqrt(t.size());
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                int now = t[i*n+j];
                int di=i;
                int dj=j;
                for (int ki=0;ki<n;ki++){
                    for (int kj=0;kj<n;kj++){
                        if ((abs(ki-i)+abs(kj-j)) <= r){
                            if (t[ki*n+kj] > now){
                                now = t[ki*n+kj];
                                di = ki;
                                dj = kj;
                            }
                        }
                    }
                }
                quick_union(i*n+j, di*n+dj);
                //vpp.push_back(make_pair(make_pair(i, j), make_pair(di, dj)));
            }
        }
        for (int i=0;i<t.size();i++){
            int j = quick_find(i);
            nopeeps[i]--;
            nopeeps[j]++;
        }
        int max = 1;
        int count=0;
        for (int i=0;i<nopeeps.size();i++){
            if (nopeeps[i] > max){
                max = nopeeps[i];
            }
            if (nopeeps[i] >= 1){
                count++;
            }
        }
        res = {count, max};
        return res;
    }
};
