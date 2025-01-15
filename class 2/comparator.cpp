#include<bits/stdc++.h>
using namespace std;

// true a<b
// false a>b
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) {
		if (a.first < b.first) return true;
		else return false;
	}
	else {
		if (a.second > b.second) return true;
		else return false;
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