#include<bits/stdc++.h>
using namespace std;

int lower_bound(int a[], int n, int val) {
	sort(a, a + n);
	int left = 0, right = n;

	while (left < right) {
		int mid = (left + right) / 2;
		if (a[mid] >= val) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	// return the lower bound for val
	// left==right
	return left;
}

int upper_bound(int a[], int n, int val) {
	sort(a, a + n);
	int left = 0, right = n;

	while (left < right) {
		int mid = (left + right) / 2;
		if (a[mid] <= val) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}

	// return the lower bound for val
	// left==right
	return left;
}

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

	cout << lower_bound(a, n, 9) << '\n';
	cout << upper_bound(a, n, 9) << '\n';

}