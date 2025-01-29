#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

// O(log(1e6))
int upper_bound(int rank, int tme) {
    int left = 0, right = 1e6;

    while (left < right) {
        int mid = (left + right) / 2;
        if (rank * mid * (mid + 1) <= tme * 2) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left;
}

// O(log(1e6))
int paranthasByCook(int rank, int tme) {
    return upper_bound(rank, tme) - 1;
}

// O(50) * O(log(1e6))
int totalParanthasByTime(int rank[], int l, int tme) {
    int paranthas = 0;
    for (int i = 0; i < l; i++) {
        paranthas += paranthasByCook(rank[i], tme);
    }
    return paranthas;
}

void solve() {
    int p;
    cin >> p;
    int l;
    cin >> l;
    int rank[l];
    for (int i = 0; i < l; i++) {
        cin >> rank[i];
    }

    // (4 * 1000 * 1001) * 50 * 22
    // for (int tme = 0; tme < 4 * 1000 * 1001; tme++) {
    //     // cout << "time -> "  <<
    //     // tme << " -> " << totalParanthasByTime(rank, l, tme)
    //     // << '\n';
    //     if (totalParanthasByTime(rank, l, tme) >= p) {
    //         cout << tme << '\n';
    //         break;
    //     }
    // }

    int left = 0, right = 4 * 1000 * 1001;
    // log(4*1000*1001) * O(l) * O(log(1e6))
    // 23 * 50 * 20
    // 23000
    // O(2.3 * 1e4)
    while (left < right) {
        int mid = (left + right) / 2;
        if (totalParanthasByTime(rank, l, mid) >= p) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    cout << left << '\n';

}

int32_t main() {
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