#include <iostream>
using namespace std;
int main(){
    int r,c;cin>>r>>c;
    int** mat=new int*[r];
    for(int i=0;i<r;i++) mat[i]=new int[c];
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>mat[i][j];
    for(int i=0;i<r;i++){ for(int j=0;j<c;j++) cout<<mat[i][j]<<" "; cout<<endl;}
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) if(mat[i][j]!=0) cout<<i<<" "<<j<<" "<<mat[i][j]<<endl;
    for(int i=0;i<r;i++) delete[] mat[i];
    delete[] mat;
    return 0;
}
