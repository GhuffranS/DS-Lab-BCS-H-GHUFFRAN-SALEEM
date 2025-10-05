#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


int prec(char c){ if(c=='^') return 3; if(c=='*'||c=='/') return 2; if(c=='+'||c=='-') return 1; return -1; }


void infixToPostfix(const char*in,char*out){
char st[256]; int top=-1; int j=0;
int L=strlen(in);
for(int i=0;i<L;i++){
char c=in[i];
if(c==' ') continue;
if(isalnum(c)) { out[j++]=c; out[j++]=' '; }
else if(c=='(') st[++top]=c;
else if(c==')'){ while(top!=-1 && st[top]!='(') { out[j++]=st[top--]; out[j++]=' '; } if(top!=-1) --top; }
else {
while(top!=-1 && ((prec(st[top])>prec(c)) || (prec(st[top])==prec(c) && c!='^')) && st[top]!='(') { out[j++]=st[top--]; out[j++]=' '; }
st[++top]=c;
}
}
while(top!=-1) out[j++]=st[top--], out[j++]=' ';
out[j]=0;
}


int evalPostfix(const char*post){
int st[256]; int top=-1;
int L=strlen(post);
for(int i=0;i<L;i++){
if(post[i]==' ') continue;
if(isdigit(post[i])) st[++top]=post[i]-'0';
else {
int b=st[top--]; int a=st[top--]; char op=post[i];
if(op=='+') st[++top]=a+b;
else if(op=='-') st[++top]=a-b;
else if(op=='*') st[++top]=a*b;
}
