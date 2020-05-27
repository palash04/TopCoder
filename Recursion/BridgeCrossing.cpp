#include <bits/stdc++.h>
using namespace std;

class BridgeCrossing{
    int minTimeTaken = INT_MAX;
public:
    
    void helper(vector<int> times,vector<bool> visited,vector<pair<int,int>> space,int n,int currTimeTaken){
        
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                if (!visited[i] && !visited[j]){
                    visited[i] = true;
                    visited[j] = true;
                    vector<pair<int,int>> spaceCpy = space;
                    space.push_back({times[i],i});
                    space.push_back({times[j],j});
                    int a = max(times[i],times[j]);
                    currTimeTaken += a;
                    if (space.size() == n){
                        if (currTimeTaken < minTimeTaken){
                            minTimeTaken = currTimeTaken;
                        }
                        return;
                    }
                    sort(space.begin(),space.end());
                    visited[space[0].second] = false;
                    int b = space[0].first;
                    currTimeTaken += b;
                    space.erase(space.begin());
                    helper(times, visited, space, n, currTimeTaken);
                    currTimeTaken -= (a + b);
                    visited[i] = false;
                    visited[j] = false;
                    space = spaceCpy;
                }
            }
        }
    }
    
    int minTime(vector<int> times){
        int n = (int)times.size();
        if (n == 1) return times[0];
        vector<bool> visited(n,false);
        vector<pair<int,int>> space;
        helper(times,visited,space,n,0);
        return minTimeTaken;
    }
};
