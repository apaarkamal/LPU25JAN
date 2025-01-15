#include<bits/stdc++.h>
using namespace std;

void fun(int* b) {
	*b = *b + 1;
	// *b++;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a = 10;
	int *b = &a;

	fun(b);

	// cout << a;

	// // &a -> address of a
	// int* b = &a;

	// cout << &a << '\n';
	// cout << b << '\n';
	// cout << *b << '\n';




}