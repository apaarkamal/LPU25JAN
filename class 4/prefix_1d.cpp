#include<bits/stdc++.h>
using namespace std;

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

    int pref_sum[n];
    pref_sum[0] = a[0];

    for (int i = 1; i < n; i++) {
        pref_sum[i] = pref_sum[i - 1] + a[i];
    }

    for (int i = 0; i < n; i++) {
        cout << pref_sum[i] << " ";
    }

    int l, r;
    cin >> l >> r;

    int sum = pref_sum[r];

    if (l > 0) {
        sum -= pref_sum[l - 1];
    }

    cout << sum << '\n';






}