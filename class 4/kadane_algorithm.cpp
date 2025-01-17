#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& a) {
		int best_end = a[0];
		int max_end = a[0];

		for (int i = 1; i < a.size(); i++) {
			best_end = max(best_end + a[i], a[i]);
			max_end = max(max_end, best_end);
		}
		return max_end;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;


	Solution H;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	cout << H.maxSubArray(v);

}