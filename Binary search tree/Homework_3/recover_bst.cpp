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

// o(h) memeory solution 
class Solution {
public:
    TreeNode* a={};
    TreeNode* f={};
    TreeNode* s={};
    void recoverTree(TreeNode* root) {
        inorder(root);
       swap(f->val,s->val);
    }
    void inorder(TreeNode * root){
        if(root->left) inorder(root->left);
         if(a){
             if(root->val < a->val){
                 if(f) s=root;
                 else  f=a,s=root;
             }
         }
         a=root;
        if(root->right) inorder(root->right);
    }
    
};

int main() {
    BinaryTree t(3);
	t.add({1},{'L'});
    t.add({4,2},{'R','L'});
    Solution s;
    s.recoverTree(t.root);
   
	return 0;
}
