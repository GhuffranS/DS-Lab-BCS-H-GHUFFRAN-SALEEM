#include <iostream>
using namespace std;
int main() {
    int r,c;
    cin >> r >> c;
    int** seats=new int*[r];
    for(int i=0;i<r;i++) seats[i]=new int[c];
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) seats[i][j]=0;
    int x,y;
    while(cin>>x>>y) {
        if(x<0||y<0) break;
        if(x<r&&y<c) seats[x][y]=1;
    }
    for(int i=0;i<r;i++){ for(int j=0;j<c;j++) cout<<seats[i][j]<<" "; cout<<endl;}
    for(int i=0;i<r;i++) delete[] seats[i];
    delete[] seats;
    return 0;
}
