class Solution {
public:
   bool valid(int i,int j,int n,int m){
       return i>=0 && j>=0 && i<n && j<m;
   }
    bool containsCycle(vector<vector<char>>& grid) {
    vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j]){
                    bool c=false;
                    dfs(i,j,grid,vis,c);
                    if(c) return true;
                }
            }
        }
        return false;
    }
    int di[4]={0,0,-1,1};
    int dj[4]={1,-1,0,0};
    void dfs(int i,int j,vector<vector<char>>&g,
    vector<vector<int>>&vis,bool & c,int pi=-1,int pj=-1){
        vis[i][j]=1;
        for(int d=0;d<4;d++){
            int ni=i+di[d];
            int nj=j+dj[d];
         if(ni==pi && nj==pj) continue;   
         if(valid(ni,nj,g.size(),g[0].size())
         && g[i][j]==g[ni][nj]){
             if(!vis[ni][nj])
             dfs(ni,nj,g,vis,c,i,j);
             else c=true;
            }
        }
    }
};