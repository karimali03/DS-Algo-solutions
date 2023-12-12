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

    void findMatches(string s, int i = 0){
        auto ptr =this;
        string res;
        for( ;i<s.size();i++ ){

            if(!ptr->child.count(s[i]) ) return;
             res+=s[i];

             ptr=ptr->child[s[i]];

            if(ptr->isLeaf) cout<<res<<"\n";


        }
    }
    
};



void list_substrs(const string& str, vector<string> &queries){
  
   trie t;

   for(auto x  : queries)   t.insert(x);  // O(Q * L )

     // O ( S*L )
   for( int i=0 ; i<str.size() ;i++){
     t.findMatches(str,i);
   }

}


int main() {
    
	vector<string> queries {"xy", "ab", "t", "yz"};
	list_substrs("heyabcdtwxyw", queries);

	return 0;
}
