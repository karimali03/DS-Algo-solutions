
#include <iostream>
#include <sstream>	// ostringstream
#include <cassert>
#include <vector>
#include <deque>
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
    string com (TreeNode * root,bool left){
        if(!root) return "()";
        string res="(";
        res+=to_string(root->val);
        if(left){
            res+=com(root->left,left);
            res+=com(root->right,left);
        }
        else{
            res+=com(root->right,left);
            res+=com(root->left,left);
        }
        return res;
            }
	bool isSymmetric(TreeNode *root) {
        return com(root->right,0)==com(root->left,1);
	}
};

int main() {	// rename like main1 for leetcode
	BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });

	cout << Solution().isSymmetric(tree.root) << "\n";

	return 0;
}
