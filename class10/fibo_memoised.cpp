#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
vector<int> memo;

int fib(int n) {
	cnt++;
	if (n <= 1) return n;
	if (memo[n] != -1) return memo[n];
	memo[n] = fib(n - 1) + fib(n - 2);
	return memo[n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	memo.resize(n + 1, -1);
	cout << fib(n) << " " << cnt;

}