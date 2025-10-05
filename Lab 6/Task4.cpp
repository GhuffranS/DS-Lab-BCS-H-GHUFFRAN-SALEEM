#include <iostream>
using namespace std;


const int M=5;
int a[M];
int f=0,r=0,cnt=0;


bool enqueue(int x){
if(cnt==M) return false;
a[r]=x; r=(r+1)%M; ++cnt; return true;
}


int dequeue(){
if(cnt==0) return -1;
int v=a[f]; f=(f+1)%M; --cnt; return v;
}


void display(){
for(int i=0;i<cnt;i++) cout<<a[(f+i)%M]<<" ";
cout<<"
";
}


int main(){
enqueue(1); enqueue(2); enqueue(3); enqueue(4); enqueue(5);
display();
cout<<dequeue()<<" popped
";
enqueue(6);
display();
return 0;
}
