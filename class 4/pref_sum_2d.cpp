#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    int mat[n][m], pref[n][m];


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << pref[i][j] << " ";
        } cout << '\n';
    }

    int a, b, x, y;
    cin >> a >> b >> x >> y;

    int sum = pref[x][y];
    if (a - 1 >= 0) sum -= pref[a - 1][y];
    if (b - 1 >= 0) sum -= pref[x][b - 1];
    if (a - 1 >= 0 && b - 1 >= 0 ) sum += pref[a - 1][b - 1];

    cout << sum << '\n';




}