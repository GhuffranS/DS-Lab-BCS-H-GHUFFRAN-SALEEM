#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++) arr[i]=0;
    for(int i=0;i<n;i++) {
        int pos,val;
        cin >> pos >> val;
        if(pos>=0 && pos<n) arr[pos]=val;
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    delete[] arr;
    return 0;
}
