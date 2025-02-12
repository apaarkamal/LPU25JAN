#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int> > Q;

	while (n--) {
		int x;
		cin >> x;
		Q.push(x);
	}

	// while (!Q.empty()) {
	// 	cout << Q.top() << '\n';
	// 	Q.pop();
	// }

	int sum = 0;

	// n*logn
	while (Q.size() > 1) {
		// logn
		int smallest = Q.top();
		Q.pop();
		// logn
		int smallest_two = Q.top();
		Q.pop();

		sum += (smallest + smallest_two);

		// logn
		Q.push(smallest + smallest_two);
	}

	cout << sum << '\n';


}