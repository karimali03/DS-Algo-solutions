#include <iostream>
#include <cassert>
#include <math.h>
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
   int level=0,num=0;
	bool perfect(TreeNode* root){
        dfs(root,0);
        if(pow(2,level)-1==num) return true;
        return false;
    }
    void dfs(TreeNode* root,int lv=0){
        if(!root) {
            level=lv;
            return;
        }
        num++;
        dfs(root->left,lv+1);
        dfs(root->right,lv+1);
    }
};
int main() {
	BinaryTree tree(1);
     Solution s;
	tree.add( { 2}, { 'L' });
	tree.add( { 2}, { 'R' });

    cout<<s.perfect(tree.root);
   
	return 0;
}

