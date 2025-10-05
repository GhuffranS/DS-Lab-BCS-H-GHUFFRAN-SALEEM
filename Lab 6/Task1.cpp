#include <iostream>
using namespace std;


const int CAP=100;
int st[CAP];
int top=-1;


void push(int x){
if(top+1==CAP) return;
st[++top]=x;
}


int pop(){
if(top==-1) return -1;
return st[top--];
}


int peek(){
if(top==-1) return -1;
return st[top];
}


void displayStack(){
for(int i=top;i>=0;--i) cout<<st[i]<<" ";
cout<<"\n";
}


int main(){
push(10); push(20); push(30);
displayStack();
cout<<pop()<<" popped\n";
cout<<peek()<<" top\n";
displayStack();
return 0;
}
