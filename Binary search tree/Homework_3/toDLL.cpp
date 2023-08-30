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

    pair<TreeNode*,TreeNode*> toDLL(TreeNode* root) {
        if(!root) return {nullptr,nullptr};
         pair<TreeNode*,TreeNode*>left=toDLL(root->left);
         pair<TreeNode*,TreeNode*>right=toDLL(root->right);
         TreeNode* head=root;
         TreeNode* tail=root;
         if(left.first){
            left.second->right=head;
			head->left=left.second;
			head=left.first;
         }
         if(right.first){
			tail->right=right.first;
			right.first->left=tail;
			tail=right.second;
         }
		 return {head,tail};
    }
	pair<TreeNode*,TreeNode*> DLL(TreeNode *root){
		if(!root) return {nullptr,nullptr};
		 pair<TreeNode*,TreeNode*> p=toDLL(root);
		 p.second->right=p.first;
		 p.first->left=p.second;
		 return p;
	}
   
};

int main() {
    
	return 0;
}
