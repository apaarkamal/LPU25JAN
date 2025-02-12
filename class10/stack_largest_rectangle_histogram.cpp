#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> nextSmaller(vector<int>& heights) {
		// increasing
		stack<int> St;
		vector<int> next_smaller(heights.size());
		for (int i = 0; i < heights.size(); i++) {
			while (!St.empty() && heights[i] < heights[St.top()]) {
				next_smaller[St.top()] = i;
				St.pop();
			}
			St.push(i);
		}
		while (!St.empty()) {
			next_smaller[St.top()] = heights.size();
			St.pop();
		}
		return next_smaller;
	}
	vector<int> prevSmaller(vector<int>& heights) {
		// increasing
		stack<int> St;
		vector<int> prev_smaller(heights.size());
		for (int i = heights.size() - 1; i >= 0; i--) {
			while (!St.empty() && heights[i] < heights[St.top()]) {
				prev_smaller[St.top()] = i;
				St.pop();
			}
			St.push(i);
		}
		while (!St.empty()) {
			prev_smaller[St.top()] = -1;
			St.pop();
		}
		return prev_smaller;
	}
	int largestRectangleArea(vector<int>& heights) {
		vector<int> next_smaller = nextSmaller(heights);
		vector<int> prev_smaller = prevSmaller(heights);

		int ans = 0;
		for (int i = 0; i < heights.size(); i++) {
			int l = prev_smaller[i];
			int r = next_smaller[i];
			int length = r - l - 1;
			int area = heights[i] * length;
			ans = max(ans, area);
		}

		return ans;



	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}