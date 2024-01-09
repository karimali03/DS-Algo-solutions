class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<vector<int>>v(s.size());
        for(int i=0;i<pairs.size();i++){
            v[pairs[i][0]].push_back(pairs[i][1]);
            v[pairs[i][1]].push_back(pairs[i][0]);
        }
       string vis=s; 
       for(int i=0;i<s.size();i++){
           string res;
           vector<int>idx;
           if(vis[i]!=1){
               dfs(i,v,res,vis,s,idx);
               sort(res.begin(),res.end());
               sort(idx.begin(),idx.end());
               for(int k=0;k<idx.size();k++){
                   s[idx[k]]=res[k];
               }
               }
       }
       return s;
    }
 void dfs(int i,vector<vector<int>>&v,string& res,
 string &vis,string&s,vector<int> & idx){
     vis[i]='1';
     res+=s[i];
     idx.push_back(i);
     for(auto x : v[i]){
         if(vis[x]!='1') dfs(x,v,res,vis,s,idx);
     }
    }
};