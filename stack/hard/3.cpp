#include <iostream>
#include <math.h>
#include <cassert>
using namespace std;



template <class T>
class Stack
{
private:
    struct Node
    {
       T data {};
       Node* next {};
       Node* prv {};
       Node(T data):data(data){};
    };
    Node *head {};
    Node* mid {};
    int length {};
public:
    ~Stack(){
        while(!empty()) pop();
    }

    void print(){

        for(auto cur=head;cur;cur=cur->next){
        if(cur == mid) cout<<"["<<cur->data<<"] ";
        else cout<<cur->data<<" ";
        }
        cout<<"\n";
    }

    void link(Node* one,Node* two){
        if(one) one->next=two;
        if(two) two->prv=one;
    }
    void push(T val){
        Node * add=new Node(val);
        link(add,head);
        head=add;
        length++;

        // handling mid
        if(length<=1) mid=head;
        else if(length&1)  mid=mid->prv;

    }
    T pop(){
        assert(head);
        T val=head->data;
        Node* del = head;
        head=head->next;
        length--;
        delete del; 

        // handling mid
        if(length%2==0) mid=mid->next;

        return val;
    }

    T top(){
        assert(head);
        return head->data;
    }
  
    bool empty(){
        return !head;
    }
};



int main(){

    Stack<int> st;
    for(int i=0;i<10;i++) {
        st.push(i);
        st.print();
    }
    cout<<"\n\n";
    while(!st.empty()){
        st.pop();
        st.print();
    }
	return 0;
}