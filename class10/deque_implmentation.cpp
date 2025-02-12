#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Deque {
private:
	vector<T> arr;
	int n;
	int front, rear, cnt;
public:
	Deque(int n) {
		this->n = n;
		arr.resize(n);
		cnt = 0;
		front = 0;
		rear = -1;
	}
	bool isFull() {
		return cnt == n;
	}
	bool isEmpty() {
		return cnt == 0;
	}
	bool push_back(T val) {
		if (isFull()) return false;
		cnt++;
		rear++;
		if (rear == n) rear = 0;
		arr[rear] = val;
		return true;
	}
	bool pop_back() {
		if (isEmpty()) return false;
		cnt--;
		rear--;
		if (rear == -1) rear = n - 1;
		return true;
	}
	bool push_front(T val) {
		if (isFull()) return false;
		cnt++;
		front--;
		if (front == -1) front = n - 1;
		arr[front] = val;
		return true;
	}
	bool pop_front() {
		if (isEmpty()) return false;
		cnt--;
		front++;
		if (front == n) front = 0;
		return true;
	}
	T front_val() {
		if (isEmpty()) {
			cout << "empty deque\n";
			T temp;
			return temp;
		}
		return arr[front];
	}
	T back_val() {
		if (isEmpty()) {
			cout << "empty deque\n";
			T temp;
			return temp;
		}
		return arr[rear];
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Deque<int> Q(5);


	Q.push_back(3);
	Q.push_back(4);

	Q.push_front(1);
	Q.push_front(2);

	cout << Q.front_val() << '\n';

	cout << Q.back_val() << '\n';

	Q.pop_back();

	Q.pop_front();

	cout << Q.front_val() << '\n';

	cout << Q.back_val() << '\n';












}