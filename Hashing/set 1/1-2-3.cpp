#include <iostream>
using namespace std;

int hash_string(string s, int n){
    int res=0;
    for(int i=0;i<s.size();i++){
        if(s[i]<'A') res= ( (res*62) %n + (s[i]-'0'+182) %n )%n;
        else if(s[i]>'Z') res=( (res*62)%n + (s[i]-'a')%n )%n;
        else res= ( (res*62)%n + (s[i]-'A'+58)%n )%n;
    }
    return res;
}

int foling_hasing(string s){
    int i=0;
    int sum=0;
    for(;i<s.size()-4;i+=4){
        sum+=hash_string(s.substr(i,4),4);
    }
    if(s.size()%4!=0) sum+=hash_string(s.substr(i,s.size()%4),s.size()%4);
    return sum;
}

struct someObject
{
    string str1,str2;
    int number;
    int hash(){
        int has=foling_hasing(str1)+foling_hasing(str2)+foling_hasing(to_string(number));
        return has;
    }
};



int main(){
    string s="AaAsA12";
    cout<<foling_hasing(s)<<"\n";
    return 0;
}
