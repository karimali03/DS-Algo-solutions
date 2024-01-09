#include<vector>
#include<iostream>
#include<cassert>
using namespace std;

class Min_Heap
{
private:
    int size;
    int capacity=1000;
    int* arr=nullptr;
    int parent(int node){
       if(node) return (node-1)/2;
       return -1;
    }
    int left(int node){
        return node*2+1 < size ? node*2+1:-1;
    }
    int right(int node){
      return node*2+2 < size ? node*2+2:-1;
    }
    void heapify_up(int node){
        int par=parent(node);
        if(!node || arr[node] > arr[par]) return;
        heapify_up(par);
    }
    void heapify_down(int node){
        int child=left(node),r=right(node);
        if(child==-1) return;
        if(r!=-1 && arr[r] < arr[child]) child=r;
        if(arr[child] < arr[node]){
            swap(arr[child],arr[node]);
            heapify_down(child);
        }
    }
    void heapify() {	// O(n)
       // optimization  i = size /2 -1  to skip leaf nodes 
        for (int i = size / 2 - 1; i >= 0; --i)
			heapify_down(i);
	}
public:
    Min_Heap(){
        size=0;
        arr=new int(capacity);
    };
    Min_Heap(vector<int> &v){
        size=v.size();
        arr=new int(capacity);
        for(int i=0;i<size;i++) arr[i]=v[i];
        heapify();
    }
    ~Min_Heap(){
        delete arr;
        arr=nullptr;
    };
    
    void push(int val){
        arr[size++]=val;
        heapify_up(size-1);
    }
    void pop(){
        arr[0]=arr[--size];
        heapify_down(0);
    }
    bool empty(){
        return size==0;
    }

};
