#include<bits/stdc++.h>
using namespace std;

const int N = 10;

template<typename T>
class Stack {
private:
	T array[N];
	int cur = 0;
public:
	bool isEmpty() {
		return cur == 0;
	}
	bool isFull() {
		return cur == N;
	}
	void push(T val) {
		if (isFull()) {
			cout << "cannot insert an element, stack full\n";
			return;
		}
		array[cur] = val;
		cur++;
	}
	void pop() {
		if (isEmpty()) {
			cout << "cannot pop, stack empty\n";
			return;
		}
		cur--;
	}
	T top() {
		if (isEmpty()) {
			cout << "cannot top, stack empty\n";
			T temp;
			return temp;
		}
		return array[cur - 1];
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Stack<int> St;

	St.push(10);
	St.push(20);
	St.push(30);

	cout << St.top() << '\n';

	St.push(40);

	cout << St.top() << '\n';

	St.pop();
	St.pop();

	cout << St.top() << '\n';










}