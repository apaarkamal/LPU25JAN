#include<bits/stdc++.h>
using namespace std;

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int a[n][3];

	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}

	int dp[n][3];
	dp[0][0] = a[0][0];
	dp[0][1] = a[0][1];
	dp[0][2] = a[0][2];

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
		dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + a[i][2];
	}

	cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));












}