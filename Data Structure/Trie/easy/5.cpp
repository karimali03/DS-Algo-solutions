#include<iostream>
#include<cstring>	// memset
#include<map>
#include <vector>
using namespace std;

class  trie
{
private:
    map<string,trie*>child;
public:
     trie(){
     };
    void insert(vector<string> & str) {
          trie* ptr=this;
          int n=str.size();
        for(int i=0;i<n;i++){
            if(!ptr->child.count(str[i])) ptr->child[str[i]]=new trie();  
           ptr=ptr->child[str[i]];
        }

	}
	bool path_exist(vector<string> & str) {
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
    vector<string>v={"Karim","Home","Projects","DS Course","Trie"};
    root.insert(v);
    vector<string>path={"Karim"};
    cout<<root.path_exist(path)<<"\n";
     path={"Karim","Cpp"}; 
    cout<<root.path_exist(path)<<"\n";
    path={"Karim","Home","Projects"};
    cout<<root.path_exist(path)<<"\n";
	return 0;
}
