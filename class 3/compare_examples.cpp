#include<bits/stdc++.h>
using namespace std;

// return true if a should come before b in the array
bool compare(int a, int b) {
    return a > b;
}

bool compareSquares(int a, int b) {
    if (a * a == b * b) {
        return a < b;
    }
    else {
        return a * a < b * b;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n, compareSquares);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

}