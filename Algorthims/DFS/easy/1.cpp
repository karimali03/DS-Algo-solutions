#include <iostream>
#include <vector>
#include <map>
using namespace std;



class Solution {
public:
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        map<int,vector<int>>mp;
        for(int i=0;i<pid.size();i++){
            if(ppid[i]==0) continue;
            mp[ppid[i]].push_back(pid[i]);
        }

        vector<int>res;
        dfs(kill,res,mp);

        return res;
    }

    void dfs(int node,vector<int> &res, map<int,vector<int>> & mp){
        res.push_back(node);
        for(auto x : mp[node]) dfs(x,res,mp);
    }


};




int main(){
    vector<int> PID = {1, 2, 3}, PPID = {0,1,1};
    int killID = 2;
    Solution s; 
    vector<int> res=s.killProcess(PID,PPID,killID);
    for(auto & x : res){
        cout<<x<<" ";
    }

    return 0;
}