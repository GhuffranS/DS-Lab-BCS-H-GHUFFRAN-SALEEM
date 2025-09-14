#include <iostream>
#include <vector>
using namespace std;

int interpolationSearch(vector<int>& arr, int x) {
    int l = 0, r = arr.size() - 1;
    while (l <= r && x >= arr[l] && x <= arr[r]) {
        if (l == r) {
            if (arr[l] == x) return l;
            return -1;
        }
        int pos = l + ((double)(r - l) / (arr[r] - arr[l])) * (x - arr[l]);
        if (arr[pos] == x) return pos;
        if (arr[pos] < x) l = pos + 1;
        else r = pos - 1;
    }
    return -1;
}

int main() {
    int n, x;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;
    int pos = interpolationSearch(arr, x);
    if (pos != -1) cout << pos;
    else cout << "Not found";
}
