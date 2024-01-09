#include <iostream>
#include <cassert>
using namespace std;
#include <queue>


class sumLastK
{
private:
      queue<int>q;
      int sum {};
      int k {};
public:
    sumLastK(int k):k(k){

    };
    ~sumLastK(){

    };

    int next(int num){
        sum+=num;
        if(q.size()==k){
            sum-=q.front();
            q.pop();
        }
        q.push(num);
        return sum;
    }
};


int main() {
	sumLastK k(4);
    for(int i=1;i<=9;i++){
        cout<<k.next(i)<<" ";
    }
    cout<<"\n";
}
