#include <iostream>
#include <cassert>
#include <climits>
#include <vector>		// for debug
#include <algorithm>
#include <sstream>
#include <unordered_set>
using namespace std;

struct Node {
	int data { };
	Node* next { };
	Node(int data) : data(data) {}
	~Node() {
		cout << "Destroy value: " << data <<" at address "<< this<< "\n";
	}
};

class LinkedList {
private:
	Node* head { };
	Node* tail { };
	int length = 0;	// let's maintain how many nodes

	vector<Node*> debug_data;	// add/remove nodes you use

	void debug_add_node(Node* node) {
		debug_data.push_back(node);
	}
	void debug_remove_node(Node* node) {
		auto it =find(debug_data.begin(), debug_data.end(), node);
		if (it == debug_data.end())
			cout << "Node does not exist\n";
		else
			debug_data.erase(it);
	}

public:

	// Below 2 deletes prevent copy and assign to avoid this mistake
	LinkedList() {
	}
	  LinkedList(const LinkedList&) = delete;
	  LinkedList &operator=(const LinkedList &another) = delete;

	void debug_print_address() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur << "," << cur->data << "\t";
		cout << "\n";
	}

	void print() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << "address: "<<cur<<" Data: "<<cur->data << "\n";
		cout << "\n";
	}

	// These 2 simple functions just to not forget changing the vector and length
	void delete_node(Node* node) {
		debug_remove_node(node);
		--length;
		delete node;
	}

	void add_node(Node* node) {
		debug_add_node(node);
		++length;
	}

	void insert_end(int value) {
		Node* item = new Node(value);
		add_node(item);

		if (!head)
			head = tail = item;
		else
			tail->next = item, tail = item;
	}
	void insert_front(int value) {		
		Node* item = new Node(value);
		add_node(item);

		item->next = head;
		head = item;

		if(length == 1) tail = head;

	}
    
    void delete_front(){
    if(!head){
        head=tail=nullptr;
    }
    else if(head==tail){
        delete_node(head);
        head=tail=nullptr;
    }
    else{
        Node* d=head;
        head=head->next;
        delete_node(d);
    }
   }

   Node* addBack(Node *cur,Node* prv){
    if(cur==tail) return cur;
      tail->next=cur;
      Node* nxt=cur->next;
      tail=tail->next;
      tail->next=nullptr;
      if(prv) prv->next=nxt;
      else head=nxt;
      return nxt;
   }
   void moveBack(int key){
      if(!head || head==tail) return;
      int len=length;
      for(Node *cur=head,*prv=nullptr;len--;){
        if( cur->data == key ){
            cur=addBack(cur,prv);
        }
        else{
            prv=cur;
            cur=cur->next;
        }
      }
   }
    
};

void test1() {
	cout << "\n\ntest1\n";
	LinkedList list;
    list.insert_front(1);
   
	list.print();
    list.moveBack(1);
    list.print();
    
}

int main() {
	 test1();
	// must see it, otherwise RTE
	cout << "\n\nNO RTE\n";

	return 0;
}
