#include <iostream>
using namespace std;
int main(){
    int cat;cin>>cat;
    int** books=new int*[cat];
    int* count=new int[cat];
    for(int i=0;i<cat;i++){
        cin>>count[i];
        books[i]=new int[count[i]];
        for(int j=0;j<count[i];j++) cin>>books[i][j];
    }
    int id;cin>>id;
    bool found=false;
    for(int i=0;i<cat;i++){
        for(int j=0;j<count[i];j++){
            if(books[i][j]==id){cout<<"Found in "<<i<<endl;found=true;}
        }
    }
    if(!found) cout<<"Not Found"<<endl;
    for(int i=0;i<cat;i++) delete[] books[i];
    delete[] books; delete[] count;
    return 0;
}
