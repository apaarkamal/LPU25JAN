#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> St;
		int cur = 0, ans = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				St.push(cur);
				cur = 0;
			}
			else {
				if (St.empty()) {
					cur = 0;
				}
				else {
					cur = cur + 2 + St.top();
					St.pop();
				}
			}
			ans = max(ans, cur);
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