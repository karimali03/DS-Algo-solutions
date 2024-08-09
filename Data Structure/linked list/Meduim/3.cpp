#include <iostream>
#include <assert.h>
#include <unordered_set>
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
   

  

    void insert_back(int val){
        if(head == nullptr){
            head = tail = add(val);
        }
        else{
            tail->next = add(val);
            tail = tail->next;
        }
    }
    
    void insert_front(int val){
        if(head == nullptr) head = tail = add(val);
        else{
            auto nxt = head;
            head = add(val);
            head->next = nxt;
        }
    }

    void insert(int idx , int val){
        assert(idx >= 0 && idx <= len);
        if(idx == len) insert_back(val);
        else if(idx == 0) insert_front(val);
        else{
            for(auto cur = head ; cur ; cur = cur->next){
                if(idx == 1){
                    auto nxt = cur->next;
                    cur -> next = add(val);
                    cur -> next -> next = nxt;
                    return; 
                }
                idx--;
            }
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

    void del(int idx){
        assert(idx >= 0 && idx < len);
        if(idx == 0) del_first();
        else if(idx == len-1) del_back();
        else{
            auto cur = get_nth(idx);
            auto node = cur->next;
            cur->next = cur-> next -> next;
            del(node);
        }
    }



    void print(){
        for(auto cur = head ; cur ; cur = cur->next){
            cout<<cur->val<<" ";
        }
        cout<<"\n";
    }

    int search(int val){
         int idx = 0;
         for(auto cur = head ; cur ; cur = cur->next){
            if(val == cur->val){
                return idx;
            }
            idx++;
        }
        return -1;
    }

	bool is_same(linked_list & list){
		if(len != list.len) return false;
		for(auto cur1 = head , cur2 = list.head ; cur1 ; cur1 = cur1->next , cur2 = cur2->next ){
			if(cur1->val != cur2->val) return false;
		}
		return true;
	}

    Node* get_nth_back(int nth){
        assert(nth >= 1 && nth <= len);
        return get_nth(len - nth + 1);
    }

	void reverse(){
		if(!head || head == tail) return;

		auto prev = head;
		auto cur = head->next;

		while (cur)
		{
			auto nxt = cur->next;
			cur->next = prev;
			prev = cur;
			cur = nxt;
		}

		tail = head; tail->next = nullptr;
		head = prev;
		
	}

	void del_next(Node* node){
		if(node == tail) return;

		Node* del_node = node->next;
		node->next = node->next->next;
		if(!node->next) tail = node;
		del(del_node);

	}
	void remove_duplicates(){
		if(!head || head == tail) return;
		unordered_set<int>st;
		for(Node *cur = head , *prv = nullptr ; cur ; prv = cur ,cur = cur->next){
			if(st.count(cur->val)){
				del_next(prv);
				cur = prv;
			}
			st.insert(cur->val);
		}
		
	}

};



void test1() {
	cout<<"test1\n";
	linked_list list;

	list.insert_back(1);
	list.insert_back(2);
	list.insert_back(3);
	list.remove_duplicates();
	list.print();

	string expected = "1 2 3";
	cout<<expected<<"\n********\n";
}

void test2() {
	cout<<"test2\n";
	linked_list list;

	list.insert_back(1);
	list.insert_back(1);
	list.insert_back(2);
	list.insert_back(3);
	list.insert_back(2);
	list.remove_duplicates();
	list.print();

	string expected = "1 2 3";
	cout<<expected<<"\n********\n";
}

void test3() {
	cout<<"test3\n";
	linked_list list;

	list.insert_back(1);
	list.insert_back(2);
	list.insert_back(3);
	list.insert_back(3);
	list.insert_back(3);
	list.remove_duplicates();
	list.print();

	string expected = "1 2 3";
	cout<<expected<<"\n********\n";
}

void test4() {
	cout<<"test4\n";
	linked_list list;

	list.insert_back(1);
	list.insert_back(2);
	list.insert_back(2);
	list.insert_back(2);
	list.insert_back(3);
	list.remove_duplicates();
	list.print();

	string expected = "1 2 3";
	cout<<expected<<"\n********\n";
}

int main() {
	test1();
	test2();
	test3();
	test4();

	// must see it, otherwise RTE
		cout << "\n\nNO RTE\n";
	return 0;
}
