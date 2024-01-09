#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& c) {
        vector<vector<pair<int,int>>>v(n);
        for(auto x : c){
            v[x[0]].push_back({x[1],1});
             v[x[1]].push_back({x[0],0});
        }
        int res=0;
        vector<int>vis(n);
        dfs(0,v,vis,res);
        return res;

}
    
    void dfs(int node, vector<vector<pair<int,int>>>&v
    ,vector<int>&vis,int & res){
        vis[node]=1;
        for(auto x : v[node]){
           if(!vis[x.first]){
            dfs(x.first,v,vis,res);
            res+=x.second;
            }     
    } 

    }

};