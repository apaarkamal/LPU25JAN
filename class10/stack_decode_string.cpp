#include<bits/stdc++.h>
using namespace std;

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

class Solution {
public:
	string decodeString(string s) {
		int k = 0;
		string cur = "";
		stack<string> Sts;
		stack<int> Stk;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '[') {
				Sts.push(cur);
				cur = "";
				Stk.push(k);
				k = 0;
			}
			else if (s[i] == ']') {
				// repeat cur k times
				int kk = Stk.top();
				Stk.pop();
				string temp = "";
				while (kk--) {
					temp += cur;
				}
				cur = temp;

				// append prev answer to cur
				cur = Sts.top() + cur;
				Sts.pop();
			}
			else if (s[i] >= '0' && s[i] <= '9') {
				k = k * 10 + (s[i] - '0');
			}
			else {
				// its alphabet
				cur = cur + s[i];
			}
			db(cur, k);
			if (!Stk.empty()) {
				db(Stk.top(), Sts.top());
			}
		}
		return cur;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;

	Solution H;
	cout << H.decodeString(s);














}