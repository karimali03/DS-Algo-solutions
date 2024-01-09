#include<iostream>
#include<cstring>	// memset
using namespace std;

class  iterative_trie
{
private:
    static const int MAX_CHAR = 26;
	iterative_trie* child[MAX_CHAR];
public:
     iterative_trie(){
        memset(child, 0, sizeof(child));
     };
    void insert(string str) {
        iterative_trie* ptr=this;
          int n=str.size();
        for(int i=n-1;i>=0;i--){
            int idx=str[i]-'a';
            if(ptr->child[idx]==nullptr) ptr->child[idx]=new iterative_trie();  
           ptr=ptr->child[idx];
        }

	}

	bool suffix_exist(string str, int idx = 0) {
		int n=str.size();
        auto ptr=this;
		for(int i=n-1;i>=0;i--){
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
    cout<<(root.suffix_exist("cd")==true);
    cout<<(root.suffix_exist("b")==true);
    cout<<(root.suffix_exist("yz")==true);
    cout<<(root.suffix_exist("zy")==true);
	return 0;
}
