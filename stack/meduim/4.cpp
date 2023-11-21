#include <iostream>
#include <cassert>
using namespace std;
#include <stack>



class Solution {
public:
   
    int scoreOfParentheses(string s) {
        int res=0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' && s[i+1]==')') {
                res+=1<<cnt;
                i++;
            }
            else if(s[i]=='(') cnt++;
            else cnt--; 
        }
        return res;
    }
};