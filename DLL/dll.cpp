#include <iostream>
#include <cassert>
#include <climits>

#include <vector>		// for debug
#include <algorithm>
#include <sstream>
using namespace std;

struct Node {
	int data { };
	Node* next { };
	Node* prev { };	 // Previous node!

	Node(int data) : data(data) {}

	void set(Node* next, Node* prev) {
		this->next = next;
		this->prev = prev;
	}

	~Node() {
		cout << "Destroy value: " << data << " at address " << this << "\n";
	}
};

class LinkedList {
private:
	Node *head { };
	Node *tail { };
	int length = 0;

public:

	// Below 2 deletes prevent copy and assign to avoid this mistake
	LinkedList() {
	}
	LinkedList(const LinkedList&) = delete;
	LinkedList &operator=(const LinkedList &another) = delete;

	void print() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}

	// These 2 simple functions just to not forget changing the vector and length
	void delete_node(Node* node) {
		--length;
		delete node;
	}

	void add_node(Node* node) {
		++length;
	}

	void link(Node* first, Node*second) {
		if(first)
			first->next = second;
		if(second)
			second->prev = first;
	}

	void insert_end(int value) {
		Node* item = new Node(value);
		add_node(item);

		if (!head)
			head = tail = item;
		else {
			link(tail, item);
			tail = item;
		}
	}

	void insert_front(int value) {
		Node* item = new Node(value);
		add_node(item);

		if (!head)
			head = tail = item;
		else {
			link(item, head);
			head = item;
		}
		
	}

	void print_reversed()  {
		for (Node* cur = tail; cur; cur = cur->prev)
			cout << cur->data << " ";
		cout << "\n";
	}

	void delete_front() {
		if(!head)
			return;
		Node* cur = head->next;
		delete_node(head);
		head = cur;

		// Integrity change
		if(head)
			head->prev = nullptr;
		else if(!length)
			tail = nullptr;

		
	}

	void delete_end() {
		if(!head)
			return;
		Node* cur = tail->prev;
		delete_node(tail);
		tail = cur;

		// Integrity change
		if(tail)
			tail->next = nullptr;
		else if(!length)
			head = nullptr;

	
	}

	Node* delete_and_link(Node* cur) {
		// remove this node, but connect its neighbors
		Node* ret = cur->prev;
		link(cur->prev, cur->next);
		delete_node(cur);

		return ret;
	}

	void delete_node_with_key(int value) {
		if (!length)
			return;
		else {
			for (Node *cur = head; cur; cur = cur->next) {
				if (cur->data == value) {
					cur = delete_and_link(cur);
					if (!cur->next)	  tail = cur;
                    if(!cur) head=cur;
				}
			}
		}
		
	}

	void del_all_key(int val){
        if(!head) return;
        insert_front(-val); // dummy node 
        for(auto cur=head->next;cur;cur=cur->next){
            if(val==cur->data){
                cur=delete_and_link(cur);
                if(!cur->next) tail=cur;
            }
        }
        delete_front(); // delete dummy node
    }
};

void test1() {
	cout << "\n\ntest1\n";
	LinkedList list;

	list.insert_end(3);
	list.insert_end(5);
	list.insert_end(7);
    list.insert_end(5);
	list.insert_end(7);
    list.del_all_key(7);
	list.print();
    list.print_reversed();
}

int main() {
	test1();
	
	// must see it, otherwise RTE
	cout << "\n\nNO RTE\n";

	return 0;
}

