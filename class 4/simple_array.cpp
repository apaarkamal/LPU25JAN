#include<bits/stdc++.h>
using namespace std;

// reversal, sort check, maximum and minimum

void reverseArray(int a[], int n) {
	// for (int i = 0; i < n / 2; i++) {
	// 	swap(a[i], a[n - i - 1]);
	// }

	// reverse(a, a + n);
}

// return true if the array is sorted
bool sortCheck(int a[], int n) {
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i + 1]) return false;
	}
	return true;
}

int maxElementInArray(int a[], int n) {
	// int ans = INT_MIN;
	// for (int i = 0; i < n; i++) {
	// 	ans = max(ans, a[i]);
	// }
	// return ans;

	// auto it = max_element(a, a + n);
	// return *it;

	sort(a, a + n);
	return a[n - 1];
}






int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << INT_MIN;

}