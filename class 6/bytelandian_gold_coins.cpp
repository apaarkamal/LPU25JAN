#include<bits/stdc++.h>
#define int long long int
using namespace std;

// map<int, int> mp;
const int N = 1e6;
int memo[N];

int byteLandianGoldCoins(int n) {
    if (n <= 1) return n;

    if (n < N &&  memo[n] != -1) {
        return memo[n];
    }

    int ans = max(byteLandianGoldCoins(n / 2)
                  + byteLandianGoldCoins(n / 3)
                  + byteLandianGoldCoins(n / 4), n);

    if (n < N) {
        memo[n] = ans;
    }

    return ans;

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    memset(memo, -1, sizeof(memo));

    int n;
    while (cin >> n) {
        cout << byteLandianGoldCoins(n) << '\n';
    }

}