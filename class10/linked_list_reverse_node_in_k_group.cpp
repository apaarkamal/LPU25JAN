#include<bits/stdc++.h>
using namespace std;



struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
	ListNode* reverseUsingRecursion(ListNode* cur, ListNode* prev = NULL) {
		if (cur == NULL) return prev;
		ListNode* forward = cur->next;
		cur->next = prev;
		return reverseUsingRecursion(forward, cur);
	}
	int findLengthOfLL(ListNode* head) {
		int cnt = 0;
		ListNode* cur = head;
		while (cur) {
			cur = cur->next;
			cnt++;
		}
		return cnt;
	}
	ListNode* fetchTail(ListNode* head) {
		ListNode* cur = head;
		while (cur->next) {
			cur = cur->next;
		}
		return cur;
	}
	void print(ListNode* head) {
		ListNode* cur = head;
		while (cur) {
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << '\n';
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (findLengthOfLL(head) < k) {
			return head;
		}
		if (head == NULL) return head;

		ListNode* cur = head;
		int kk = k;
		kk--;
		while (kk--) {
			cur = cur->next;
		}
		// tail of ll of length k
		ListNode* forward = cur->next;
		cur->next = NULL;

		ListNode* newHead = reverseKGroup(forward, k);

		// the ll is reversed of length k
		head = reverseUsingRecursion(head);
		ListNode* tail = fetchTail(head);
		tail->next = newHead;

		return head;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



}