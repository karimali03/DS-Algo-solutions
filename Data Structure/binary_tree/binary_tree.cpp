#include <iostream>
#include <sstream>	
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;


struct TreeNode {
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
   
    void inorder(TreeNode* root){
		if(root->left) inorder(root->left);
		cout<<root->val;
		if(root->right) inorder(root->right);
	}
    void _inorder(){
		inorder(root);
	}
	 void preorder(TreeNode* root){
		cout<<root->val;
		if(root->left)  preorder(root->left);
		if(root->right)  preorder(root->right);
	}
    void _preorder(){
		preorder(root);
	}
	 void postorder(TreeNode* root){
		if(root->left) postorder(root->left);
		if(root->right) postorder(root->right);
		cout<<root->val;
	}
    void _postorder(){
		postorder(root);
	}
	void level_order_traversal(){
		queue<TreeNode*>q;
		q.push(root);
		while(!q.empty()){
			int sz=q.size();
			while(sz--){
				auto x=q.front();
				q.pop();
				cout<<x->val<<" ";
				if(x->left) q.push(x->left);
				if(x->right) q.push(x->right);
			}
			cout<<"\n";
		}
	}
	
	
	string parenthesize() {
		return _parenthesize(root);
	}

	string _parenthesize(TreeNode *root) {
		if (!root)
			return "()";

		string repr = "(" + to_string(root->val);

		if (root->left)
			repr += _parenthesize(root->left);
		
		if (root->right)
			repr += _parenthesize(root->right);
	
		repr += ")";

		return repr;
	}

	string parenthesize_canonical() {
		return _parenthesize_canonical(root);
	}

	string _parenthesize_canonical(TreeNode *root) {
		if (!root)
			return "()";

		string repr = "(" + to_string(root->val);

		vector<string> v;

		if (left)
			v.push_back(_parenthesize_canonical(root->left));
		
		if (right)
			v.push_back(_parenthesize_canonical(root->right));
	

		sort(v.begin(), v.end());
		for (int i = 0; i < (int) v.size(); ++i)
			repr += v[i];

		repr += ")";

		return repr;
	}
};

bool isLeaf(TreeNode *node) {
	return node && !node->left && !node->right;
}



int main() {
	
	return 0;
}
