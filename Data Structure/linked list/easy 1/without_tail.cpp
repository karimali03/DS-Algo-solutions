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
          n->next=head;
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



int main() {

	LinkedList list;

	list.insert(10);
	list.insert(20);
	list.insert(30);
	list.insert(40);
	list.insert(50);
	list.insert(60);

	list.print();	// 60 50 40 30 20 10
	cout<<list.get_tail()->data;	// 10

	return 0;
}
