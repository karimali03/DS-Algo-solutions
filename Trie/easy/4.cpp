#include<iostream>
#include<cstring>	// memset
#include<map>
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
};

int main() {
	trie root;

	root.insert("abcd");
	root.insert("xyz");
	root.insert("abf");
	root.insert("xn");
	root.insert("ab");
	root.insert("bcd");

	cout << root.word_exist("xyz") << "\n";
	cout << root.word_exist("xy") << "\n";
	cout << root.prefix_exist("xy") << "\n";
   
	return 0;
}
