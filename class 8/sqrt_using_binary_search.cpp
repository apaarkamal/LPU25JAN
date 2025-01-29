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

double sqrt_using_binary_search(double x) {
	double left = 1, right = x, two = 2;

	while (right - left > 0.00001) {
		double mid = (left + right) / two;
		db(left, right, mid);
		if (mid * mid > x) {
			right = mid;
		}
		else {
			left = mid;
		}
	}

	return (left + right) / two;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	double x;
	cin >> x;

	cout << setprecision(5) << fixed;

	cout << sqrt_using_binary_search(x);

}