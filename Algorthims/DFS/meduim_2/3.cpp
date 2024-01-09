class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        unordered_map<int,int>vis;
        for(int i=0;i<nums.size();i++){
           st.insert(nums[i]);
        }
        int mx=0;
        for(auto x : st){
            if(!vis[x]){
                int cnt=dfs(x,st,vis);
                mx=max(mx,cnt);
            }
        }
        return mx;
        }
    
    int dfs(int i,unordered_set<int>&st,unordered_map<int,int>&vis){
        int cnt=1;
        vis[i]=1;
        if(st.count(i+1) && !vis[i+1]) cnt+=dfs(i+1,st,vis);
        if(st.count(i-1) && !vis[i-1]) cnt+=dfs(i-1,st,vis);
        return cnt;
    }
};