#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// static array
	int a[5] = {2, 1, 5, 3, 9};

	// sort(a, a + 5);
	sort(a + 1, a + 5);

	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}

}