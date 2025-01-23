#include<bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int> > grid;

int dx[8] = { -2, -2, -1, +1, +2, +2, -1, +1};
int dy[8] = { -1, +1, +2, +2, +1, -1, -2, -2};

void print_grid() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << grid[i][j] << "\t";
		}
		cout << '\n';
	}
}

void knightTour(int row, int col, int step) {
	// cout << row << " " << col << '\n';

	grid[row][col] = step;

	if (step == m * n) {
		print_grid();
		exit(0);
		cout << '\n';
	}

	for (int i = 0; i < 8; i++) {
		int new_row = row + dx[i];
		int new_col = col + dy[i];
		if (new_row >= 0 && new_row < n
		        && new_col >= 0 && new_col < m) {
			if (grid[new_row][new_col] == 0) {
				knightTour(new_row, new_col, step + 1);
			}
		}
	}

	grid[row][col] = 0;
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;

	grid.resize(n, vector<int>(m, 0));

	knightTour(0, 0, 1);

}