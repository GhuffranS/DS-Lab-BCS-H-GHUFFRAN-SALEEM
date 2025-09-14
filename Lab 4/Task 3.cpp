#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[m]) m = j;
        }
        int t = arr[i];
        arr[i] = arr[m];
        arr[m] = t;
    }
    for (int i : arr) cout << i << " ";
}
