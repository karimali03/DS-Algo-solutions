#include <iostream>
#include <cassert>
#include <vector>
#include <deque>
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
   void print(TreeNode* root){
      deque<TreeNode*>q;
      q.push_front(root);
      int b=1;
	  // 1  push back l r
	  // 0  push front r l
      while(!q.empty()){
        int sz=q.size();
        if(b){
               while(sz--){
            auto x =q.front();
            q.pop_front();
            cout<<x->val<<" ";
            if(x->left) q.push_back(x->left);
            if(x->right) q.push_back(x->right);
        }
        }
        else{
          while(sz--){
            auto x =q.back();
            q.pop_back();
            cout<<x->val<<" ";
            if(x->right) q.push_front(x->right);
			 if(x->left) q.push_front(x->left);
         }
        }
        b=!b;
        cout<<"\n";
      }
   }

	
};
int main() {
	BinaryTree tree(3);
     Solution s;
	tree.add( { 20, 7 }, { 'R', 'R' });
	tree.add( { 9 }, { 'L' });
	tree.add( { 20, 15 }, { 'R', 'L' });
    s.print(tree.root);
	return 0;
}
