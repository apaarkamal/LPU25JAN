#include<bits/stdc++.h>
using namespace std;

// O(n)
int placeCows(int a[], int n, int k) {
    // place a cow on a[0]
    int cows_placed = 1, last_cow_placed = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] - last_cow_placed >= k) {
            cows_placed++;
            last_cow_placed = a[i];
        }
    }

    return cows_placed;
}

// (cows+placed < c)
int lower_bound(int a[], int n, int c) {
    int left = 1, right = a[n - 1] - a[0];

    while (left < right) {
        int mid = (left + right) / 2;
        if (placeCows(a, n, mid) < c) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}

int upper_bound(int a[], int n, int c) {
    int left = 1, right = a[n - 1] - a[0];

    while (left < right) {
        int mid = (left + right) / 2;
        if (placeCows(a, n, mid) >= c) { // condition
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    // return the lower bound for val
    // left==right
    return left;
}

void solve() {
    int n, c;
    cin >> n >> c;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);


    // linear search
    // // O(10^9) * O(n)
    // for (int k = 1; k <= a[n - 1] - a[0]; k++) {
    //     // cout << k << " " << placeCows(a, n, k) << '\n';
    //     if (placeCows(a, n, k) < c) {
    //         cout << k - 1 << '\n';
    //         break;
    //     }
    // }


    // binary search lower_bound
    // cout << lower_bound(a, n, c) - 1 << '\n';

    // binary search upper_bound
    // log(10^9) ~ 22 * O(n) = 22* 10^5 = 2 ^ 10^6
    cout << upper_bound(a, n, c) - 1 << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}