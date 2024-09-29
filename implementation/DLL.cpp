#include <iostream>
#include <cassert>
#include <climits>
#include <vector>		
#include <algorithm>
#include <sstream>
using namespace std;

struct Node
{
    int val;
    Node *prev,*next;
    Node(int val , Node* prev = nullptr,  Node* next = nullptr)
     : val(val) , prev(prev),next(next) {}
};


class DLL {
    private:
    Node* tail;
    int len;

    void del(Node* node){
            delete node;
            len--;
    }

    Node* add(int val){
        len++;
		auto node = new Node(val);
        return node;
    }
   
    public:
    Node* head;
    DLL(){
        head = tail = nullptr;
        len = 0;
    }
    ~DLL(){
        Node* temp = head;
        while(temp){
            Node* next = temp->next;
            del(temp);
            temp = next;
        }
    }

    void print(){
        for(auto cur = head;cur;cur=cur->next)  cout<<cur->val<<" ";
        cout<<"\n";
    }

    void print_reverse(){
        for(auto cur=tail;cur;cur=cur->prev) cout<<cur->val<<" ";
        cout<<"\n";
    }

    void link(Node* one , Node* two){
        if(one) one->next = two;
        else head = two;
        if(two) two->prev = one;
        else tail = one;
    }

    void insert_back(int val){
        auto node = add(val);
        if(!head){
            head = tail = node;
        }
        else{
            link(tail , node);
            tail = node;
        }
    }

    void insert_front(int val){
        auto node = add(val);
        if(!head){
            head = tail = node;
        }
        else{
            link(node, head);
            head = node;
        }
    }

    void insert_after(Node* prev , int val){
        if(!prev) insert_front(val);
        else{
            auto node = add(val);
            auto nxt = prev->next;
            link(prev , node);
            link(node , nxt );
        }
    }

    void insert_sorted(int val){
        if(!head || val >= tail->val ) insert_back(val);
        else if(val <= head->val) insert_front(val);
        else{
            for(auto cur = head ; cur ; cur=cur->next){
                if(cur->val >= val){
                    insert_after(cur->prev , val);
                    return;
                }
            }
        }
    }

    void del_front(){
        if(!head) return;
        auto node = head;
        if(head == tail) head = tail = nullptr;
        else {
            head = head ->next;
            head->prev = nullptr;
        }
        del(node);
    }

    void del_back(){
        if(!head) return;
        auto node = head;
        if(head == tail) head = tail = nullptr;
        else{
            tail = tail->prev;
            tail->next = nullptr;
        }
        del(node);
    }

    Node* del_and_link(Node* cur){
        if(!cur) return {};
        Node* node = cur;
        Node* ret = cur->prev;
        link(cur->prev,cur->next);
        del(node);
        return ret;
    }

    void del_node_with_key(int val){
        if(!head) return;
        for(auto cur = head ; cur ; cur = cur->next){
            if(cur->val == val){
                del_and_link(cur);
                return;
            }
        }
    }

    void reverse(){
        Node* cur=head;
        swap(head,tail);
        while (cur)
        {
           swap(cur->next,cur->prev);
           cur=cur->prev;
        }
    }
    
    void merge_sorted(DLL& list){
        auto cur1 = head;
        auto cur2 = list.head;
        Node *prv = nullptr;
        while(cur1 && cur2){
            if(cur1->val >= cur2->val){
                insert_after(prv , cur2->val);
                cur2 = cur2->next;
                if(prv) cur1 = prv->next;
                else cur1 = head;
            } 
            else{
                prv = cur1;
                cur1 = cur1->next;
            }
          
          
        }
        while (cur2)
        {
            insert_after(tail , cur2->val);
            cur2 = cur2->next;
        }
        
    }
};


int main(){
    DLL st;
    st.insert_back(10);
    st.insert_back(20);
    st.insert_back(30);
    st.insert_front(1);
    st.print();
    st.print_reverse();
    st.del_node_with_key(10);
    st.print();
    return 0;
}