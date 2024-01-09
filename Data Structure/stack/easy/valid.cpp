#include <iostream>
#include <cassert>
#include <stack>
using namespace std;


class Stack
{
private:
    struct Node
    {
       int data {};
       Node* next {};
       Node(int data):data(data){};
    };
    Node *head {};
public:
    ~Stack(){
        while(!empty()) pop();
    }

    void print(){
        for(auto cur=head;cur;cur=cur->next)
        cout<<cur->data<<" ";
        cout<<"\n";
    }

    void push(int val){
        Node * add=new Node(val);
        add->next=head;
        head=add;
    }
    int pop(){
        assert(head);
        int val=head->data;
        Node* del = head;
        head=head->next;
        delete del; 
        return val;
    }

    int top(){
        assert(head);
        return head->data;
    }

    bool empty(){
        return !head;
    }
};



int main(){

    string s="abbaca";
    stack<char> st;
    int i=0;
    int n=s.size();
    while(i<n){
        bool rm=0;
        st.push(s[i++]);
        while (i<n && st.top()==s[i])   i++,rm=1;
        if(rm) st.pop();
    }
    while(!st.empty()) cout<<st.top(),st.pop();
	return 0;
}