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
		 int ret = -1;
         for(auto cur = head ; cur ; cur = cur->next){
            if(val == cur->val){
                ret = idx;
            }
            idx++;
        }
        return ret;
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

	void delete_last_occurrence(int val){
		if(!head) return;
		int idx = search(val);
		if(idx == -1) return;
		del(idx);
	}

};



void test1() {
	cout << "\n\ntest1\n";
	linked_list list;

	list.insert_back(1);
	list.insert_back(2);
	list.insert_back(3);
	list.delete_last_occurrence(1);
	// some actions
	list.print();

	string expected = "2 3";
	cout<<expected<<"\n**********\n";

}

void test2() {
	cout << "\n\ntest2\n";
	linked_list list;

	list.insert_back(1);
	list.insert_back(2);
	list.insert_back(3);
	list.insert_back(1);
	list.insert_back(4);
	list.delete_last_occurrence(1);
	list.print();

	string expected = "1 2 3 4";
	cout<<expected<<"\n**********\n";
}

void test3() {
	cout << "\n\ntest3\n";
	linked_list list;

	list.insert_back(1);
	list.insert_back(2);
	list.insert_back(3);
	list.insert_back(4);
	list.insert_back(1);
	list.delete_last_occurrence(1);
	list.print();

	string expected = "1 2 3 4";
	cout<<expected<<"\n**********\n";
}

void test4() {
	cout << "\n\ntest4\n";
	linked_list list;

	list.insert_back(1);
	list.insert_back(2);
	list.insert_back(3);
	list.insert_back(4);
	list.delete_last_occurrence(7);
	list.print();

	string expected = "1 2 3 4";
	cout<<expected<<"\n**********\n";
}

int main() {
	test1();
	test2();
	test3();
	test4();

	// must see it, otherwise RTE
	cout << "\n\nNO RTE\n";

}