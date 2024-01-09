#include <iostream>
#include <cassert>
#include <vector>
#include <deque>
#include <queue>
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
       int dia=0;
      int tree_dia(TreeNode* root){
        height(root);
        return dia;
    }
      int height(TreeNode* root){
        if(!root) return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        dia=max(dia,lh+rh);
        return 1+max(lh,rh);
      }
};
int main() {
	BinaryTree tree(3);
     Solution s;
	tree.add( { 2, 4 }, { 'L','L' });
	tree.add({3,7} , {'R','R'});
	tree.add({2,5} , {'L','R'});
    cout<<s.tree_dia(tree.root);
	return 0;
}
