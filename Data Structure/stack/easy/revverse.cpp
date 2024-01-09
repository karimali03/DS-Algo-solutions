#include <iostream>
#include <cassert>
#include <climits>
#include <string.h>
using namespace std;

class Stack {
private:
	// Tip: We can make this struct internally
	struct Node {
		char data { };
		Node* next { };
		Node(char data) :
				data(data) {
		}
	};

	Node *head { };		// Points to Top

public:
	~Stack() {
		while (!isEmpty())
			pop();
	}
	void display() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}

	void push(int value) {
		// By design: always new node = head
		// Great match with stack!
		Node* item = new Node(value);
		item->next = head;
		head = item;

		// Tip: This code works as long as machine has more RAM
		// In industry: You may check if return is null (can't create) or not.
	}

	char pop() {
		assert(!isEmpty());
		char element = head->data;
		Node* temp = head;
		head = head->next;
		delete temp;
		return element;
	}

	int peek() {
		assert(!isEmpty());
		int element = head->data;
		return element;
	}

	int isEmpty() {
		return !head;
	}
};

int main() {
    Stack st;
    string s;
    cout<<"enter your string";
    getline(cin,s);
    int i=0,n=s.size();
    while(i<n){
        while(i<n && s[i]!=' '){
            st.push(s[i++]);
        }
        while(i<n && s[i]==' ') i++;
        while(!st.isEmpty()){
            cout<<st.pop();
        }
        cout<<" ";
    }

	return 0;
}

