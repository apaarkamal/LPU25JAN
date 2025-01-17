#include<bits/stdc++.h>
using namespace std;

// 4 5
// 2 9 3 -5 1
// 4 -1 2 -1 -4
// -3 -5 7 -8 -1
// -1 3 2 4 5

int mat[1000][1000], pref[1000][1000];

// O(1)
int givePrefixSum(int a, int b, int x, int y) {
	int sum = pref[x][y];
	if (a - 1 >= 0) sum -= pref[a - 1][y];
	if (b - 1 >= 0) sum -= pref[x][b - 1];
	if (a - 1 >= 0 && b - 1 >= 0 ) sum += pref[a - 1][b - 1];
	return sum;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	pair<int, vector<int> > ans;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	/// precomputation of prefix sums
	pref[0][0] = mat[0][0];
	// first column
	for (int i = 1; i < n; i++) {
		pref[i][0] = pref[i - 1][0] + mat[i][0];
	}
	// first row
	for (int j = 1; j < m; j++) {
		pref[0][j] = pref[0][j - 1] + mat[0][j];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1]
			             - pref[i - 1][j - 1] + mat[i][j];
		}
	}

	// O(n^2*m^2)
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < m; b++) {
			// top - left corner (a, b)
			// x and y bottom right
			for (int x = a; x < n; x++) {
				for (int y = b; y < m; y++) {
					// now we know a submatrix between
					// (a, b) and (x, y)
					// cout << a << " " << b << " " << x << " " << y << '\n';
					// we want the sum of this submatrix
					// int sum = 0;
					// for (int i = a; i <= x; i++) {
					// 	for (int j = b; j <= y; j++) {
					// 		sum += mat[i][j];
					// 	}
					// }

					int sum = givePrefixSum(a, b, x, y);


					vector<int> temp;
					temp.push_back(a);
					temp.push_back(b);
					temp.push_back(x);
					temp.push_back(y);
					ans = max(ans, make_pair(sum, temp));

				}
			}

		}
	}

	cout << ans.first << '\n';

	for (auto x : ans.second) {
		cout << x << " ";
	}


}