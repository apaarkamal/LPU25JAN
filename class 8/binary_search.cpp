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

// -1 if not found
// return the index
int binary_search_iterative(int a[], int n, int val) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		// db(left, right, mid, a[mid]);
		if (a[mid] == val) {
			return mid;
		}
		else if (val < a[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}

// try to code binary search recursively
// homework

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

	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << '\n';

	cout << binary_search_iterative(a, n, 23) << '\n';
	cout << binary_search_iterative(a, n, 24) << '\n';


	if (binary_search(a, a + n, 24)) {
		cout << "found";
	}
	else {
		cout << "not found";
	}













}