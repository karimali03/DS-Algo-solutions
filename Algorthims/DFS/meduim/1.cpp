class Solution {
public:
    bool valid(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int res=0;
       for(int i=0;i<grid2.size();i++){
           for(int j=0;j<grid2[0].size();j++){
              if(grid2[i][j]==1){
               bool take=true;
               dfs(i,j,grid1,grid2,take);
               res+=take;
               }
           }
       }
       return res; 
    }
const int di[4]={0, 0, 1, -1};
const int dj[4]={1, -1, 0, 0};
  void dfs( int i,int j,vector< vector<int> >& g1
    ,vector< vector<int> >&g2 ,bool & take ) {
        if(g2[i][j]!=g1[i][j]) take=false;
        g2[i][j]=-1;
        for(int d=0;d<4;d++){
            int ni=i+di[d];
            int nj=j+dj[d];
    if(valid(ni,nj,g2.size(),g2[0].size()) && g2[ni][nj]==1)
            dfs(ni,nj,g1,g2,take);
        }
    }
};