#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int* exp=new int[n];
    for(int i=0;i<n;i++) cin>>exp[i];
    char more;
    cin>>more;
    if(more=='y'){
        int m;
        cin>>m;
        int* temp=new int[n+m];
        for(int i=0;i<n;i++) temp[i]=exp[i];
        for(int i=n;i<n+m;i++) cin>>temp[i];
        delete[] exp;
        exp=temp;
        n=n+m;
    }
    int sum=0;
    for(int i=0;i<n;i++) sum+=exp[i];
    cout<<sum<<" "<<sum/(double)n<<endl;
    delete[] exp;
    return 0;
}
