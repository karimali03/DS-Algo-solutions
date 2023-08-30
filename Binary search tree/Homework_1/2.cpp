
#include <iostream>
#include <cassert>
#include <vector>
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
	TreeNode* sortedArrayToBST(vector<int> v){
        int sz=v.size();
        auto root=link({},0,sz-1,v);
        return root;
    }
    TreeNode* link(TreeNode *root,int l,int r,vector<int>& v){
           int mid=l+(r-l)/2;
           if(l>r) return {}; 
           root=new TreeNode(v[mid]);
           root->left=link(root->left,l,mid-1,v);
           root->right=link(root->right,mid+1,r,v);
           return root;
    }
 
};
int main() {
   
	return 0;
}
