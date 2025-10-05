#include <iostream>
#include <cstring>
using namespace std;


struct Node{char url[256]; Node* next;};


Node* createNode(const char*s){
Node* p=new Node;
strcpy(p->url,s);
p->next=0;
return p;
}


void push(Node*&top,const char*s){
Node* p=createNode(s);
p->next=top;
top=p;
}


char* pop(Node*&top){
if(!top) return 0;
Node* t=top; top=top->next;
char* r=new char[256]; strcpy(r,t->url); delete t; return r;
}


void show(Node*top){
for(Node*p=top;p;p=p->next) cout<<p->url<<"
";
}


int main(){
Node* top=0;
push(top,"home.com");
push(top,"about.com");
push(top,"contact.com");
show(top);
}
