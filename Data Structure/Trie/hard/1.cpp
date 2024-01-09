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
     trie(){};

    void insert(string str , int st = 0 ) {
          trie* ptr=this;
          int n=str.size();
        for( ; st<n ; st++ ){
            if(!ptr->child.count(str[st])) ptr->child[str[st]]=new trie();  
             ptr=ptr->child[str[st]];
           if( st == n-1 ) ptr->isLeaf=true;
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



void list_substrs(const string& str, vector<string> &queries){
    trie t;
   for(int i=0 ;i < str.size();i++){   // o(S^2)
       t.insert(str,i);
   }

   for(auto x : queries){        // O( q*L )
 
    if(t.prefix_exist(x)) 
      cout<<x<<"\n";

   }


}


int main() {

	vector<string> queries {"xy", "ab", "t", "yz"};
	list_substrs("heyabcdtwxyw", queries);

	return 0;
}
