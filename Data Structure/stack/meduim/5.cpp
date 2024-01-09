#include <iostream>
#include <stack>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        stack<int>st;
        int n=v.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && v[st.top()] < v[i]){
                res[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};