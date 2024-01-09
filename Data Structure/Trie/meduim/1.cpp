#include<iostream>
#include<cstring>	// memset
#include<map>
#include<vector>
using namespace std;

class  trie
{
private:
    map<char,trie*>child;
    bool isLeaf {};
public:
     trie(){
     };
    void insert(string str) {
          trie* ptr=this;
          int n=str.size();
        for(int i=0;i<n;i++){
            if(!ptr->child.count(str[i])) ptr->child[str[i]]=new trie();  
             ptr=ptr->child[str[i]];
           if(i==n-1) ptr->isLeaf=true;
        }

	}

	bool word_exist(string str) {
        int n=str.size();
        auto ptr=this; // pointer to current class
		for(int i=0;i<n;i++){
            if(!ptr->child.count(str[i])) return false;
            ptr=ptr->child[str[i]];
        }
        return ptr->isLeaf;
	}

	bool prefix_exist(string str) {
		int n=str.size();
        auto ptr=this;
		for(int i=0;i<n;i++){
            if(!ptr->child.count(str[i])) return false;
            ptr=ptr->child[str[i]];
        }
        return true;
	}
    void get_all_strings(vector<string> & res ,string s=""){
        if(isLeaf) res.push_back(s);
        for(auto & x : child){
            x.second->get_all_strings(res,s+x.first);
        }
    }
};

int main() {
	trie tree;

    tree.insert("abcd");
	tree.insert("xyz");
	tree.insert("a");
	tree.insert("ab");
	tree.insert("xyzw");
	tree.insert("bcd");

	vector<string> res;
	tree.get_all_strings(res);
	for (int i = 0; i < (int) res.size(); ++i)
		cout << res[i] << "\n";
	return 0;
}
