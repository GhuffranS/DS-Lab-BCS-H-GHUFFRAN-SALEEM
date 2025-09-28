#include <iostream>
using namespace std;

int calculateFactorial(int n) {
    if (n <= 1) return 1;
    return n * calculateFactorial(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << calculateFactorial(n);
    return 0;
}
