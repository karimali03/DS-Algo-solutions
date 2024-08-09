#include <iostream>
#include <assert.h>
using namespace std;


class linked_list

{
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
    linked_list(){
        head = tail = nullptr;
        len = 0;
    };

	~linked_list() {		
		while(head){
			Node* nxt = head->next;
			del(head);
			head = nxt;
		}
	}
   

  
    void insert(int val){
        if(head == nullptr){
            head = tail = add(val);
        }
		else if(val <= head->val){
			auto nxt = head;
			head = add(val);
			head->next = nxt;
		}
        else{
            for(Node* cur = head , *prv = nullptr ; cur ; prv = cur ,cur = cur->next){
				if(cur->val >= val){
						prv->next = add(val);
						prv->next->next = cur;
						return;
				}
			}
			tail->next = add(val);
			tail = tail->next;
        }
    }
    
    Node* get_nth(int nth){
        /* nth form 1 to len */
        assert(nth > 0 && nth <= len);
        for(auto cur = head ; cur ; cur = cur->next){
            if(nth == 1) return cur;
            nth--;
        }
        return {};
    }

    void del_first(){
        assert(head);
        auto node = head;
        if(head == tail) head = tail = nullptr;
        else head = head->next;
        del(node);
    }

    void del_back(){
        assert(head);
        auto node = tail;
        if(head == tail) head = tail = nullptr;
        else {
            auto cur = get_nth(len  - 1);
            tail = cur;
            cur -> next = nullptr;
        }
        del(node);
    }

	void print(){
		for(auto cur = head ; cur ; cur = cur->next){
			cout<<cur->val<<" ";
		}
		cout<<"\n";
	}

    



};


/*
	Implement: void insert_sorted(int value)
	It will always insert the value in position so that list is sorted
	Let’s insert values: 10 2 30 4 1
	insert(10) ⇒ {10}
	insert(2) ⇒ {2, 10}
	insert(30) ⇒ {2, 10, 30}
	insert(4) ⇒ {2, 4, 10, 30}
	insert(1) ⇒ {1, 2, 4, 10, 30}
*/


void test1() {
	cout << "test1\n";
	linked_list list;

	list.insert(10);
	list.insert(2);
	list.insert(30);
	list.insert(4);
	list.insert(1);

	// some actions
	list.print();

	string expected = "2 4 10 30";
	cout<<expected<<"\n********\n";
}


int main() {
	test1();

	cout << "bye\n";		// must see it, otherwise RTE
	return 0;
}
