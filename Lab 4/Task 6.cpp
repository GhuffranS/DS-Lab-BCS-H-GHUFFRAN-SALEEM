#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int gap = n;
    bool sw = true;
    int comps = 0, swaps = 0;
    while (gap != 1 || sw) {
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;
        sw = false;
        for (int i = 0; i < n - gap; i++) {
            comps++;
            if (arr[i] > arr[i + gap]) {
                int t = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = t;
                swaps++;
                sw = true;
            }
        }
    }
    for (int i : arr) cout << i << " ";
    cout << endl;
    cout << "Comparisons: " << comps << endl;
    cout << "Swaps: " << swaps << endl;
}
