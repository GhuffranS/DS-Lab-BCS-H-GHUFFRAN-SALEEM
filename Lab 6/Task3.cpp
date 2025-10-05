#include <iostream>
using namespace std;


const int NQ=100;
int q[NQ];
int fronti=0,reari=0,sz=0;


bool enqueue(int x){
if(sz==NQ) return false;
q[reari]=x; reari=(reari+1)%NQ; ++sz; return true;
}


int dequeue(){
if(sz==0) return -1;
int v=q[fronti]; fronti=(fronti+1)%NQ; --sz; return v;
}


void displayQueue(){
for(int i=0;i<sz;i++) cout<<q[(fronti+i)%NQ]<<" ";
cout<<"
";
}


int main(){
enqueue(5); enqueue(6); enqueue(7);
displayQueue();
cout<<dequeue()<<" removed
";
displayQueue();
return 0;
}
