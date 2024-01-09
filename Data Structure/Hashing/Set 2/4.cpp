#include <iostream>
#include <cassert>
#include<unordered_set>
using namespace std;



struct Node {
    int data {};
    Node* next { };
    Node(int data) :data(data) {

    }
};



class LinkedList {
private:
	Node *head { };
	Node *tail { };
	int length = 0;
public:
	void print() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}
	void insert_end(int value) {
		Node* item = new Node(value);

		if (!head)
			head = tail = item;
		else {
			tail->next = item;
			tail = item;
		}
		++length;
	}

	void create_cycle() {
		for (int i = 0; i < 4; ++i)
			insert_end(i);
		Node* now = tail;
		for (int i = 0; i < 3; ++i)
			insert_end(14 + i);
		
        tail->next = now;// cycle
	}

	void remove_cycle() {
		// set of addresses
		unordered_set<Node*> visited;

		for (auto  cur = head; cur->next ; cur=cur->next) {
			if(visited.count(cur->next)) {
			   cur->next={};
               tail=cur;
			}
			visited.insert(cur);
		}
	}
};


int main() {
	LinkedList lst;
	lst.create_cycle();
	lst.remove_cycle();
	lst.print();
	// 0 1 2 3 14 15 16

	return 0;
}
