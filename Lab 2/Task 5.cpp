#include <iostream>
using namespace std;
int main() {
    int r,c;
    cin>>r>>c;
    int** A=new int*[r];
    int** B=new int*[r];
    int** C=new int*[r];
    for(int i=0;i<r;i++){
        A[i]=new int[c]; B[i]=new int[c]; C[i]=new int[c];
    }
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>A[i][j];
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>B[i][j];
    for(int i=0;i<r;i++){ for(int j=0;j<c;j++){C[i][j]=A[i][j]+B[i][j]; cout<<C[i][j]<<" ";} cout<<endl;}
    for(int i=0;i<r;i++){ for(int j=0;j<c;j++){C[i][j]=A[i][j]-B[i][j]; cout<<C[i][j]<<" ";} cout<<endl;}
    for(int i=0;i<r;i++){ delete[] A[i]; delete[] B[i]; delete[] C[i]; }
    delete[] A; delete[] B; delete[] C;
    return 0;
}
