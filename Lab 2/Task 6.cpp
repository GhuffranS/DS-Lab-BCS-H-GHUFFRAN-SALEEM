#include <iostream>
using namespace std;
class SafePtr {
    int* p;
public:
    SafePtr(){p=new int;}
    void setValue(int v){*p=v;}
    int getValue(){return *p;}
    void release(){delete p; p=nullptr;}
};
int main() {
    SafePtr arr[5];
    for(int i=0;i<5;i++){int x;cin>>x;arr[i].setValue(x);}
    for(int i=0;i<5;i++) cout<<arr[i].getValue()<<" ";
    for(int i=0;i<5;i++) arr[i].release();
    return 0;
}
