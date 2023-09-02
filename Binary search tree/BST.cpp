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


struct BST {
	TreeNode* root { };
	BST(int root_value) :
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

	bool _search(TreeNode* root, int target) {	// tail recursion
		if(!root)
			return false;

		if (target == root->val)
			return true;

		if (target < root->val)
			return _search(root->left, target);

		return _search(root->right, target);
	}
	bool search(int target) {
		return _search(root, target);
	}

	TreeNode* _insert(TreeNode* root,int val){
		if(!root) 	return new TreeNode(val);
		if(val > root->val) root->right=_insert(root->right,val);
		else if(val < root->val) root->left=_insert(root->left,val);
		return root;
	}
	void insert(int val){
		_insert(root,val);
	}
 
   TreeNode* min_value(TreeNode* cur){
	while(cur && cur->left) cur=cur->left;
	return cur;
   }
   TreeNode* max_value(TreeNode* cur){
	while(cur && cur->right) cur=cur->right;
	return cur;
   }
   // successor code
   bool find_chain(TreeNode* root, int target, vector<TreeNode*> &ancestors) {
		ancestors.push_back(root);

		if (target == root->val)
			return true;

		if (target < root->val)
			return find_chain(root->left, target, ancestors);

		return root->right && find_chain(root->right, target, ancestors);
	}
	TreeNode* get_next(vector<TreeNode*> &ancestors) {
		if (ancestors.empty()) 	return nullptr;
		TreeNode* node = ancestors.back();	// last element
		ancestors.pop_back();
		return node;
	}
	pair<bool, int> successor(int target) {
		vector<TreeNode*> ancestors;

		if (!find_chain(root, target, ancestors))	// not exist
			return make_pair(false, -1);

		TreeNode* child = get_next(ancestors);

		if (child->right)	// must have it in min of right
			return make_pair(true, min_value(child->right)->val);

		TreeNode* parent = get_next(ancestors);

		// Cancel chain of ancestors I am BIGGER than them
		while (parent && parent->right == child)
			child = parent, parent = get_next(ancestors);

		if (parent)	
			return make_pair(true, parent->val);
		return make_pair(false, -1);
	}
    TreeNode* _del_node(TreeNode* root,int val){
		if(!root) return {};
		if(val > root->val) root->right=_del_node(root->right,val);
		else if(val < root->val) root->left=_del_node(root->left,val);
		else{
			auto del=root;
			if(!root->left && !root->right) root=nullptr;
			else if(!root->left) root=root->right;
			else if(!root->right) root=root->left;
			else{
				auto mn=min_value(root->right);
				root->val=mn->val;
				root->right=_del_node(root->right,root->val);
				del=nullptr;
			}
			if(del) delete del;
		}
		return root;
	}
	
    void del_node(int val){
		root=_del_node(root,val);
	}

};


int main() {
	BST tree(50);
	tree.insert(20);
	tree.insert(45);
	tree.insert(70);
	tree.insert(73);
	tree.insert(35);
	tree.insert(15);
	tree.insert(60);

	tree.print_inorder();
	return 0;
}
