#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    bool valid(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<int>>res(grid.size(),vector<int>(grid[0].size()));
        dfs(row,col,color,grid,res);
        return grid;
    }
    int di[4]={1,-1,0,0};
    int dj[4]={0,0,1,-1};
    void dfs(int i,int j,int color,vector<vector<int>>&g,vector<vector<int>>&vis
    ){
        int cnt=0;
        vis[i][j]=1;
        for(int d=0;d<4;d++){
            int ni=i+di[d];
            int nj=j+dj[d];
            if(valid(ni,nj,g.size(),g[0].size()) && ( g[ni][nj]==g[i][j] || vis[ni][nj] ) ){
                cnt++;
                if(!vis[ni][nj]) dfs(ni,nj,color,g,vis);
            }
        }
        if(cnt<4) g[i][j]=color;
    }
};

int main(){
    vector<vector<int>>v={{1,1,1},{1,1,1},{1,1,1}};
    Solution s;
    v =s.colorBorder(v,1,1,2);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
}