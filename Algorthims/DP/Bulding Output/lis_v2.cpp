using namespace std;
#include <iostream>
#include <bits/stdc++.h>


class Solution {
public:
    int dp[2501];
    vector<int>v;
    int rec(int i){
        int & ret = dp[i];
        if(~ret) return ret;
        ret = 0;
        for(int j = i+1; j < v.size() ;j++){
            if(v[i] < v[j])
                ret = max(ret,rec(j));
        }
        return ret = 1 + ret;
    }
     void print_rec(int i){
        if(i) cout<<v[i]<<" ";
        int optimal = rec(i);
        for(int j = i+1; j < v.size() ;j++){
            if(v[i] < v[j]){
                if(optimal == 1 + rec(j)){
                    print_rec(j);
                    return;
                }
            }
        }  
    }

    void lengthOfLIS(vector<int>& nums) {
        v = nums;
        memset(dp,-1,sizeof(dp));
        v.insert(v.begin(),INT_MIN);
        print_rec(0);
    }
};


int main(){
    Solution s; 
    vector<int> v {0,1,0,3,2,3};
    s.lengthOfLIS(v);
    return 0;
}