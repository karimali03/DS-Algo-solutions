#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    pair<int,int> x1,x2,x3;
    bool isCousins(TreeNode* root, int x, int y) {
      dfs(root,x,-1,0);
      x1=x3;
       dfs(root,y,-1,0);
       x2=x3;
       if(x1.first==x2.first and x1.second !=x2.second) return true;
       else return false; 
    }
   void dfs(TreeNode* root,int x,int parent,int level){
       if(!root) return;
       if(root->val==x)  x3={level,parent};
         dfs(root->left,x,root->val,level+1) ;
         dfs(root->right,x,root->val,level+1);
    }

};
