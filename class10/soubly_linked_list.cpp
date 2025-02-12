#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
	node(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};

pair<node*, node*> constructDLL() {
	int n;
	cin >> n;
	node* head = NULL;
	node* tail = NULL;
	while (n--) {
		int x;
		cin >> x;
		node* temp = new node(x);
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
	}
	return make_pair(head, tail);
}

void forwardPrintDLL(node* head) {
	node* cur = head;
	while (cur) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << '\n';
}

void reversePrintDLL(node* tail) {
	node* cur = tail;
	while (cur) {
		cout << cur->data << " ";
		cur = cur->prev;
	}
	cout << '\n';
}

node* insertAtHead(node* head, int x) {
	node* newNode = new node(x);
	if (head != NULL) {
		newNode->next = head;
		head->prev = newNode;
	}
	return newNode;
}

node* reversetough(node* head) {
	node* curnode = head;
	node* prevnode = NULL;

	while (curnode) {
		node* forwardNode = curnode->next;
		curnode->prev = forwardNode;
		curnode->next = prevnode;
		prevnode = curnode;
		curnode = forwardNode;
	}

	return prevnode;
}

node* reverseEasy(node* head) {
	node* cur = head;
	node* lastNode = NULL;
	while (cur) {
		lastNode = cur;
		swap(cur->next, cur->prev);
		cur = cur->prev;
	}
	return lastNode;
}

// deleteAtHead

// deleteAtTail

// insertAtKth

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	pair<node*, node*> x = constructDLL();
	node* head = x.first;
	node* tail = x.second;

	forwardPrintDLL(head);

	reversePrintDLL(tail);

	head = reversetough(head);

	forwardPrintDLL(head);

	head = reverseEasy(head);

	forwardPrintDLL(head);



}