#include<bits/stdc++.h>
using namespace std;

int dp(int index, int a[], int memo[], int k) {
	if (index == 0) return 0;

	if (memo[index] != -1) return memo[index];

	int ans = INT_MAX;

	for (int i = index - 1; i >= index - k && i >= 0; i--) {
		ans = min(ans, dp(i, a, memo, k) + abs(a[index] - a[i]));
	}

	return memo[index] = ans;
}

void trace_back(int index, int a[], int memo[], int k) {
	cout << index + 1 << '\n';
	for (int i = index - 1; i >= index - k && i >= 0; i--) {
		if (dp(index, a, memo, k)
		        == dp(i, a, memo, k) + abs(a[index] - a[i])) {
			trace_back(i, a, memo, k);
			return;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	int a[n];
	int memo[n];
	memset(memo, -1, sizeof(memo));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// cout << dp(n - 1, a, memo, k);


	trace_back(n - 1, a, memo, k);
















}