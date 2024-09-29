#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;


class Queue {
private:
    struct Node
    {
        int val;
        Node* next;
        Node(int val):val(val){ next = nullptr;};
    };
    Node* head;
    Node* tail;
    int len;

    Node* add(int val){
        len++;
		auto node = new Node(val);
        return node;
    }
    
    void del(Node* node){
        len--;
        delete node;
    }
    
public:
    Queue(){
        head = tail = nullptr;
        len = 0;
    };

	~Queue() {		
		while(head){
			Node* nxt = head->next;
			del(head);
			head = nxt;
		}
	}
   
    void push(int val){
        if(head == nullptr){
            head = tail = add(val);
        }
        else{
            tail->next = add(val);
            tail = tail->next;
        }
    }

    int front(){
        assert(head);
        return head->val;
    }

    void pop(){
        assert(head);
        auto node = head;
        if(head == tail) head = tail = nullptr;
        else head = head->next;
        del(node);
    }

    void print(){
        for(auto cur = head ; cur ; cur = cur->next){
            cout<<cur->val<<" ";
        }
        cout<<"\n";
    }
};





int main() {
	cout << "\n\nNO RTE\n";		// must see it, otherwise RTE
	return 0;
}