#include<bits/stdc++.h>
using namespace std;

struct node {
	int val;
	node* left;
	node* right;
	node(int _val) {
		this->val = _val;
		this->left = this->right = NULL;
	}
};

node* constructPreorder() {
	int val;
	cin >> val;
	if (val == -1) return NULL;
	node* root = new node(val);
	root->left = constructPreorder();
	root->right = constructPreorder();
	return root;
}

void preorderTraversal(node* root) {
	if (root == NULL) return;
	cout << root->val << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void inorderTraversal(node* root) {
	if (root == NULL) return;
	preorderTraversal(root->left);
	cout << root->val << " ";
	preorderTraversal(root->right);
}


void postorderTraversal(node* root) {
	if (root == NULL) return;
	preorderTraversal(root->left);
	preorderTraversal(root->right);
	cout << root->val << " ";
}

node* constructLevelOrder() {
	int x;
	cin >> x;
	if (x == -1) return NULL;
	node* root = new node(x);

	queue<node*> Q;
	Q.push(root);

	while (!Q.empty()) {
		node* cur = Q.front();
		Q.pop();

		int x, y;
		cin >> x >> y;

		if (x != -1) {
			cur->left = new node(x);
			Q.push(cur->left);
		}
		if (y != -1) {
			cur->right = new node(y);
			Q.push(cur->right);
		}
	}
	return root;
}

int sizeOfTree(node* root) {
	if (root == NULL) return 0;
	return sizeOfTree(root->left)
	       + sizeOfTree(root->right) + 1;
}

int sumOfAllValues(node* root) {
	if (root == NULL) return 0;
	return sumOfAllValues(root->left)
	       + sumOfAllValues(root->right)
	       + root->val;
}

int heightOfTree(node* root) {
	if (root == NULL) return 0;
	return max(heightOfTree(root->left),
	           heightOfTree(root->right)) + 1;
}

void leftView(node* root) {
	if (root == NULL) return;
	queue<node*> Q;
	Q.push(root);
	Q.push(NULL);
	cout << root->val << " ";
	while (!Q.empty()) {
		node* cur = Q.front();
		Q.pop();
		if (cur == NULL) {
			if (!Q.empty()) {
				cout << Q.front()->val << " ";
				Q.push(NULL);
			}
			continue;
		}
		if (cur->left) {
			Q.push(cur->left);
		}
		if (cur->right) {
			Q.push(cur->right);
		}
	}
}

void rightView(node* root) {
	if (root == NULL) return;
	queue<node*> Q;
	Q.push(root);
	Q.push(NULL);
	cout << root->val << " ";
	while (!Q.empty()) {
		node* cur = Q.front();
		Q.pop();
		if (cur == NULL) {
			if (!Q.empty()) {
				cout << Q.front()->val << " ";
				Q.push(NULL);
			}
			continue;
		}
		if (cur->right) {
			Q.push(cur->right);
		}
		if (cur->left) {
			Q.push(cur->left);
		}
	}
}

void rightViewUsingDeque(node* root) {
	if (root == NULL) return;
	deque<node*> Q;
	Q.push_back(root);
	Q.push_back(NULL);
	cout << root->val << " ";
	while (!Q.empty()) {
		node* cur = Q.front();
		Q.pop_front();
		if (cur == NULL) {
			if (!Q.empty()) {
				cout << Q.back()->val << " ";
				Q.push_back(NULL);
			}
			continue;
		}
		if (cur->left) {
			Q.push_back(cur->left);
		}
		if (cur->right) {
			Q.push_back(cur->right);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// node* root = constructPreorder();

	node* root = constructLevelOrder();

	// preorderTraversal(root);
	// cout << '\n';

	// inorderTraversal(root);
	// cout << '\n';

	// postorderTraversal(root);

	// cout << sizeOfTree(root) << '\n';

	// leftView(root);

	// rightView(root);

	rightViewUsingDeque(root);



}