#include <iostream>
using namespace std;

struct Process{int id; int pr;};

const int QN=100;
Process q[QN];
int fi=0,ri=0,qs=0;

void enqueue(Process p){ if(qs==QN) return; q[ri]=p; ri=(ri+1)%QN; ++qs; }

Process dequeue(){ Process p={-1,-1}; if(qs==0) return p; p=q[fi]; fi=(fi+1)%QN; --qs; return p; }

void runScheduler(int threshold){
    Process st[QN]; int top=-1;
    int count=qs;
    for(int i=0;i<count;i++){
        Process p=dequeue();
        if(p.pr>=threshold) st[++top]=p; else enqueue(p);
    }
    while(top!=-1){ Process x=st[top--]; cout<<"Executing ID "<<x.id<<" pr "<<x.pr<<"
"; }
}

int main(){
    enqueue({1,3}); enqueue({2,7}); enqueue({3,5}); enqueue({4,9});
    runScheduler(6);
    return 0;
