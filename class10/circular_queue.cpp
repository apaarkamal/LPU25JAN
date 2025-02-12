#include<bits/stdc++.h>
using namespace std;

const int n = 10;

template <typename T>
class Queue {
	T arr[n];
	int front_pointer = 0, rear_pointer = -1, cnt = 0;
	int size() {
		return cnt;
	}
	bool isFull() {
		return (size() == n);
	}
	bool isEmpty() {
		return (size() == 0);
	}
	void push(T val) {
		if (isFull()) {
			cout << "cannot push, queue full\n";
			return;
		}
		rear_pointer++;
		cnt++;
		if (rear_pointer == n) rear_pointer = 0;
		arr[rear_pointer] = val;
	}
	T front() {
		if (isEmpty()) {
			cout << "empty queue\n";
			T temp;
			return temp;
		}
		return arr[front_pointer];
	}
	T rear() {
		if (isEmpty()) {
			cout << "empty queue\n";
			T temp;
			return temp;
		}
		return arr[rear_pointer];
	}
	void pop() {
		if (isEmpty()) {
			cout << "empty queue\n";
			return;
		}
		cnt--;
		front_pointer++;
		if (front_pointer == n) front_pointer = 0;
		return;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	queue<string> Q;

	Q.push("apaar");
	Q.push("kamal");

	cout << Q.front() << '\n';

	Q.pop();

	cout << Q.front() << '\n';














}