#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int** marks=new int*[n];
    int* courses=new int[n];
    for(int i=0;i<n;i++){
        cin>>courses[i];
        marks[i]=new int[courses[i]];
        for(int j=0;j<courses[i];j++) cin>>marks[i][j];
    }
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<courses[i];j++) sum+=marks[i][j];
        cout<<sum/(double)courses[i]<<endl;
    }
    for(int i=0;i<n;i++) delete[] marks[i];
    delete[] marks;
    delete[] courses;
    return 0;
}
