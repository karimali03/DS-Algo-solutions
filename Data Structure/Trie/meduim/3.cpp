#include<iostream>
#include<cstring>	// memset
#include<map>
#include<vector>
using namespace std;


class MagicDictionary {
private:
        map<char, MagicDictionary*>child;
        bool isLeaf {};
public:
    MagicDictionary() {
           
    }
    
    void buildDict(vector<string> dictionary) {
       for(auto x : dictionary){
         auto ptr=this;
          int n=x.size();
        for(int i=0;i<n;i++){
            if(!ptr->child.count(x[i])) 
        ptr->child[x[i]]=new MagicDictionary();  
        ptr=ptr->child[x[i]];
        if(i==n-1) ptr->isLeaf=true;
           }
    }
    }
    
    bool search(string word,int idx=0,bool sk=1){
        if(idx==word.size()) return isLeaf&&!sk;
        if(sk){
            for(char ch='a';ch<='z';ch++){
                if(ch==word[idx]) continue;
                if(child.count(ch))
                if(child[ch]->search(word,idx+1,0))
                return true;
            }
        }
    if(!child.count(word[idx]))
        return false;
    if(child[word[idx]]->search(word,idx+1,sk))
        return true;
        
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */