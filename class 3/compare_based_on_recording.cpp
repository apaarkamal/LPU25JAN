#include<bits/stdc++.h>
using namespace std;

map<int, int> frequency_map;

bool compareUsingFrequency(int a, int b) {
    return frequency_map[a] < frequency_map[b];
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
        frequency_map[a[i]]++;
    }

    for (auto x : frequency_map) {
        cout << x.first << " " << x.second << '\n';
    }

    sort(a, a + n, compareUsingFrequency);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

}