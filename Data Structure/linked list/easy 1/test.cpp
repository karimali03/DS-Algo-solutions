#include <iostream>
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

    void reverse_print(node* st) {
        if (!st)  return;
        reverse_print(st->next);
        cout << st->data << " ";
    }

public:
    linkedlist() : head(nullptr), tail(nullptr), len(0) {}

    void insert_back(int val) {
        node* n = new node(val);
        if (head == nullptr) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
        len++;
    }
    void reverse_print() {
        reverse_print(head);
    }
    void print(){
        for(node *cur=head;cur;cur=cur->next){
            cout<<cur->data<<" ";
        }
        cout<<"\n";
    }
    node* get_nth(int idx){
        if(idx>len||idx<=0) return nullptr;
        int cnt=1;
        for(node *cur=head;cur;cur=cur->next,cnt++){
            if(idx==cnt) return cur;
        }
    }
    int search(int val){
        int cnt=1;
        for(node *cur=head;cur;cur=cur->next,cnt++){
            if(cur->data==val) return cnt;
        }
        return -1;
    }
      int improved_search(int val){
        if(head->data==val) return 1;
        int cnt=1;
        for(node* cur=head,*prev=nullptr;prev=cur,cur;cur=cur->next,cnt++){
            if(cur->data==val) {
                swap(prev->data,cur->data);
                return cnt-1;
                }
        }
        return -1;
    }
    
};

int main() {
    linkedlist v;
    v.insert_back(15);
    v.insert_back(20);
    v.insert_back(30);
    v.insert_back(7);
    v.reverse_print();

    return 0;
}
