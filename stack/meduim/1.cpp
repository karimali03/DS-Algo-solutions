#include <iostream>
#include <cassert>
using namespace std;
#include <vector>
#include<stack>

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        stack<int>st;
        
        st.push(v[0]);
        for(int i=1;i<v.size();i++){ 
           if(st.empty()) st.push(v[i]); 
           else if(st.top()*v[i] > 0) st.push(v[i]);
           else if(st.top() < 0) st.push(v[i]);
           else{
               while(!st.empty() && st.top()
               < abs(v[i]) && st.top() > 0) st.pop();
               if(st.empty() || st.top()<0) st.push(v[i]);
               if(!st.empty() && v[i]==-st.top()) st.pop();
           }
        }
        vector<int>res(st.size());
        for(int i=(int)st.size()-1 ;i>=0;i--){
            res[i]=st.top();
            st.pop();
        }
        return res;
    }
};