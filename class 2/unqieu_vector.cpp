#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(2);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.push_back(4);
	a.push_back(4);
	a.push_back(5);

	for (auto x : a) {
		cout << x << " ";
	}
	cout << '\n';

	auto it = unique(a.begin(), a.end());
	a.resize(it - a.begin());

	for (auto x : a) {
		cout << x << " ";
	}
	cout << '\n';

	cout << *it;


	// Array of n element
	// [5,5,3,4,4,3,2,2,2,5,6,6,7]
	// How many distinct values that array has?
	// implement unqiue for an array



}