#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int k = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > k) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = k;
    }
}

void shellSort(vector<int>& arr, int& comps, int& swaps) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int t = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > t) {
                arr[j] = arr[j - gap];
                j -= gap;
                comps++;
                swaps++;
            }
            arr[j] = t;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> b = arr, in = arr, sh = arr;

    clock_t t1 = clock();
    bubbleSort(b);
    clock_t t2 = clock();
    insertionSort(in);
    clock_t t3 = clock();
    int comps = 0, swaps = 0;
    shellSort(sh, comps, swaps);
    clock_t t4 = clock();

    cout << "Bubble time: " << (double)(t2 - t1) / CLOCKS_PER_SEC << endl;
    cout << "Insertion time: " << (double)(t3 - t2) / CLOCKS_PER_SEC << endl;
    cout << "Shell time: " << (double)(t4 - t3) / CLOCKS_PER_SEC << endl;
    cout << "Shell comps: " << comps << " swaps: " << swaps << endl;
}
