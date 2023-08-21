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
	int maxValue(TreeNode *root) {
		if (!root)
			return 0;

		int lrmx = max(maxValue(root->left),maxValue(root->right));
		return max(lrmx,root->val);
	}
};
int main() {
	BinaryTree tree(1);
     Solution s;
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
    cout<<s.maxValue(tree.root)<<"\n";
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });

    cout<<s.maxValue(tree.root)<<"\n";
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });

    cout<<s.maxValue(tree.root)<<"\n";
	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });
    cout<<s.maxValue(tree.root)<<"\n";
   
	return 0;
}
