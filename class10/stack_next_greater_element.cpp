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

	stack<int> St;
	int next_greater[n];

	// next greater element
	// decreasing stack
	for (int i = 0; i < n; i++) {
		while (!St.empty() && a[i] > a[St.top()]) {
			next_greater[St.top()] = a[i];
			St.pop();
		}
		St.push(i);
	}
	while (!St.empty()) {
		next_greater[St.top()] = -1;
		St.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << next_greater[i] << " ";
	}










}