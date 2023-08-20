#include <iostream>
#include <cassert>
using namespace std;

class Stack {
private:
	int size { };
	int added { };
	int* array { };
public:
	Stack(int size) :
			size(size), added(0) {
		array = new int[size];
	}

	~Stack() {
		delete[] array;
	}

	bool push(int x) {
		if(added==size) return false;
		for(int i=added-1;i>=0;i--){
            array[i+1]=array[i];
        }
        array[0]=x;
        added++;
        return true;
	}

	bool pop() {
	   if(isEmpty()) return false;
		for(int i=0;i<added;i++){
            array[i]=array[i+1];
        }
        added--;
        return true;
	}

	int peek() {
		assert(!isEmpty());
		return array[0];
	}

	int isFull() {
		return added == size;
	}

	int isEmpty() {
		return added == 0;
	}

	void display() {
		for (int i = 0; i <added; i++)
			cout << array[i] << " ";
		cout << "\n";
	}
};

int main() {


	Stack stk(3);
	stk.push(10);
	stk.push(20);
	stk.push(30);

	if (!stk.isFull())
		stk.push(50);
	else
		cout << "Full Stack\n";
	stk.display();	
	cout << stk.peek() << "\n";	

	while (!stk.isEmpty()) {
		cout << stk.peek() << " ";
		stk.pop();
	} 
    
	return 0;
}
