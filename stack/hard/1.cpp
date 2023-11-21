#include <iostream>
#include <math.h>
#include <cassert>
using namespace std;



template <class T>
class Stack
{
private:
    struct Node
    {
       T data {};
       Node* next {};
       Node(T data):data(data){};
    };
    Node *head {};
public:
    ~Stack(){
        while(!empty()) pop();
    }

    void print(){
        for(auto cur=head;cur;cur=cur->next)
        cout<<cur->data<<" ";
        cout<<"\n";
    }

    void push(T val){
        Node * add=new Node(val);
        add->next=head;
        head=add;
    }
    T pop(){
        assert(head);
        T val=head->data;
        Node* del = head;
        head=head->next;
        delete del; 
        return val;
    }

    T top(){
        assert(head);
        return head->data;
    }

    bool empty(){
        return !head;
    }
};




double operation(double a, double b, char oper) {
	if (oper == '+')
		return a + b;
	if (oper == '-')
		return a - b;
	if (oper == '*')
		return a * b;
	if (oper == '/')
		return a / b;
	return pow(a, b);	
}

double Evaluation(string & postfix){
    Stack<double> st;

    for(auto & x : postfix){
        if(isdigit(x)) st.push(x-'0');
        else {

            double num2=st.pop(),num1=st.pop();
            st.push(operation(num1,num2,x));
        }
    }
    return st.top();
}



int main(){

    string s; 
    while(cin>>s){
        cout<<Evaluation(s)<<"\n\n";
    }
	return 0;
}