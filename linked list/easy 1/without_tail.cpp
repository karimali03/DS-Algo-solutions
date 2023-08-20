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
	Node(int data) : data(data) {}
	~Node() {
		cout << "Destroy value: " << data <<" at address "<< this<< "\n";
	}
};

class LinkedList {
private:
	Node *head { };


public:
	void print() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}
    void insert(int val){
        Node* n=new Node(val);
         if(!head) head=n;
         else{
           head=head->next;
           head=n;
        }
    }
    Node* get_tail(){
        auto tail=head;
        while(tail->next){
            tail=tail->next;
        }
        return tail;
    }
};

void test1() {
	cout << "\n\ntest1\n";
	LinkedList list;

	

}

void test2() {
	cout << "\n\ntest2\n";
	LinkedList list;
    
}


int main() {
	test1();
	test2();

	// must see it, otherwise RTE
	cout << "\n\nNO RTE\n";

	return 0;
}
