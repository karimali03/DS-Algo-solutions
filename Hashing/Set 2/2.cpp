#include<iostream>
using namespace std;
#include <unordered_set> 

int comSub(string & s1 , string & s2){
    unordered_set<string>st1,st2;
    int sz=s1.size();
    for(int i=0;i<sz;i++){
        string res;
        int cnt=i;
        for(int j=i+1;j<=sz;j++){
        res+=s1[cnt++];
        st1.insert(res);
        }
    }
    
    sz=s2.size();
    for(int i=0;i<sz;i++){
        string res;
        int cnt=i;
        for(int j=i+1;j<=sz;j++){
        res+=s2[cnt++];
        st2.insert(res);
        }
    }
    unordered_set<string>res;
    int cnt=0;
    for(auto & x : st1) res.insert(x);
    for(auto & x : st2) if(res.count(x)) cnt++;
    return cnt;
}

int main(){
    string s1="aaaaa";
    string s2="aaaaa";
    cout<<comSub(s1,s2)<<"\n";
}
