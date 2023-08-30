#include <iostream>
#include <cassert>
#include <vector>
#include <limits.h>
using namespace std;

struct TreeNode {
	int val { };
	TreeNode* left { };
	TreeNode* right { };
	TreeNode(int val) : val(val) { }
};


struct BinaryTree {
	TreeNode* root { };
	BinaryTree(int root_value) :
			root(new TreeNode(root_value)) {
	}

	void add(vector<int> values, vector<char> direction) {
		assert(values.size() == direction.size());
		TreeNode* current = this->root;
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

	void _print_inorder(TreeNode* current) {
		if (!current)
			return;
		_print_inorder(current->left);
		cout << current->val << " ";
		_print_inorder(current->right);
	}


	void print_inorder() {
		_print_inorder(root);
		cout << "\n";
	}

   
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool chk=true;
        if(root->left) chk&=root->val>mx(root->left);
        if(root->right) chk&=root->val<mn(root->right);
        return chk && isValidBST(root->left) &&isValidBST(root->right);
    }
    int mn(TreeNode* root){
        if(!root) return INT_MAX;
       return min(root->val,min(mn(root->right),mn(root->left)));
    }
     int mx(TreeNode* root){
        if(!root) return INT_MIN;
       return max(root->val,max(mx(root->right),mx(root->left)));
    }
};


int main(){
	return 0;
}
