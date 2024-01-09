#include <iostream>
#include <cassert>
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

    void insert_back(int val,Node* cur={},bool firstTime=true){
        if(firstTime){
            insert_back(val,head,false);
        }
        else{
            if(!cur){
                  Node* add=new Node(val);
                  head=add;
                  return;
            }
            if(!cur->next){
                Node* add=new Node(val);
                cur->next=add;
                return;
            }
            insert_back(val,cur->next,firstTime);
        }
    }

    Node* reverse(Node* cur={},bool firstTime=true){
          if(firstTime){
            return  reverse(head,false);
        }
        else{
            if(!cur) return {};
            if(!cur->next){
                head=cur;
                return cur;
            }
            else{
                Node* rest=reverse(cur->next,firstTime);
                rest->next=cur;
                cur->next=nullptr;
                return cur;
            }
        }
    }

};



int main(){
   
	Stack stk;
	stk.push(10);

    stk.reverse();
    stk.print();
	return 0;
}