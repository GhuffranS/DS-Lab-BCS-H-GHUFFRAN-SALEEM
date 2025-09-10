#include <iostream>
using namespace std;
int main(){
    int d;cin>>d;
    int** salary=new int*[d];
    int* emp=new int[d];
    for(int i=0;i<d;i++){
        cin>>emp[i];
        salary[i]=new int[emp[i]];
        for(int j=0;j<emp[i];j++) cin>>salary[i][j];
    }
    for(int i=0;i<d;i++){
        int mx=salary[i][0];
        for(int j=1;j<emp[i];j++) if(salary[i][j]>mx) mx=salary[i][j];
        cout<<mx<<endl;
    }
    int best=0; double bestAvg=0;
    for(int i=0;i<d;i++){
        int sum=0; for(int j=0;j<emp[i];j++) sum+=salary[i][j];
        double avg=sum/(double)emp[i];
        if(avg>bestAvg){bestAvg=avg;best=i;}
    }
    cout<<best<<endl;
    for(int i=0;i<d;i++) delete[] salary[i];
    delete[] salary; delete[] emp;
    return 0;
}
