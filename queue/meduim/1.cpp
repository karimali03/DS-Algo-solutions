#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

class stack_queue
{
private:
    stack<int>st1,st2;
public:
    stack_queue(){};
    ~stack_queue(){};
    bool isEmpty(){
        return st1.empty();
    }
    void pop(){
        assert(!isEmpty());
        st1.pop();
    }
    int top(){
        assert(!isEmpty());
        return st1.top();
    }
    void push(int val){
        while (!isEmpty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(val);
        while (!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
};


int main(){
    stack_queue q;
    for(int i=1;i<6;i++){
        q.push(i);
    }
    q.pop();
    for(int i=6;i<10;i++) q.push(i);
    while (!q.isEmpty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    
}
