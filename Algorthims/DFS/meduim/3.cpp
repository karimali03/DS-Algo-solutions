class Solution {
public:
    bool valid(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
            if(grid[i][j]==0){
                bool take=true;
                dfs(i,j,grid,take);
                res+=take;
            }
        }
        return res;
    }
    int di[4]={0,0,-1,1};
    int dj[4]={1,-1,0,0};
void dfs(int i,int j,vector<vector<int>>&g,bool &take){
        g[i][j]=-1;
 if(i==0||j==0||i==g.size()-1 || j==g[0].size()-1)         take=false;
        for(int d=0;d<4;d++){
        int ni=i+di[d];
        int nj=j+dj[d];
      if(valid(ni,nj,g.size(),g[0].size())
        && g[ni][nj]==0)  dfs(ni,nj,g,take);
        }
    }
};