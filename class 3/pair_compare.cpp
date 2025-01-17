#include<bits/stdc++.h>
using namespace std;

// whether a is less then b or not?
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	pair<int, int> a[n];
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = make_pair(x, y);
	}

	sort(a, a + n, compare);

	for (int i = 0; i < n; i++) {
		cout << a[i].first << " " << a[i].second << '\n';
	}

}