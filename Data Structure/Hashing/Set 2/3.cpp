#include<iostream>
using namespace std;
#include <unordered_set> 
#include <vector>
#include <algorithm>
int disSub(string & s){
    unordered_set<string>st;
    int sz=s.size();
    for(int i=0;i<sz;i++){
       string res;
        int cnt=i;
        for(int j=i+1;j<=sz;j++){
            res+=s[cnt++];
            sort(res.begin(),res.end());
            st.insert(res);
        }
    }
    return st.size();
}

int main(){
    string s="aabade"; 
    cout<<disSub(s)<<"\n";
}
