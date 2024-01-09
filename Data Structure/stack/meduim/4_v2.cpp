#include <iostream>
#include <cassert>
using namespace std;
#include <stack>





class Solution {
public:
   
    int scoreOfParentheses(string s) {
       stack<int>st;
       st.push(0);
       for(int i=0;i<s.size();i++){
           if(s[i]=='(') st.push(0);
           else{
               int last=st.top();
               st.pop();
               if(last==0) last=1;
               else last*=2;
               int ans=st.top()+last;
               st.pop();
               st.push(ans);
           }
       }
       return st.top();
    }
};