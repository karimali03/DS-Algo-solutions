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
      bool complete(TreeNode* root){
		int d=depth(root);
		// cout<<d<<"\n";
		queue<TreeNode*>q;
		q.push(root);
		int st=0;
		while(!q.empty()){
			int sz=q.size();
			d--;
			if(d>1){
			while(sz--){
				auto x=q.front();
				q.pop();
				if(x->left) q.push(x->left);
		        else return false;
				if(x->right) q.push(x->right);
				else return false;
			}
			}
			else{
				while(!q.empty()){
					auto x=q.front();
				    q.pop();
					if(!x->left) st=1;
					else if(st) return false;
					if(!x->right) st=1;
					else if(st) return false;
				}
				break;
			}
		}
		return true;
	  }

	  int depth(TreeNode*root){
		if(!root) return 0;
		return max(depth(root->left),depth(root->right))+1;
	  }   
};
int main() {
	BinaryTree tree(3);
     Solution s;
	tree.add( { 2, 4 }, { 'L','L' });
	tree.add({3,7} , {'R','R'});
	tree.add({2,5} , {'L','R'});
    cout<<s.complete(tree.root);
	return 0;
}
