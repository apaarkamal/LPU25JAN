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

	int dp[n];
	dp[0] = 0;
	dp[1] = abs(a[1] - a[0]);

	// O(n)
	for (int i = 2; i < n; i++) {
		dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]),
		            dp[i - 2] + abs(a[i] - a[i - 2]));
	}
	cout << dp[n - 1];

}