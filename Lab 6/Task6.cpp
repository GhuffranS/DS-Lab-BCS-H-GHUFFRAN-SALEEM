#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


int prec(char c){ if(c=='^') return 3; if(c=='*'||c=='/') return 2; if(c=='+'||c=='-') return 1; return -1; }


void reverseStr(char*s){ int i=0,j=strlen(s)-1; while(i<j){ char t=s[i]; s[i]=s[j]; s[j]=t; ++i; --j; }}


void infixToPostfix(const char*in,char*out){
char st[256]; int top=-1; int j=0; int L=strlen(in);
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


void infixToPrefix(const char*in,char*out){
char s[512]; strcpy(s,in);
reverseStr(s);
for(int i=0;i<(int)strlen(s);i++){ if(s[i]=='(') s[i]=')'; else if(s[i]==')') s[i]='('; }
char post[512]; infixToPostfix(s,post);
int len=strlen(post);
char tokens[256][32]; int tcount=0;
int idx=0;
while(idx<len){ if(post[idx]==' ') { idx++; continue; } int k=0; while(idx<len && post[idx]!=' '){ tokens[tcount][k++]=post[idx++]; } tokens[tcount][k]=0; tcount++; }
int p=0;
}
