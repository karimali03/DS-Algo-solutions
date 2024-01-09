class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adj) {
        map<int,vector<int>>v;
        for(auto x : adj ){
            v[x[0]].push_back(x[1]);
             v[x[1]].push_back(x[0]);
        }
        for(auto x : v){
            if(v[x.first].size()==1){
                vector<int>res;
                dfs(x.first,v,-1e6,res);
                return res;
            }
        }
        return {};
    }
   void dfs(int i,map<int,vector<int>>&v,int pr,vector<int>& res){
       res.push_back(i);
       for(auto x : v[i]){
           if(x!=pr) dfs(x,v,i,res);
       }
   }
};