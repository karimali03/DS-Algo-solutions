#include<vector>
#include <iostream>
#include <unordered_map>
using namespace std;


class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
public:

     unordered_map<int,Employee*>mp;
    int getImportance(vector<Employee*> employees, int id) {

        for(auto & x : employees){
            mp[x->id]=x;
        }
        return dfs(id);
    }
    int dfs(int id){
        int res=0;
        for(auto & x : mp[id]->subordinates)
         res+=dfs(x);
        return mp[id]->importance + res;
    }
};