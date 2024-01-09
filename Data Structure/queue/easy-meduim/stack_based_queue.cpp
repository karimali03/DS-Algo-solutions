#include <iostream>
#include <cassert>
#include<queue>
using namespace std;

class Queue {
	int size { };
	int front { 0 };
	int rear { 0 };
	int added_elements { };
	int *array { };

public:
	Queue(int size) :
			size(size) {
		array = new int[size];
	}

	~Queue() {
		delete[] array;
	}

	int next(int pos) {
		++pos;
		if (pos == size)
			pos = 0;
		return pos;
		//return (pos + 1) % size;	//  Or shorter way
	}

	void enqueue(int value) {
		assert(!isFull());
		array[rear] = value;
		rear = next(rear);
		added_elements++;
	}

	int dequeue() {
		assert(!isEmpty());
		int value = array[front];
		front = next(front);
		--added_elements;
		return value;
	}

	void display() {
		cout << "Front " << front << " - rear " << rear << "\t";
		if (isFull())
			cout << "full";
		else if (isEmpty()) {
			cout << "empty\n\n";
			return;
		}
		cout << "\n";

		for (int cur = front, step = 0; step < added_elements; ++step, cur = next(cur))
			cout << array[cur] << " ";
		cout << "\n\n";
	}

	int isEmpty() {
		return added_elements == 0;
	}

	bool isFull() {
		return added_elements == size;
	}
};
 
class Stack
{
private:
    queue<int> q;
    int added_elements{0} ;
public:
    
    void push(int val){
       q.push(val);  
       added_elements++;
    }
    void pop(){
        for(int i=0;i<added_elements-1;i++){
            int val=q.front();
            q.pop();
            q.push(val);
        }
        q.pop();
        added_elements-- ;
    }

    int peek(){
       for(int i=0;i<added_elements-1;i++){
            int val=q.front();
            q.pop();
            q.push(val);
        }
        int ret=q.front();
        q.push(ret);
        q.pop();
        return ret;
    }
    bool empty(){
        return q.empty();
    }
};



int main() {
	Stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    while(!stk.empty()){
        cout<<stk.peek()<<" ";
        stk.pop();
    }
    

	return 0;
}


