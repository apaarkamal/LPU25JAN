#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > grid;

bool isSafe(int row, int col) {
	// this is a column check
	int i = row, j;
	while (i >= 0) {
		if (grid[i][col]) return false;
		i--;
	}

	// right-up diagonal check
	i = row; j = col;
	while (j < n && i >= 0) {
		if (grid[i][j]) return false;
		j++; i--;
	}

	// left-up diagonal check
	i = row; j = col;
	while (j >= 0 && i >= 0) {
		if (grid[i][j]) return false;
		i--; j--;
	}

	return true;
}

void print_grid() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j]) cout << "Q";
			else cout << ".";
		}
		cout << '\n';
	}
}

void nqueen(int row) {
	if (row == n) {
		print_grid();
		exit(0);
		cout << '\n';
		return;
	}
	for (int col = 0; col < n; col++) {
		if (isSafe(row, col)) {
			grid[row][col] = 1;

			nqueen(row + 1);

			// backtrack
			grid[row][col] = 0;
		}
	}
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	grid.resize(n, vector<int>(n, 0));

	nqueen(0);

}