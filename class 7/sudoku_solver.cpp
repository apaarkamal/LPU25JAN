#include<bits/stdc++.h>
using namespace std;

void sudokuSolver(int row, int col);

int grid[9][9], n = 9;

bool isSafe(int row, int col, int digit) {
	// row check
	for (int j = 0; j < n; j++) {
		if (grid[row][j] == digit) return false;
	}
	// col check
	for (int i = 0; i < n; i++) {
		if (grid[i][col] == digit) return false;
	}

	// 3 x 3 check
	int row_start = (row / 3) * 3, col_start = (col / 3) * 3;

	for (int i = row_start; i < row_start + 3; i++) {
		for (int j = col_start; j < col_start + 3; j++) {
			if (grid[i][j] == digit) return false;
		}
	}

	return true;
}

void goNext(int row, int col) {
	if (col == n - 1) {
		sudokuSolver(row + 1, 0);
	}
	else {
		sudokuSolver(row, col + 1);
	}
}

void print_grid() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
}

void sudokuSolver(int row, int col) {
	if (row == n) {
		print_grid();
		return;
	}

	if (grid[row][col] == 0) {
		// i need to fill the cell

		for (int digit = 1; digit <= 9; digit++) {
			if (isSafe(row, col, digit)) {
				grid[row][col] = digit;
				goNext(row, col);
				grid[row][col] = 0;
			}
		}
	}
	else {
		goNext(row, col);
	}
}

int main() {
#ifndef ONLINE_JUDGEa
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	sudokuSolver(0, 0);

}