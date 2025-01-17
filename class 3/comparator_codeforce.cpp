#include<bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    // a + b
    // b + a
    return a + b < b + a;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    string a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    sort(a, a + n, compare);

    for (int i = 0; i < n; i++) {
        cout << a[i];
    }

}