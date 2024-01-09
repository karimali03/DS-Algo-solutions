#include<iostream>
#include<cstring>	// memset
using namespace std;

class trie {
private:
	static const int MAX_CHAR = 26;
	trie* child[MAX_CHAR];
	bool isLeaf { };

public:
	trie() {
		// set an array to 0s. Here pointers to null
		memset(child, 0, sizeof(child));
	}

	void insert(string str, int idx = 0) {
		if (idx == (int) str.size())
			isLeaf = 1;
		else {
			int cur = str[idx] - 'a';
			if (child[cur] == 0)
				child[cur] = new trie();
			child[cur]->insert(str, idx + 1);
		}
	}

	bool word_exist(string str, int idx = 0) {
		if (idx == (int) str.size())
			return isLeaf;	// there is a string marked here

		int cur = str[idx] - 'a';
		if (!child[cur])
			return false;	// such path don't exist

		return child[cur]->word_exist(str, idx + 1);
	}

	bool prefix_exist(string str, int idx = 0) {
		if (idx == (int) str.size())
			return true;	// all subword covered

		int cur = str[idx] - 'a';
		if (!child[cur])
			return false;	// such path don't exist

		return child[cur]->prefix_exist(str, idx + 1);
	}
};

class  iterative_trie
{
private:
    static const int MAX_CHAR = 26;
	iterative_trie* child[MAX_CHAR];
	bool isLeaf { };
public:
     iterative_trie(){
        memset(child, 0, sizeof(child));
     };
    void insert(string str) {
        iterative_trie* ptr=this;
          int n=str.size();
        for(int i=0;i<n;i++){
            int idx=str[i]-'a';
            if(ptr->child[idx]==nullptr) ptr->child[idx]=new iterative_trie();  
           ptr=ptr->child[idx];
           if(i==n-1) ptr->isLeaf=true;
        }

	}

	bool word_exist(string str) {
        int n=str.size();
        auto ptr=this; // pointer to current class
		for(int i=0;i<n;i++){
            int idx=str[i]-'a';
            if(!ptr->child[idx]) return false;
            ptr=ptr->child[idx];
        }
        return ptr->isLeaf;
	}

	bool prefix_exist(string str, int idx = 0) {
		int n=str.size();
        auto ptr=this;
		for(int i=0;i<n;i++){
            int idx=str[i]-'a';
            if(!ptr->child[idx]) return false;
            ptr=ptr->child[idx];
        }
        return true;
	}
};

int main() {
	iterative_trie root;

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
