using namespace std;
#include <iostream>
#include <bits/stdc++.h>


class Solution {
public:
    int dp[501][501];
    string a,b; 
    int rec(int i,int j){
        if(i == a.size()) return b.size()-j;
        if(j == b.size()) return a.size()-i;

        int & ret = dp[i][j];
        if(~ret) return ret;

        if(a[i] == b[j]) return ret = rec(i+1,j+1);

        int remove = 1 + rec(i+1,j);
        int insert = 1 + rec(i,j+1);
        int change = 1 + rec(i+1,j+1);
        return ret = min({remove,change,insert}); 
    }

    void print_rec(int i,int j){
        
        if(i == a.size()){
            while (j < b.size())
            {
                 cout<<"remove at index "<<j<<" from string b \n";
                 j++;
            }
            return;
        }

        if(j == b.size()){
            while (i < a.size())
            {
                 cout<<"remove at index "<<i<<" from string a \n";
                 i++;
            }
            return;
        }


        if(a[i] == b[j]){
            print_rec(i+1,j+1);
            return;
        }

        int optimal = rec(i,j);


        int remove = 1 + rec(i+1,j);
        int insert = 1 + rec(i,j+1);
        

        if(optimal == remove){
            cout<<"remove at index "<<i<<" from string a \n";
            print_rec(i+1,j);
        }
        else if(optimal == insert){
             cout<<"insert at index "<<i<<" from string a \n";
            print_rec(i,j+1);
        }
        else {
            cout<<"replace at index "<<i<<" from string a "<<"\n";
            print_rec(i+1,j+1);
        }
        
        return;
    }
    
    
    int minDistance(string word1, string word2) {
        a = word1;
        b = word2;
        memset(dp,-1,sizeof(dp));
        print_rec(0,0);
        return rec(0,0);
    }
};


int main(){
    Solution s; 
    string a = "horse";
    string b = "ros" ;
    s.minDistance(a,b);
    return 0;
}