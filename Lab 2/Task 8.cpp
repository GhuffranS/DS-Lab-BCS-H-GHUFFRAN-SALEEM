#include <iostream>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    int** temp=new int*[n];
    for(int i=0;i<n;i++) temp[i]=new int[m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>temp[i][j];
    double hottest=-1e9,coldest=1e9; int hotDay=0,coldDay=0;
    for(int i=0;i<n;i++){
        int sum=0; for(int j=0;j<m;j++) sum+=temp[i][j];
        double avg=sum/(double)m;
        cout<<avg<<endl;
        if(avg>hottest){hottest=avg;hotDay=i;}
        if(avg<coldest){coldest=avg;coldDay=i;}
    }
    cout<<hotDay<<" "<<coldDay<<endl;
    for(int i=0;i<n;i++) delete[] temp[i];
    delete[] temp;
    return 0;
}
