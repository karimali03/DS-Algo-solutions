#include <iostream>
#include <cassert>
#include <climits>

#include <vector>		// for debug
#include <algorithm>
#include <sstream>
using namespace std;

struct node {
    int data;
    node* next;
    node(int data) : data(data), next(nullptr) {} // constructor
};

class linkedlist {
private:
    node* head;
    node* tail;
    int len;
    
public:
    linkedlist() : head(nullptr), tail(nullptr), len(0) {}

    void insert_back(int val) {
        node* n = new node(val);
        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
        len++;
    }
    void insert_front(int val){
        node* n=new node(val);
        if (!head) {
            head = tail = n;
        } 
        else{
            n->next=head;
            head=n;
        }

    }
    void print(){
        for(node *cur=head;cur;cur=cur->next){
            cout<<cur->data<<" ";
        }
        cout<<"\n";
    }
   
};

int main() {
    linkedlist v;
    v.insert_back(15);
    v.insert_back(20);
    v.insert_back(30);
    v.insert_back(7);
     v.print();
    v.insert_front(1);
    v.insert_front(2);
    v.insert_front(3);
    v.insert_front(4);
    v.print();
    return 0;
}
