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

// recursion
// re-occurrence

// fibonacci series
// f(n) = f(n-1) + f(n-2)

// prefix sums
// prefix_sum(n) = prefix_sum(n-1) + a[n]

// sum of n natural numbers
// sum_n(n) = n + sum_n(n-1)

// factorial
// fact(n) -> returns n!
// define its recurrence relation
// fact(n) = n*fact(n-1)


// void fun(int n) {
// 	if (n == 0) return;
// 	cout << n << " ";
// 	fun(n - 1);
// 	cout << n << " ";
// 	return;
// }

// void fun(int n) {
// 	if (n <= 0) return;
// 	cout << n << " ";
// 	fun(n - 1);
// 	cout << n << " ";
// 	fun(n - 2);
// 	cout << n << " ";
// 	return;
// }

int fun(int n) {
	if (n <= 1) return n;
	int left = fun(n - 1);
	int right = fun(n - 2);
	int ans = left + right;
	return ans;
}

// power of a^b
int pow(int a, int b) {
	if (b == 0) return 1;
	return a * pow(a, b - 1);
}

int mul(int a, int b) {
	if (b == 0) return 0;
	return a + mul(a, b - 1);
}


// fun(1) -- line25
// fun(2) -- line 25
// fun(3) -- line 25
// fun(4) -- line 25
// fun(5) -- line25
// Stack

int numWaysToReachN(int n) {
	if (n == 0) return 1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += numWaysToReachN(i);
	}
	return ans;
}

void makeWaysToReachN(int n, string way, int mx) {
	if (n == 0) {
		cout << way << '\n';
		return;
	}
	for (int i = mx; i <= n; i++) {
		makeWaysToReachN(n - i,  way + "+" + to_string(i),  i);
	}
}

void generateSubsequence(string s, int index, string ans) {
	if (s.size() == index) {
		cout << ans << '\n';
		return;
	}

	// exclude the s[index]
	generateSubsequence(s, index + 1, ans);

	// include s[index]
	generateSubsequence(s, index + 1, ans + s[index]);
}

void generateValidParanthesis(int open, int close, int n,
                              string valid_paranthesis) {
	if (n % 2 == 1) {
		cout << "Not possible for odd lengths\n";
		return;
	}

	if (open + close == n) {
		cout << valid_paranthesis << '\n';
		return;
	}

	// add open bracket
	if (open < n / 2) {
		generateValidParanthesis(open + 1, close, n,
		                         valid_paranthesis + "(");
	}

	// add closing bracket
	if (close < open) {
		generateValidParanthesis(open, close + 1, n,
		                         valid_paranthesis + ")");
	}

	return;
}

bool isPalindrome(int start, int end, string s) {
	// db(start, end);
	// odd length
	if (start == end) {
		return true;
	}
	// even length
	if (start == end - 1) {
		return s[start] == s[end];
	}

	return s[start] == s[end] &&
	       isPalindrome(start + 1, end - 1, s);
}

void makeAllWords(string s, int index, string res) {
	if (index == s.size()) {
		cout << res << '\n';
		return;
	}

	// 1 character case
	char ch = s[index] + '0';
	makeAllWords(s, index + 1, res + ch);

	// try to take two characters
	if (index < s.size() - 1
	        && (s[index] == '1'
	            || s[index] == '2' && s[index + 1] <= '6')) {
		// now we convert s[index] and s[index+1] to words
		int num = (s[index] - '0') * 10 + (s[index + 1] - '0');
		char ch = 'a' + (num - 1);
		makeAllWords(s, index + 2, res + ch);
	}
}

vector<vector<string> > palindromicPartitioning(int start, string s) {

	if (start == s.size()) {
		vector<vector<string> > temp;
		vector<string> v;
		temp.push_back(v);
		return temp;
	}


	cout << start << '\n';

	vector<vector<string> > res;
	for (int end_ = start; end_ < s.size(); end_++) {
		if (isPalindrome(start, end_, s)) {

			vector<vector<string> > future_ans =
			    palindromicPartitioning(end_ + 1, s);

			string palindrome = s.substr(start, end_ - start + 1);

			for (vector<string> v : future_ans) {
				v.insert(v.begin(), palindrome);
				res.push_back(v);
			}

		}
	}
	return res;
}

// palindromic partitioning of s
vector<vector<string> > partition(string s) {
	return palindromicPartitioning(0, s);
}

int minStepsToOne(int n) {
	if (n == 1) return 0;

	int a = minStepsToOne(n - 1);
	int b = INT_MAX, c = INT_MAX;
	if (n % 2 == 0) {
		b = minStepsToOne(n / 2);
	}
	if (n % 3 == 0) {
		c = minStepsToOne(n / 3);
	}
	return min(min(a, b), c) + 1;
}

int byteLandianGoldCoins(int n) {
	if (n <= 1) return n;
	return max(byteLandianGoldCoins(n / 2)
	           + byteLandianGoldCoins(n / 3)
	           + byteLandianGoldCoins(n / 4), n);
}

void TowerOfHanoi(int n, string source,
                  string helper, string destination) {
	if (n == 0) return;
	TowerOfHanoi(n - 1, source, destination, helper);
	cout << source << " --->  " << destination << '\n';
	TowerOfHanoi(n - 1, helper, source, destination);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// cout << fun(3);

	// cout << pow(3, 5) << '\n';
	// cout << mul(3, 5) << '\n';

	// for (int i = 1; i <= 10; i++) {
	// 	cout << i << " " << numWaysToReachN(i) << '\n';
	// }


	// makeWaysToReachN(8, "", 1);
	// string s;
	// cin >> s;

	// generateSubsequence(s, 0, "");

	// generateValidParanthesis(0, 0, 5, "");


	// string s;
	// cin >> s;
	// cout << isPalindrome(0, s.size() - 1, s);

	// string s;
	// cin >> s;
	// makeAllWords(s, 0, "");



	// string s;
	// cin >> s;
	// auto res  = partition(s);

	// for (auto v : res) {
	// 	for (auto s : v) {
	// 		cout << s << " ";
	// 	}
	// 	cout << '\n';
	// }


	// cout << minStepsToOne(10) << '\n';

	// cout << byteLandianGoldCoins(2) << '\n';
	int n;
	cin >> n;
	TowerOfHanoi(n, "A", "B", "C");










}