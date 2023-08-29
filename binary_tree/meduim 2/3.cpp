
#include <iostream>
#include <sstream>	// ostringstream
#include <cassert>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string toStr(int n) {
	// Convert integer to string
	ostringstream oss;
	oss << n;
	return oss.str();
}

struct TreeNode {		// don't copy for leetcode
	int val { };
	TreeNode *left { };
	TreeNode *right { };
	TreeNode(int val) :
			val(val) {
	}
};

struct BinaryTree {
	TreeNode *root { };
	BinaryTree(int root_value) :
			root(new TreeNode(root_value)) {
	}
	void add(vector<int> values, vector<char> direction) {
		assert(values.size() == direction.size());
		TreeNode *current = this->root;
		// iterate on the path, create all necessary TreeNodes
		for (int i = 0; i < (int) values.size(); ++i) {
			if (direction[i] == 'L') {
				if (!current->left)
					current->left = new TreeNode(values[i]);
				else
					assert(current->left->val == values[i]);
				current = current->left;
			} else {
				if (!current->right)
					current->right = new TreeNode(values[i]);
				else
					assert(current->right->val == values[i]);
				current = current->right;
			}
		}
	}
};

class Solution {
public:
     map<string,int>mp;
     void duplicated(TreeNode* root){
        col(root);
        for(auto x :mp) if(x.second>1) cout<<x.first<<"\n";
 }
    bool leaf(TreeNode *root){
        return root &&!root->left &&!root->right;
    }
    string col(TreeNode* root){
        if(!root) return "()";
        string res="(";
        res+=to_string(root->val);
        res+=col(root->left);
        res+=col(root->right);
        if(!leaf(root)) mp[res]++;
        return res;
    }
    


};

int main() {	
	BinaryTree tree(1);
	tree.add( { 2, 3 }, { 'L', 'L' });
	tree.add( { 4, 5, 6, 8, 8 }, { 'R', 'R', 'R', 'R', 'R' });
	tree.add( { 4, 2, 3 }, { 'R', 'L', 'L' });
	tree.add( { 4, 5, 6 ,7 }, { 'R', 'R', 'L' ,'L' });
    tree.add( { 4, 5, 6 ,7 }, { 'R', 'R', 'R' ,'L' });
    tree.add( { 4, 5, 6 ,8 ,8 }, { 'R', 'R', 'L' ,'R' ,'R'});
    Solution s;
    s.duplicated(tree.root);
	return 0;
}
