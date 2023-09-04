#include<iostream>
#include<cstring>	// memset
#include <vector>
#include <sstream>  // stringstream
using namespace std;

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

	pair<bool,int> word_exist(string str) {
        int n=str.size();
        auto ptr=this; // pointer to current class
		for(int i=0;i<n;i++){
            if(ptr->isLeaf) return {true,i};
            int idx=str[i]-'a';
            if(!ptr->child[idx]) return {false,0};
            ptr=ptr->child[idx];
        }
        return {false,0};
	}

	
};

class Solution {
   private:
      iterative_trie t; 
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
       for(auto x: dictionary)   t.insert(x);
       string res;
       stringstream str(sentence);
       string word;
       int b=0;
       while(str >> word){
           if(b) res+=" ";
           b=1;
           pair<bool,int> p=t.word_exist(word);
           if(p.first){
               res+=word.substr(0,p.second);
           }
           else res+=word;
          
       }
       return res;
    }

};

int main(){
    
}
