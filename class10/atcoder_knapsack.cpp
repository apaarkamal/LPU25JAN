#include<bits/stdc++.h>
#define int long long int
using namespace std;

int knapsack(int n, int val[], int weight[], int weight_of_knapsack,
             vector<vector<int> >& memo) {
	if (n == -1) {
		return 0;
	}

	if (memo[n][weight_of_knapsack] != -1) return memo[n][weight_of_knapsack];

	// exclude
	int exclude = knapsack(n - 1, val, weight, weight_of_knapsack, memo);

	// include
	int include = 0;
	if (weight[n] <= weight_of_knapsack) {
		include = knapsack(n - 1, val, weight, weight_of_knapsack - weight[n], memo)
		          + val[n];
	}
	return memo[n][weight_of_knapsack] = max(include, exclude);
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, w;
	cin >> n >> w;
	int val[n], weight[n];

	vector<vector<int> > memo;
	memo.resize(n, vector<int>(w + 1, -1));


	for (int i = 0; i < n; i++) {
		cin >> weight[i] >> val[i];
	}

	cout << knapsack(n - 1, val, weight, w, memo);

}