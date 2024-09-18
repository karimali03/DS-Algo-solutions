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

	void del_after(Node* prev){
       
        if(prev == nullptr) del_first();
        else if(prev ->next == tail) del_back();
        else{
            auto del_node = prev->next;
			prev->next = prev->next->next;
			del(del_node);
        }
    }

	void insert_after(Node* prev, int val){
		if(prev == nullptr) insert_front(val);
		else if(prev == tail) insert_back(val);
		else{
			auto nxt = prev->next;
			prev->next = add(val);
			prev->next->next = nxt;
		}
	}

	void insertAlternate(linked_list &list){
		if(!head) {
			for(auto cur = list.head ; cur ; cur = cur->next){
				insert_back(cur->val);
			}
			return;
		};
		if(!list.head) return;
		auto cur1 = head; auto cur2 = list.head;
		while (cur1 && cur2)
		{
			auto nxt2 = cur2->next;
			insert_after(cur1 , cur2->val);
			cur1 = cur1->next->next;
			cur2 = nxt2;
		}
		if(cur2) {
			for(auto cur = cur2 ; cur ; cur = cur->next){
				insert_back(cur->val);
			}
		}
		len += list.len;
	}


};




void test1() {
	cout << "\n\ntest1\n";
	linked_list list1;

	list1.insert_back(1);
	list1.insert_back(2);
	list1.insert_back(3);

	linked_list list2;

	list2.insert_back(4);
	list2.insert_back(5);

	list1.insertAlternate(list2);

	list1.print();

	string expected = "1 4 2 5 3";
	cout<<expected<<"\n";
	cout<<"\n**************\n";
}

void test2() {
	cout << "\n\ntest2\n";
	linked_list list1;

	list1.insert_back(1);
	list1.insert_back(2);
	list1.insert_back(3);

	linked_list list2;

	list2.insert_back(4);

	list1.insertAlternate(list2);

	list1.print();

	string expected = "1 4 2 3";
	cout<<expected<<"\n";
	cout<<"\n**************\n";
}

void test3() {
	cout << "\n\ntest3\n";
	linked_list list1;

	list1.insert_back(1);
	list1.insert_back(2);
	list1.insert_back(3);

	linked_list list2;

	list2.insert_back(4);
	list2.insert_back(5);
	list2.insert_back(6);

	list1.insertAlternate(list2);

	list1.print();

	string expected = "1 4 2 5 3 6";
	cout<<expected<<"\n";
	cout<<"\n**************\n";
}

void test4() {
	cout << "\n\ntest4\n";
	linked_list list1;

	list1.insert_back(1);
	list1.insert_back(2);
	list1.insert_back(3);

	linked_list list2;

	list2.insert_back(4);
	list2.insert_back(5);
	list2.insert_back(6);
	list2.insert_back(7);

	list1.insertAlternate(list2);

	list1.print();

	string expected = "1 4 2 5 3 6 7";
	cout<<expected<<"\n";
	cout<<"\n**************\n";
}

void test5() {
	cout << "\n\ntest5\n";
	linked_list list1;

	linked_list list2;

	list2.insert_back(4);
	list2.insert_back(5);
	list2.insert_back(6);
	list2.insert_back(7);

	list1.insertAlternate(list2);

	list1.print();

	string expected = "4 5 6 7";
	cout<<expected<<"\n";
	cout<<"\n**************\n";
}



int main() {
	test1();
	test2();
	test3();
	test4();
	test5();

	// must see it, otherwise RTE
	cout << "\n\nNO RTE\n";

	return 0;
}