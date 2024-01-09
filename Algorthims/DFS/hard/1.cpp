#include <vector>
#include <iostream>
using namespace std;



class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
   vector<int>vis(g.size());
    bool stop=false;
    for(int i=0;i<g.size();i++)
     {
        if(!vis[i]) dfs(i,vis,g,1,stop);
        if(stop) return false;
     }
     return true;
    }

    void dfs(int node,vector<int>&vis,
     vector<vector<int>>&adj,int v,bool & st){
       vis[node]=v;
       for(auto x : adj[node]){
           if(!vis[x]) dfs(x,vis,adj,3-v,st);
            if(vis[x]==vis[node]) st=true;
       }
    }

};