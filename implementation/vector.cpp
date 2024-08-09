#include <iostream>
#include <assert.h>
using namespace std;

template <typename T>
class Vector {
private:
    int size;
    int capacity;
    T* arr;

public:
    Vector() : size(0), capacity(1) {
        arr = new T[capacity];
    }

    Vector(int size) : size(size), capacity(size * 2) {
        arr = new T[capacity];
    }

    ~Vector() {
        delete[] arr;
    }

    Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
        arr = new T[capacity];
        for(int i = 0 ; i <  other.size ; i++) arr[i] = other.arr[i];
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] arr;
            size = other.size;
            capacity = other.capacity;
            arr = new T[capacity];
            for(int i = 0 ; i <  other.size ; i++) arr[i] = other.arr[i];
        }
        return *this;
    }

    void expand_capacity() {
        int new_capacity = size * 2;
        T* new_arr = new T[new_capacity];
        std::copy(arr, arr + size, new_arr);
        delete[] arr;
        arr = new_arr;
        capacity = new_capacity;
    }

    void push_back(const T& val) {
        if (size == capacity) expand_capacity();
        arr[size++] = val;
    }

    void insert(int idx, const T& val) {
        assert(idx >= 0 && idx <= size); 
        if (size == capacity) expand_capacity();
        for (int i = size - 1; i >= idx; i--) arr[i + 1] = arr[i];
        arr[idx] = val;
        size++;
    }

    int find(const T& val) const {
        for (int i = 0; i < size; i++) if (val == arr[i]) return i;
        return -1;
    }

    int lower_bound(const T& val) const {
        int l = 0, r = size;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] < val) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    int upper_bound(const T& val) const {
        int l = 0, r = size;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] <= val) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    void erase(int idx) {
        assert(idx >= 0 && idx < size);
        for (int i = idx; i < size - 1; i++) arr[i] = arr[i + 1];
        size--;
    }

    T& operator[](int idx) {
        assert(idx >= 0 && idx < size);
        return arr[idx];
    }

    const T& operator[](int idx) const {
        assert(idx >= 0 && idx < size);
        return arr[idx];
    }

    int Size() const {
        return this->size;
    }

};

int main(){
    int n; cin>>n;
    Vector<int> v(n);
    v.push_back(4);
    v.push_back(5);
    v.push_back(10);
    for(int i  = 0 ; i < v.Size() ; i++) cout<<v[i]<<" ";
    cout<<"\n";
    Vector<int> vv = v;
    vv.erase(3);
    for(int i =0  ; i < vv.Size() ; i++) cout<<vv[i]<<" ";
    cout<<"\n";
    vv.insert(vv.Size(), 10000);
    cout<<vv[vv.Size()-1]<<"\n";

    return 0;
}