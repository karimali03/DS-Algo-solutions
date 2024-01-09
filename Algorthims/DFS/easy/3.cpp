#include <iostream>
#include <vector>
#include <map>
using namespace std;



class Solution {
public:
    int CC(int n,vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n);
        int cnt=0;
        for(int i=0;i<n;i++)
        if(!vis[i]) dfs(i,adj,vis),cnt++;
        return cnt;
        }
    
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        for(auto x : adj[node]){
            if(!vis[x]) dfs(x,adj,vis);
        }
    }


};




int main(){
    int n = 5;
    vector<vector<int>> edges {{0,1},{1,2},{3,4},{2,3}};
    Solution s;
    cout<<s.CC(n,edges)<<"\n";
    return 0;
}